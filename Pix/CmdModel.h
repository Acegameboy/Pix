#pragma once

#include "Command.h"

class CmdModel : public Command
{
public:
public:
	const char* GetName() override
	{
		return "Model";
	}

	const char* GetDescription() override
	{
		return
			"Model(fileName)\n"
			"\n"
			"- Adds a model to the primitives manager\n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};
