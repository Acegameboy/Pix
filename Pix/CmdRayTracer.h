#pragma once

#include "Command.h"

class CmdBeginRayTracing : public Command
{
public:
	const char* GetName() override
	{
		return "BeginRayTracing";
	}

	const char* GetDescription() override
	{
		return
			"BeginRayTracing() -- begins ray tracing prep and renders image\n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdEndRayTracing : public Command
{
public:
	const char* GetName() override
	{
		return "EndRayTracing";
	}

	const char* GetDescription() override
	{
		return
			"EndRayTracing() -- begins ray tracing prep and renders image\n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdRTSphere : public Command
{
public:
	const char* GetName() override
	{
		return "RTSphere";
	}

	const char* GetDescription() override
	{
		return
			"RTSphere(x, y, z, radius, r, g, b, <ri>)\n"
			"- adds sphere to the ray tracing scene\n"
			"- optional ri (refraction index)";
	}

	bool Execute(const std::vector<std::string>& params) override;
};

class CmdRTLight : public Command
{
public:
	const char* GetName() override
	{
		return "RTLight";
	}

	const char* GetDescription() override
	{
		return
			"RTLight(x, y, z, radius, r, g, b, <ri>)\n"
			"- adds lights to the ray tracing scene\n";
	}

	bool Execute(const std::vector<std::string>& params) override;
};