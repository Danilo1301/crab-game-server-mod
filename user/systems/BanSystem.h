#pragma once

#include "pch.h"

struct BanInfo
{
	std::string reason;
	time_t unbanTime;
	//long long bySteamId;
};

class BanSystem {
public:
	static std::map<long long, BanInfo> BannedPlayers;

	static void Update(float dt);
	static void BanPlayer(long long steamId, std::string reason, int seconds);
	static bool IsPlayerBanned(long long steamId);
	static void UnbanPlayer(long long steamId);
	static double GetUnbanTime(long long steamId); //in seconds
};