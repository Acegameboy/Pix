#include "CmdSetViewPort.h"
#include "Viewport.h"
#include "VariableCache.h"

bool CmdSetViewport::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 4)
	{
		return false;
	}
	
	VariableCache* vc = VariableCache::Get();
	float x = vc->GetFloat(params[0]);
	float y = vc->GetFloat(params[1]);
	float width = vc->GetFloat(params[2]);
	float height = vc->GetFloat(params[3]);

	bool show = (params.size() > 4) && params[4] == "true";
	Viewport::Get()->SetViewport(x, y, width, height);
	Viewport::Get()->ShowViewport(show);
	return true;
}
