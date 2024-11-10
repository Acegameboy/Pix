#include "PrimitivesManager.h"
#include "Rasterizer.h"
#include "Clippers.h"
#include "Camera.h"
#include "MatrixStack.h"

extern float gResolutionX;
extern float gResolutionY;


namespace
{
	Matrix4 GetScreenTransform()
	{
		float hw = gResolutionX * 0.5f;
		float hh = gResolutionY * 0.5f;
		return
		{
			  hw, 0.0f, 0.0f, 0.0f,
			0.0f,   hh, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			  hw,   hh, 0.0f, 1.0f
		};
	}
}

PrimitivesManager* PrimitivesManager::Get()
{
	static PrimitivesManager sInstance;
	return &sInstance;
}

void PrimitivesManager::BeginDraw(Topology topology, bool applyTransform)
{
	mVertexBuffer.clear();
	mTopology = topology;
	mApplyTransform = applyTransform;
	mDrawBegin = true;
}

void PrimitivesManager::AddVertex(const Vertex& vertex)
{
	if (mDrawBegin)
	{
		mVertexBuffer.push_back(vertex);
	}
}

void PrimitivesManager::EndDraw()
{
	if (!mDrawBegin)
	{
		return;
	}

	switch (mTopology)
	{
	case Topology::Point:
		{
		for (size_t i = 0; i < mVertexBuffer.size(); ++i)
			{
			if(!Clipper::Get()->ClipPoint(mVertexBuffer[i]))
			Rasterizer::Get()->DrawPoint(mVertexBuffer[i]);
			}
		}
		break;
	case Topology::Line:
		for (size_t i = 1; i < mVertexBuffer.size(); i += 2)
		{
			if (!Clipper::Get()->ClipLine(mVertexBuffer[i - 1], mVertexBuffer[i]))
			{
				Rasterizer::Get()->DrawLine(mVertexBuffer[i - 1], mVertexBuffer[i]);
			}
		}
		break;
	case Topology::Triangle:
		if (mApplyTransform)
		{
			Matrix4 matWorld = MatrixStack::Get()->GetTransform();
			Matrix4 matView = Camera::Get()->GetViewMatrix();
			Matrix4 matProj = Camera::Get()->GetProjectionMatrix();
			Matrix4 matScreen = GetScreenTransform();
			Matrix4 matFinal = matWorld * matView * matProj * matScreen;
			for (Vertex& v : mVertexBuffer)
			{
				v.pos = MathHelper::TransformCoord(v.pos, matFinal);
				MathHelper::FlattenVectorScreenCoords(v.pos);
			}
		}
		for (size_t i = 2; i < mVertexBuffer.size(); i += 3)
		{
			std::vector<Vertex> triangle = { mVertexBuffer[i - 2], mVertexBuffer[i - 1], mVertexBuffer[i] };
			if (!Clipper::Get()->ClipTriangle(triangle))
			{
				for (size_t t = 2; t < triangle.size(); ++t)
				{
					Rasterizer::Get()->DrawTriangle(triangle[0], triangle[t - 1], triangle[t]);
				}
			}
		}
		break;
	default:
		break;		
	}
	mDrawBegin = false;
}
