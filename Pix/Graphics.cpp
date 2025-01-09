#include "Graphics.h"

#include "Viewport.h"
#include "Clippers.h"
#include "MatrixStack.h"
#include "Camera.h"
#include "PrimitivesManager.h"
#include "DepthBuffer.h"
#include "LightManager.h"
#include "MaterialManager.h"
#include "PostProcessing.h"
#include "RayTracer.h"

void Graphics::NewFrame()
{
	Viewport::Get()->OnNewFrame();
	Clipper::Get()->OnNewFrame();
	MatrixStack::Get()->OnNewFrame();
	Camera::Get()->OnNewFrame();
	PrimitivesManager::Get()->OnNewFrame();
	DepthBuffer::Get()->OnNewFrame();
	LightManager::Get()->OnNewFrame();
	MaterialManager::Get()->OnNewFrame();
	PostProcessing::Get()->OnNewFrame();
	RayTracer::Get()->OnNewFrame();
}