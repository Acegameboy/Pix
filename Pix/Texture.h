#pragma once

#include <XEngine.h>

enum class AddressMode
{
	Border,
	Clamp,
	Mirror,
	Wrap
};

class Texture //It'll only load 24 bit bmps
{
public:
	void Load(const std::string& fileName);
	const std::string& GetFileName() const;
	X::Color GetPixel(float u, float v, AddressMode mode) const;
	X::Color GetPixel(int u, int v) const;
	
	int GetWidth() const;
	int GetHeight() const;

private:
	std::string mFileName;
	std::unique_ptr<X::Color[]> mPixels;
	int mWidth = 0;
	int mHeight = 0;
};