#pragma once

#include "pch.h"
#include "Injector.h"

class Mod {
public:
	static bool m_DebugMode;
	static std::string m_Version;
	static bool m_IsConsole;

	static void Init();
	static void InitConsole();

	//static long long GetLobbyOwnerId();
	static long long GetMySteamId();

	static void SendChatMessage(long long fromClient, std::string message);
	static void AppendLocalChatMessage(long long fromClient, std::string username, std::string message);

	static void SendDropItem(long long toClient, int objectId, int itemId, int ammo);
	static void ForceGiveItem(long long toClient, int objectId, int itemId);

	static void KillPlayer(long long clientId);
	static void BanPlayer(long long clientId);
	static void KickPlayer(long long clientId);
	static void RespawnPlayer(long long clientId, Vector3 position);
	static void SetPlayerPosition(long long clientId, Vector3 position);

	static void RestartGame();
	static void SetCurrentGameModeTime(float time);
	static void SendWinner(long long clientId, long long money);

	static void SendLocalInteract(int itemid);

	static void SetAllPlayersReady();

	static void UseItemAll(long long clientId, int objectId, int itemId, Vector3 pos);
};