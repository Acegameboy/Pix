#pragma once

#include "RenderTarget.h"

enum class EffectType
{
	None,
	MonoChrome,
	Invert,
	Mirror,
	Blur,
	ColorMaskR,
	ColorMaskG,
	ColorMaskB,
	Sepia,
	Wave
};

class PostProcessing
{
public:
	static PostProcessing* Get();

	void Initialize(int width, int height, const X::Color& clearColor);
	void OnNewFrame();
	void SetEffectType(EffectType effectType);

	void BeginDraw();
	bool DrawToRenderTarget(int x, int y, const X::Color& color);
	void EndDraw();

private:
	void DrawPixel(int x, int y);

	bool mDrawBegin = false;
	X::Color mClearColor = X::Colors::Black;
	EffectType mEffectType = EffectType::None;
	RenderTarget mRenderTarget;
};
