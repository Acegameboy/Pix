#include "CmdSetUseFilter.h"
#include "VariableCache.h"
#include "TextureCache.h"

bool CmdSetUseFilter::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	TextureCache::Get()->SetUseFilter(vc->GetBool(params[0]));
	return true;
}
