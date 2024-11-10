#pragma once

#include "Command.h"

class CmdSetCameraPosition : public Command
{
public:
	const char* GetName() override
	{
		return "SetCameraPosition";
	}
	const char* GetDescription() override
	{
		return "SetCameraPosition(x, y, z)\n"
			"\n"
			"- sets camera position(x, y, z)";
	}
	bool Execute(const std::vector<std::string>& params) override;
};
class CmdSetCameraDirection : public Command
{
public:
	const char* GetName() override
	{
		return "SetCameraDirection";
	}
	const char* GetDescription() override
	{
		return "SetCameraDirection(x, y, z)\n"
			"\n"
			"- sets camera Direction(x, y, z)";
	}
	bool Execute(const std::vector<std::string>& params) override;
};
class CmdSetCameraNear : public Command
{
public:
	const char* GetName() override
	{
		return "SetCameraNear";
	}
	const char* GetDescription() override
	{
		return "SetCameraNear(value)\n"
			"\n"
			"- sets camera near value";
	}
	bool Execute(const std::vector<std::string>& params) override;
};
class CmdSetCameraFar : public Command
{
public:
	const char* GetName() override
	{
		return "SetCameraFar";
	}
	const char* GetDescription() override
	{
		return "SetCameraFar(value)\n"
			"\n"
			"- sets camera far value";
	}
	bool Execute(const std::vector<std::string>& params) override;
};
class CmdSetCameraFov : public Command
{
public:
	const char* GetName() override
	{
		return "SetCameraFov";
	}
	const char* GetDescription() override
	{
		return "SetCameraFov(value)\n"
			"\n"
			"- sets camera fov value";
	}
	bool Execute(const std::vector<std::string>& params) override;
};

