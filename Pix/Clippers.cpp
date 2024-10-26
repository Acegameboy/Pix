#include "Clippers.h"
#include "Viewport.h"

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
	return false;
}

bool Clipper::ClipLine(Vertex& a, Vertex& b)
{
	return false;
}

bool Clipper::ClipTriangle(std::vector<Vertex>& vertices)
{
	return false;
}

bool Clipper::IsClipping() const
{
	return mIsClipping;
}

void Clipper::SetClipping(bool clip)
{
	mIsClipping = clip;
}
