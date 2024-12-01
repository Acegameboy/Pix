#pragma once

#include "Command.h"

class CmdSetShadeMode : public Command
{
public:
	const char* GetName() override
	{
		return "SetShadeMode";
	}

	const char* GetDescription() override
	{
		return
			"SetShadeMode(shademode)\n"
			"\n"
			"- Sets the Shade mode of the rendering(<flat>, <grourrad>, <phong>)\n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};
