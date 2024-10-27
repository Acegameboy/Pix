#include "Clippers.h"
#include "Viewport.h"

const short BIT_INSIDE = 0; // 0000 0000
const short BIT_LEFT = 1 << 1; // 0000 0001
const short BIT_RIGHT = 1 << 2; //0000 0010
const short BIT_BOTTOM = 1 << 3; //0000 0100
const short BIT_TOP = 1 << 4; //0000 1000

enum ClipEdge : short
{
	Left,
    Top,
	Right,
	Bottom,
	Count
};

short GetOutputCode(float x, float y)
{
	Viewport* vp = Viewport::Get();

	short code = BIT_INSIDE;
	if (x < vp->GetMinX())
	{
		code |= BIT_LEFT;
	}
	else if (x > vp->GetMaxX())
	{
		code |= BIT_RIGHT;
	}
	if (y < vp->GetMinY())
	{
		code |= BIT_TOP;
	}
	else if (y > vp->GetMaxY())
	{
		code |= BIT_BOTTOM;
	}
	
	return code;
}

bool IsInFront(ClipEdge edge, const Vector3& pos)
{
	switch (edge)
	{
	case ClipEdge::Left: return pos.x >= Viewport::Get()->GetMinX();
	case ClipEdge::Top: return pos.y >= Viewport::Get()->GetMinY();
	case ClipEdge::Right: return pos.x <= Viewport::Get()->GetMaxX();
	case ClipEdge::Bottom: return pos.y <= Viewport::Get()->GetMaxY();
	}
}

Vertex ComputeIntersection(ClipEdge edge, const Vertex& v0, const Vertex& v1)
{
	Viewport* vp = Viewport::Get();

	float t = 0.0f;
	switch (edge)
	{
	case ClipEdge::Left: t = (vp->GetMinX() - v0.pos.x) / (v1.pos.x - v0.pos.x); break;
	case ClipEdge::Top: t = (vp->GetMinY() - v0.pos.y) / (v1.pos.y - v0.pos.y); break;
	case ClipEdge::Right: t = (vp->GetMaxX() - v0.pos.x) / (v1.pos.x - v0.pos.x); break;
	case ClipEdge::Bottom: t = (vp->GetMaxY() - v0.pos.y) / (v1.pos.y - v0.pos.y); break;
	default:
		break;
	}
	return LerpVertex(v0, v1, t);
}

Clipper::Clipper()
{
}

Clipper* Clipper::Get()
{
	static Clipper sInstance;
	return &sInstance;
}

void Clipper::OnNewFrame()
{
	mIsClipping = false;
}



bool Clipper::ClipPoint(const Vertex& v)
{
	if (!mIsClipping)
	{
		return false;
	}
	
	Viewport* vp = Viewport::Get();
	float minX = vp->GetMinX();
	float maxX = vp->GetMaxX();
	float minY = vp->GetMinY();
	float maxY = vp->GetMaxY();

	return v.pos.x < minX || v.pos.x > maxX
		|| v.pos.y < minY || v.pos.y > maxY;

}

bool Clipper::ClipLine(Vertex& a, Vertex& b)
{
	if (!mIsClipping)
	{
		return false;
	}
	Viewport* vp = Viewport::Get();
	float minX = vp->GetMinX();
	float maxX = vp->GetMaxX();
	float minY = vp->GetMinY();
	float maxY = vp->GetMaxY();

	short codeA = GetOutputCode(a.pos.x, a.pos.y);
	short codeB = GetOutputCode(b.pos.x, b.pos.y);
	bool cullLine = true;
	while (true)
	{
		if (!(codeA | codeB))
		{
			//both are in the viewport, so draw
			cullLine = false;
			break;
		}
		else if (codeA & codeB)
		{
			cullLine = true;
			break;
		}

		float t = 0.0f;
		short outcode = codeB > codeA ? codeB : codeA;

		if (outcode & BIT_TOP)
		{
			t = (minY - a.pos.y) / (b.pos.y - a.pos.y);
		}
		else if (outcode & BIT_BOTTOM)
		{
			t = (maxY - a.pos.y) / (b.pos.y - a.pos.y);
		}
		else if (outcode & BIT_LEFT)
		{
			t = (minX - a.pos.x) / (b.pos.x - a.pos.x);
		}
		else if (outcode & BIT_RIGHT)
		{
			t = (maxX - a.pos.x) / (b.pos.x - a.pos.x);
		}

		if (outcode == codeA)
		{
			a = LerpVertex(a, b, t);
			codeA = GetOutputCode(a.pos.x, a.pos.y);
		}
		else
		{
			b = LerpVertex(a, b, t);
			codeB = GetOutputCode(b.pos.x, b.pos.y);
		}

	}

	return cullLine;
}

bool Clipper::ClipTriangle(std::vector<Vertex>& vertices)
{
	if (!mIsClipping)
	{
		return false;
	}
	std::vector<Vertex> newVertices;
	for (short edgeIndex = 0; edgeIndex < (short)ClipEdge::Count; ++edgeIndex)
	{
		newVertices.clear();
		ClipEdge edge = (ClipEdge)edgeIndex;
		for (size_t v = 0; v < vertices.size(); ++v)
		{
			size_t vp1 = (v + 1) % vertices.size();
			const Vertex& vP0= vertices[v];
			const Vertex& vP1 = vertices[vp1];

			const bool p0IsInFront = IsInFront(edge, vP0.pos);
			const bool p1IsInFront = IsInFront(edge, vP1.pos);

			//are both in front
			if (p0IsInFront && p1IsInFront)
			{
				newVertices.push_back(vP1);
			}
			//are both behind
			else if (!p0IsInFront && !p1IsInFront)
			{
				//do nothing
			}
			//is p0 in front and p1 behind
			else if (p0IsInFront && !p1IsInFront)
			{
				newVertices.push_back(ComputeIntersection(edge, vP0, vP1));
			}
			//is p0 behind and p1 in front
			else if (!p0IsInFront && p1IsInFront)
			{
				newVertices.push_back(ComputeIntersection(edge, vP0, vP1));
				newVertices.push_back(vP1);
			}
		}
		vertices = newVertices;
	}
	return newVertices.empty();
}

bool Clipper::IsClipping() const
{
	return mIsClipping;
}

void Clipper::SetClipping(bool clip)
{
	mIsClipping = clip;
}
