#pragma once

#include "pch.h"

#include "Player.h"

class Server {
public:
	static std::string m_Version;
	static Player* m_LobbyOwner;
	static std::map<long long, Player*> m_Players;
	static std::chrono::system_clock::time_point m_LastUpdatedTime;
	static int m_UniqueObjectId;
	static float m_BroadCastHelpTime;
	static bool m_LightState;
	static Vector3 m_SpawnPosition;
	static bool m_CanUpdateSpawnPosition;
	static bool m_ShowHelpMessage;
	static bool m_ShowPlayerIds;
	static long long m_LobbyId;
	static long long m_LastLobbyId;
	static bool m_HasCheckedForUpdate;

	static bool m_AutoStartEnabled;
	static int m_AutoStartTime;
	static float m_TimeUntilAutoStart;

	static bool m_IsAtLobby;

	static std::map<std::string, int> m_WeaponList;
	static std::vector<int> m_DisabledWeapons;

	static void OnPlayerAddedToLobby(long long clientId);
	static void OnPlayerRemovedFromLobby(long long clientId);
	static bool OnPlayerAttemptBanned(long long clientId);

	static void TryAddPlayer(long long clientId, int playerId, u10A5u109Au109Eu109Eu1099u10A8u10A8u109Au109Du109Fu109C* playerManager);
	static bool HasPlayer(long long clientId);
	static Player* AddPlayer(Player* player);
	static Player* GetPlayer(long long clientId);

	static void Init();
	static void Update(float dt);

	static void GiveWeapon(long long toClient, int weaponId);

	static std::vector<Player*> FindPlayers(std::string selector);

	static bool IsWeaponDisabled(int weaponId);
	static void DisableWeapon(int weaponId);
	static void EnableWeapon(int weaponId);
};