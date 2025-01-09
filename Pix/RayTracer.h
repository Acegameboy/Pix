#pragma once

#include <XEngine.h>
#include "MathHelper.h"

class RayTracer
{
public:
	static RayTracer* Get();

	void OnNewFrame();

	bool BeginDraw();
	void AddObject(const Sphere& sphere, const X::Color& color, float ri);
	void AddLight(const Vector3& position, const X::Color& color);
	bool EndDraw();

private:
	X::Color Trace(const Ray& ray, int depth);

	struct Object
	{
		Sphere sphere;
		X::Color color;
		float reflectionIndex = 0.0f;

		bool IsOpaque() const
		{
			return MathHelper::IsEqual(reflectionIndex, 0.0f);
		}
	};

	struct Light
	{
		Vector3 position;
		X::Color color;
		float attenC = 1.0f;
		float attenL = 0.0f;
		float attenQ = 0.001f;
	};

	std::vector<Object> mObject;
	std::vector<Light> mLight;
	float mAmbient = 0.0f;
};
