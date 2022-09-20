#pragma once

#include "pch.h"
#include "Injector.h"
#include "Player.h"

class Mod {
public:
	static bool m_DebugMode;
	static std::string m_Version;
	static bool m_ConsoleMode;

	static void Init();

	static void AppendLocalChatMessage(long long fromClient, std::string username, std::string content);
	static void SendChatMessage(long long fromClient, std::string content);

	static void SendDropItem(long long toClient, int itemId, int objectId, int ammo);
	static void ForceGiveItem(long long toClient, int itemId, int objectId);

	static void SetCurrentGameModeTime(float time);

	static void RespawnSpectator(Player* player);
};