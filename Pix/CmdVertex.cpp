#include "CmdVertex.h"
#include "PrimitivesManager.h"
#include "VariableCache.h"

bool CmdVertex::Execute(const std::vector<std::string>& params)
{
	VariableCache* vc = VariableCache::Get();
	Vertex v;
	v.color.a = 1.0f;

	if (params.size() == 2) //x,y
	{
		v.pos.x = vc->GetFloat(params[0]);
		v.pos.y = vc->GetFloat(params[1]);
	}
	else if (params.size() == 3)
	{
		v.pos.x = vc->GetFloat(params[0]);
		v.pos.y = vc->GetFloat(params[1]);
		v.pos.z = vc->GetFloat(params[2]);
	}
	else if (params.size() == 5)
	{
		v.pos.x = vc->GetFloat(params[0]);
		v.pos.y = vc->GetFloat(params[1]);
		v.color.r = vc->GetFloat(params[2]);
		v.color.g = vc->GetFloat(params[3]);
		v.color.b = vc->GetFloat(params[4]);
	}
	else if (params.size() == 6)
	{
		v.pos.x = vc->GetFloat(params[0]);
		v.pos.y = vc->GetFloat(params[1]);
		v.pos.z = vc->GetFloat(params[2]);
		v.color.r = vc->GetFloat(params[3]);
		v.color.g = vc->GetFloat(params[4]);
		v.color.b = vc->GetFloat(params[5]);
	}
	else
	{
		return false;
	}
	
	PrimitivesManager::Get()->AddVertex(v);
	return true;
}
