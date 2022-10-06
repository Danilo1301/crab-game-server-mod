#include "pch-il2cpp.h"
#include "BanSystem.h"

#include "Mod.h"
#include "Server.h"
#include "Config.h"

std::map<long long, BanInfo> BanSystem::BannedPlayers;

void BanSystem::Update(float dt)
{
	std::vector<long long> toUnban;

	for (auto pair : BannedPlayers)
	{
		auto steamId = pair.first;
		//auto banInfo = pair.second;

		auto diff = GetUnbanTime(steamId);

		if (diff <= 0)
		{
			toUnban.push_back(steamId);
		}
	}

	for (auto u : toUnban)
	{
		UnbanPlayer(u);
	}
}

void BanSystem::BanPlayer(long long steamId, std::string reason, float hours)
{
	std::cout << "[BanSystem] BanPlayer " << steamId << " for " << hours << " hours, reason: (" << reason << ")" << std::endl;

	time_t now;
	time(&now);

	int addTime = (int)std::round(hours * 60.0f * 60.0f);
	time_t unbanTime = now + addTime;

	BanInfo banInfo = { reason, unbanTime };
	BannedPlayers[steamId] = banInfo;

	if (Server::HasPlayer(steamId))
	{
		if (Server::GetPlayer(steamId)->IsOnline)
		{
			Mod::ModBanPlayer(steamId);
		}
	}

	Config::SavePlayers();
}

bool BanSystem::IsPlayerBanned(long long steamId)
{
	return BannedPlayers.find(steamId) != BannedPlayers.end();
}

void BanSystem::UnbanPlayer(long long steamId)
{
	if (!IsPlayerBanned(steamId)) return;

	auto banInfo = BannedPlayers[steamId];
	std::cout << "[BanSystem] UnbanPlayer " << steamId << " was unbanned (banned for: " << banInfo.reason << ")" << std::endl;

	BannedPlayers.erase(steamId);

	Config::SavePlayers();
}

double BanSystem::GetUnbanTime(long long steamId)
{
	time_t now;
	time(&now);

	return difftime(BannedPlayers[steamId].unbanTime, now);
}

/*
void BanSystem::SaveData()
{
	std::cout << "[BanSystem] SaveData" << std::endl;
}

void BanSystem::LoadData()
{
	std::cout << "[BanSystem] LoadData" << std::endl;
}

*/


