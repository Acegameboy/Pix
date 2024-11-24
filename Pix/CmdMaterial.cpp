#include "CmdMaterial.h"
#include "MaterialManager.h"
#include "VariableCache.h"

bool CmdSetMaterialAmbient::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 3)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	const float r = vc->GetFloat(params[0]);
	const float g = vc->GetFloat(params[1]);
	const float b = vc->GetFloat(params[2]);
	MaterialManager::Get()->SetMaterialAmbient({ r, g, b, 1.0f });
	return true;
}

bool CmdSetMaterialDiffuse::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 3)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	const float r = vc->GetFloat(params[0]);
	const float g = vc->GetFloat(params[1]);
	const float b = vc->GetFloat(params[2]);
	MaterialManager::Get()->SetMaterialDiffuse({ r, g, b, 1.0f });
	return true;
}

bool CmdSetMaterialSpecular::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 3)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	const float r = vc->GetFloat(params[0]);
	const float g = vc->GetFloat(params[1]);
	const float b = vc->GetFloat(params[2]);
	MaterialManager::Get()->SetMaterialSpecular({ r, g, b, 1.0f });
	return true;
}

bool CmdSetMaterialEmissive::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 3)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	const float r = vc->GetFloat(params[0]);
	const float g = vc->GetFloat(params[1]);
	const float b = vc->GetFloat(params[2]);
	MaterialManager::Get()->SetMaterialEmissive({ r, g, b, 1.0f });
	return true;
}

bool CmdSetMaterialShininess::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	const float shiness = vc->GetFloat(params[0]);
	MaterialManager::Get()->SetMaterialShininess(shiness);
	return true;
}
