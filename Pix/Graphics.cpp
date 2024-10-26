#include "Graphics.h"

#include "Viewport.h"
#include "Clippers.h"

void Graphics::NewFrame()
{
	Viewport::Get()->OnNewFrame();
	Clipper::Get()->OnNewFrame();
}