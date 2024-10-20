#pragma once

#include <XEngine.h>
#include "Vertex.h"

enum class FillMode
{
	Soild,
	Wireframe

};

class Rasterizer
{
public:
	static Rasterizer* Get();

public:
	void SetFillMode(FillMode fillmMode);

	void SetColor(X::Color color);

	void DrawPoint(int x, int y);

	void DrawPoint(const Vertex& v);
	void DrawLine(const Vertex& a, const Vertex& b);
	void DrawTriangle(const Vertex& a, const Vertex& b, const Vertex& c);

private:
	void DrawFillTriangle(const Vertex& a, const Vertex& b, const Vertex& c);

	X::Color mColor = X::Colors::White;
	FillMode mFillMode = FillMode::Wireframe;
};