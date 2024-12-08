#include "CmdSetAddressMode.h"
#include "TextureCache.h"

bool CmdSetAddressMode::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	AddressMode addressMode = AddressMode::Clamp;
	if (params[0] == "border")
	{
		addressMode = AddressMode::Border;
	}
	else if (params[0] == "clamp")
	{
		addressMode = AddressMode::Clamp;
	}
	else if (params[0] == "mirror")
	{
		addressMode = AddressMode::Mirror;
	}
	else if (params[0] == "wrap")
	{
		addressMode = AddressMode::Wrap;
	}
	else
	{
		return false;
	}

	TextureCache::Get()->SetAddressMode(addressMode);
	return true;
}
