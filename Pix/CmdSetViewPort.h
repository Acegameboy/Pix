#pragma once

#include "Command.h"

class CmdSetViewPort : public Command
{
public:
	const char* GetName() override
	{
		return "SetViewPort";
	}

	const char* GetDescription() override
	{
		return
			"SetViewPort(x, y, width, height, <show>)\n"
			"\n"
			"- Sets the size of a viewport to display within.\n"
			"- Optional: Show(true or false) if viewport should be displayed.\n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};
