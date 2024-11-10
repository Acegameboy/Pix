#include "MatrixStack.h"
#include "MathHelper.h"

MatrixStack* MatrixStack::Get()
{
	static MatrixStack sInstance;
	return &sInstance;
}

void MatrixStack::OnNewFrame()
{
	mCombinedTransform = Matrix4::Identity();
	mMatrices.clear();
}

void MatrixStack::PushTranslation(const Vector3& d)
{
	Matrix4 translationMatrix = Matrix4::Translation(d);
	mMatrices.push_back(translationMatrix);
	mCombinedTransform = translationMatrix * mCombinedTransform;
}

void MatrixStack::PushRotationalX(float radians)
{
	Matrix4 rotationalMatrix = Matrix4::RotationalX(radians);
	mMatrices.push_back(rotationalMatrix);
	mCombinedTransform = rotationalMatrix * mCombinedTransform;
}

void MatrixStack::PushRotationalY(float radians)
{
	Matrix4 rotationalMatrix = Matrix4::RotationalY(radians);
	mMatrices.push_back(rotationalMatrix);
	mCombinedTransform = rotationalMatrix * mCombinedTransform;
}

void MatrixStack::PushRotationalZ(float radians)
{
	Matrix4 rotationalMatrix = Matrix4::RotationalZ(radians);
	mMatrices.push_back(rotationalMatrix);
	mCombinedTransform = rotationalMatrix * mCombinedTransform;
}

void MatrixStack::PushScaling(const Vector3& s)
{
	Matrix4 scalingMatrix = Matrix4::Scaling(s);
	mMatrices.push_back(scalingMatrix);
	mCombinedTransform = scalingMatrix * mCombinedTransform;
}

void MatrixStack::PopMatrix()
{
	if (!mMatrices.empty())
	{
		Matrix4 matrix = mMatrices.back();
		mMatrices.pop_back();
		mCombinedTransform = MathHelper::Inverse(matrix) * mCombinedTransform;
	}
}

const Matrix4& MatrixStack::GetTransform() const
{

	return mCombinedTransform;
}

