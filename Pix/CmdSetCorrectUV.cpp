#include "CmdSetCorrectUV.h"
#include "PrimitivesManager.h"
#include "VariableCache.h"

bool CmdSetCorrectUV::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	bool enable = VariableCache::Get()->GetBool(params[0]);
	PrimitivesManager::Get()->SetCorrectUV(enable);
	return true;
}
