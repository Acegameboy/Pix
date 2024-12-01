#include "ModelCache.h"
#include "CmdModel.h"
#include "PrimitivesManager.h"

bool CmdModel::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	const Model* model = ModelCache::Get()->GetModel(params[0]);
	PrimitivesManager* pm = PrimitivesManager::Get();
	for (int i = 0; i < model->GetVertexCount(); ++i)
	{
		pm->AddVertex(model->GetVertex(i));
	}
	return true;
}
