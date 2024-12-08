#pragma once

#include "Command.h"

class CmdSetAddressMode : public Command
{
public:
	const char* GetName() override
	{
		return "SetAddressMode";
	}

	const char* GetDescription() override
	{
		return
			"SetAddressMode(addressMode)\n"
			"\n"
			"- Sets the texture address mode <border>, <clamp>, <mirror>, <wrap>\n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};
