#include "Rasterizer.h"

//draw a lin where abs(m) > 0 and <1

void DrawLineLow(const Vertex& left, const Vertex& right)
{
	int startX = static_cast<int>(left.pos.x);
	int endX = static_cast<int>(right.pos.x);
	float dx = static_cast<float>(endX - startX);

	for (int x = startX; x <= endX; x++)
	{
		float t = static_cast<float>(x - startX) / dx;
		Rasterizer::Get()->DrawPoint(LerpVertex(left, right, t));
	}
}

void DrawLineHeigh(const Vertex& bottom, const Vertex& top)
{
	int startY = static_cast<int>(bottom.pos.y);
	int endY = static_cast<int>(top.pos.y);
	float dy = static_cast<float>(endY - startY);
	for (int y = startY; y <= endY; y++)
	{
		float t = static_cast<float>(y - startY) / dy;
		Rasterizer::Get()->DrawPoint(LerpVertex(bottom, top, t));
	}
}

Rasterizer* Rasterizer::Get()
{
	static Rasterizer sInstance;

	Matrix4 matC = Matrix4::Translation(1.0f, 0.0f, 5.0f);
	Matrix4 final = matC;
	Matrix4 finalInv = MathHelper::Inverse(final);
	Matrix4 indentity = final * finalInv;
	return &sInstance;
}

void Rasterizer::SetFillMode(FillMode fillMode)
{
	mFillMode = fillMode; 
}

void Rasterizer::SetColor(X::Color color)
{
	mColor = color;
}

void Rasterizer::DrawPoint(int x, int y)
{
	X::DrawPixel(x, y, mColor);
}

void Rasterizer::DrawPoint(const Vertex& v)
{
	SetColor(v.color);
	DrawPoint(static_cast<int>(v.pos.x), static_cast<int>(v.pos.y));
}

void Rasterizer::DrawLine(const Vertex& a, const Vertex& b)
{
	bool useHighLine = MathHelper::IsEqual(b.pos.x, a.pos.x);
	if (!useHighLine)
	{
		float dx = b.pos.x - a.pos.x;
		float dy = b.pos.y - a.pos.y;
		float m = dy / dx;
		useHighLine = abs(m) >= 1.0f;
	}
	if(useHighLine)
	{
		if (a.pos.y < b.pos.y)
		{
			DrawLineHeigh(a, b);
		}
		else
		{
			DrawLineHeigh(b, a);
		}
	}
	else
	{
		if (a.pos.x < b.pos.x)
		{
			DrawLineLow(a, b);
		}
		else
		{
			DrawLineLow(b, a);
		}
	}
}

void Rasterizer::DrawTriangle(const Vertex& a, const Vertex& b, const Vertex& c)
{
	switch (mFillMode)
	{
	case FillMode::Wireframe:
	{
		DrawLine(a, b);
		DrawLine(b, c);
		DrawLine(c, a);
	}
	break;
	case FillMode::Solid:
	{
		std::vector<Vertex> sortedVectices = { a,b,c };
		std::stable_sort(sortedVectices.begin(), sortedVectices.end(), [](const Vertex& lhs, const Vertex& rhs)
		{
			return lhs.pos.y < rhs.pos.y;
		});
		DrawFillTriangle(sortedVectices[0], sortedVectices[1], sortedVectices[2]);
	}
	break;
	default:
	break;
	}

}

void Rasterizer::DrawFillTriangle(const Vertex& a, const Vertex& b, const Vertex& c)
{
	if (MathHelper::IsEqual(a.pos.y, c.pos.y))
	{
		DrawLine(a, c);
		return;
	}

	int startY = static_cast<int>(a.pos.y);
	int endY = static_cast<int>(c.pos.y);
	float dy = static_cast<float>(endY - startY);
	if (MathHelper::IsEqual(a.pos.y, b.pos.y))
	{
		for (int y = startY; y <= endY; y++)
		{
			float t = static_cast<float>(y - startY) / dy;
			Vertex v0 = LerpVertex(a, c, t);
			Vertex v1 = LerpVertex(b, c, t);
			DrawLine(v0, v1);
		}
	}
	else if (MathHelper::IsEqual(b.pos.y, c.pos.y))
	{
		for (int y = startY; y <= endY; y++)
		{
			float t = static_cast<float>(y - startY) / dy;
			Vertex v0 = LerpVertex(a, c, t);
			Vertex v1 = LerpVertex(a, b, t);
			DrawLine(v0, v1);
		}
	}
	else
	{
		float t = (b.pos.y - a.pos.y) / dy;
		Vertex splitVertex = LerpVertex(a, c, t);
		DrawFillTriangle(a, b, splitVertex);
		DrawFillTriangle(b, splitVertex, c);
	}
}
