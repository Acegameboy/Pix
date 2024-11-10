#pragma once
#include "Vertex.h"

using namespace std;

enum class Topology
{
	Point,
	Line,
	Triangle
};

class PrimitivesManager
{
public:
	static PrimitivesManager* Get();

	void BeginDraw(Topology topology, bool applyTransform);
	void AddVertex(const Vertex& vertex);
	void EndDraw();
	
private:
	vector<Vertex> mVertexBuffer;
	Topology mTopology = Topology::Triangle;

	bool mDrawBegin = false;
	bool mApplyTransform = false;
};