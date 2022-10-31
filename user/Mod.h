#pragma once

#include "pch.h"
#include "Injector.h"

#include <comdef.h>  //wchar* -> char*

class Mod {
public:
	static std::string Version;
	static bool ConsoleMode;
	static int UniqueObjectId;
	static bool LoadAllTemplates;

	static void Init();
private:
	static void InitConsole();

public:
	static void AppendLocalChatMessage(long long fromClient, std::string username, std::string content);
	static void SendChatMessage(long long fromClient, std::string content);

	static void SendDropItem(long long toClient, int itemId, int objectId, int ammo);
	static void ForceGiveItem(long long toClient, int itemId, int objectId);

	static void RestartGame();
	static void SetCurrentGameModeTime(float time);

	static long long GetMySteamId();
	static long long GetCurrentLobbyOwnerId();
	static bool IsInAnyLobby();
	static bool IsLobbyOwner();

	static void ModBanPlayer(long long clientId);
	static void KickPlayer(long long clientId);
	static void SendWinner(long long clientId, long long money);
	static void SendLocalInteract(int itemid);
	static void SetPlayerReady(long long clientId, bool ready, bool sendInteract = true);
	static void TogglePlayerReady(long long clientId, bool sendInteract = true);
	static void SetAllPlayersReady();
	static void SendReadyInteract();
	static void UseItemAll(long long clientId, int objectId, int itemId, Vector3 pos);
};