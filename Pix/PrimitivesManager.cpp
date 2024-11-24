#include "PrimitivesManager.h"
#include "Rasterizer.h"
#include "Clippers.h"
#include "Camera.h"
#include "MatrixStack.h"
#include "LightManager.h"

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
	Vector3 CreateFacingNormal(const Vector3& a, const Vector3& b, const Vector3& c)
	{
		Vector3 dirAB = b - a;
		Vector3 dirAC = c - a;
		Vector3 faceNormal = MathHelper::Cross(dirAB, dirAC);
		return MathHelper::Normalize(faceNormal);
	}

	bool CullTriangle(CullMode mode, const std::vector<Vertex>& triangleInNDC)
	{
		if (mode == CullMode::None)
		{
			return false;
		}
		Vector3 faceNormal = CreateFacingNormal(triangleInNDC[0].pos, triangleInNDC[1].pos, triangleInNDC[2].pos);
		if (mode == CullMode::Back)
		{
			return faceNormal.z > 0.0f;
		}
		if (mode == CullMode::Front)
		{
			return faceNormal.z <  0.0f;
		}

		return false;
	}
}

PrimitivesManager* PrimitivesManager::Get()
{
	static PrimitivesManager sInstance;
	return &sInstance;
}

void PrimitivesManager::OnNewFrame()
{
	mCullMode = CullMode::None;
}

void PrimitivesManager::SetCullMode(CullMode mode)
{
	mCullMode = mode;
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
	{
		LightManager* lm = LightManager::Get();
		Matrix4 matWorld = MatrixStack::Get()->GetTransform();
		Matrix4 matView = Camera::Get()->GetViewMatrix();
		Matrix4 matProj = Camera::Get()->GetProjectionMatrix();
		Matrix4 matScreen = GetScreenTransform();
		Matrix4 matToNDC = matView * matProj;

		for (size_t i = 2; i < mVertexBuffer.size(); i += 3)
		{
			std::vector<Vertex> triangle = { mVertexBuffer[i - 2], mVertexBuffer[i - 1], mVertexBuffer[i] };
			if (mApplyTransform)
			{
				//Move all position to world space
				for (size_t i = 0; i < triangle.size(); i++)
				{
					triangle[i].pos = MathHelper::TransformCoord(triangle[i].pos, matWorld);
				}

				Vector3 faceNormal = CreateFacingNormal(triangle[0].pos, triangle[1].pos, triangle[2].pos);

				for (size_t i = 0; i < triangle.size(); i++)
				{
					triangle[i].color *= lm->ComputeLightColor(triangle[i].pos, faceNormal);
				}

				//Move all position to NDC space
				for (size_t i = 0; i < triangle.size(); i++)
				{
					triangle[i].pos = MathHelper::TransformCoord(triangle[i].pos, matToNDC);
				}
				//Test to see if we cull the triangle
				if (CullTriangle(mCullMode, triangle))
				{
					continue;
				}
				//Move all position into Screen Space
				for (size_t i = 0; i < triangle.size(); i++)
				{
					triangle[i].pos = MathHelper::TransformCoord(triangle[i].pos, matScreen);
					MathHelper::FlattenVectorScreenCoords(triangle[i].pos);
				}
			}
			if (!Clipper::Get()->ClipTriangle(triangle))
			{
				for (size_t t = 2; t < triangle.size(); ++t)
				{
					Rasterizer::Get()->DrawTriangle(triangle[0], triangle[t - 1], triangle[t]);
				}
			}
		}
	}
		break;
	default:
		break;		
	}
	mDrawBegin = false;
}
