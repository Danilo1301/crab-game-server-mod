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
		auto banInfo = pair.second;

		if (banInfo.unbanTime == -1) continue;

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

void BanSystem::BanPlayer(long long steamId, std::string reason, int seconds)
{
	std::cout << "[BanSystem] BanPlayer " << steamId << " for " << seconds << " seconds, reason: (" << reason << ")" << std::endl;

	time_t now;
	time(&now);

	int addTime = seconds;
	time_t unbanTime = now + addTime;

	if (seconds == -1) unbanTime = -1;

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
	auto unbanTime = BannedPlayers[steamId].unbanTime;

	if (unbanTime == -1)
	{
		return -1;
	}

	time_t now;
	time(&now);

	return difftime(unbanTime, now);
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


