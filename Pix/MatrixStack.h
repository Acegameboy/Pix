#pragma once
#include "Vector3.h"
#include "Matrix4.h"
#include <vector>


class MatrixStack
{
public:
	static MatrixStack* Get();

	void OnNewFrame();

	void PushTranslation(const Vector3& d);
	void PushRotationalX(float radians);
	void PushRotationalY(float radians);
	void PushRotationalZ(float radians);
	void PushScaling(const Vector3& s);

	void PopMatrix();
	const Matrix4& GetTransform() const;

private:
	std::vector<Matrix4> mMatrices;
	Matrix4 mCombinedTransform;
};
