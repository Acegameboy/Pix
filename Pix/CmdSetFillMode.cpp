#include "CmdSetFillMode.h"
#include "Rasterizer.h"

bool CmdSetFillMode::Execute(const std::vector<std::string>& params)
{
    // Check for a single parameter
    if (params.size() != 1)
        return false;

    if (params[0] == "Solid")
    {
        Rasterizer::Get()->SetFillMode(FillMode::Solid);
    }
    else if (params[0] == "Wireframe")
    {
        Rasterizer::Get()->SetFillMode(FillMode::Wireframe);
    }
    else
    {
        return false; // Invalid parameter
    }
    return true;
}