#include "Rasterizer.h"
#include "CmdSetShadeMode.h"

bool CmdSetShadeMode::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	ShadeMode shadeMode = ShadeMode::Gourrad;
	if (params[0] == "flat")
	{
		shadeMode = ShadeMode::Flat;
	}
	else if (params[0] == "gourrad")
	{
		shadeMode = ShadeMode::Gourrad;
	}
	else if (params[0] == "phong")
	{
		shadeMode = ShadeMode::Phong;
	}
	else
	{
		return false;
	}
	Rasterizer::Get()->SetShadeMode(shadeMode);
	return true;
}
