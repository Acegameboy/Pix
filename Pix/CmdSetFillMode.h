#pragma once

#include "Command.h"

class CmdSetFillMode : public Command
{
public:
	const char* GetName() override
	{
		return "SetFillMode";
	}

	const char* GetDescription() override
	{
		return
			"SetFillMode(mode)\n\n"
			"Sets the fill mode for drawing triangles. 'mode' can be 'Solid' or 'Wireframe'.";
	}

	bool Execute(const std::vector<std::string>& params) override;
};
