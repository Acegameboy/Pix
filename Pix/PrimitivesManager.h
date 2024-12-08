#pragma once
#include "Vertex.h"

using namespace std;

enum class Topology
{
	Point,
	Line,
	Triangle
};

enum class CullMode
{
	None, 
	Back,
	Front
};

class PrimitivesManager
{
public:
	static PrimitivesManager* Get();

	void OnNewFrame();
	void SetCullMode(CullMode mode);
	void SetCorrectUV(bool correctUV);

	void BeginDraw(Topology topology, bool applyTransform);
	void AddVertex(const Vertex& vertex);
	void EndDraw();
	
private:
	vector<Vertex> mVertexBuffer;
	Topology mTopology = Topology::Triangle;
	CullMode mCullMode = CullMode::None;

	bool mDrawBegin = false;
	bool mApplyTransform = false;
	bool mCorrectUV = false;
};