#pragma once

#include "Command.h"

class CmdSetUseFilter : public Command
{
public:
	const char* GetName() override
	{
		return "SetUseFilter";
	}

	const char* GetDescription() override
	{
		return
			"SetUseFilter(<use>)\n"
			"\n"
			"- Enables/Disables using bilinear filtering on textures.\n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

