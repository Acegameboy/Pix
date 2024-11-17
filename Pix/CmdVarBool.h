#pragma once

#include "Command.h"

class CmdVarBool : public Command
{
public:
	const char* GetName() override
	{
		return "bool";
	}

	const char* GetDescription() override
	{
		return
			"Declares a bool variable. Can optionally specify a drag speed, min, and max.\n"
			"\n"
			"syntax: bool $<name> = <value>, <speed>, <min>, <max>\n"
			"\n"
			"e.g.\n"
			"  bool $angle = 3.14\n"
			"  bool $color = 0.47, 0.01, 0, 1\n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};
