#pragma once

#include "pch.h"
#include "Player.h"


class Server {
public:
	static Player* m_LobbyOwner;
	static std::map<long long, Player*> m_Players;
	static std::chrono::system_clock::time_point m_LastUpdatedTime;
	static int m_UniqueObjectId;
	static float m_BroadCastHelpTime;
	static bool m_LightState;
	static Vector3 m_SpawnPosition;
	static bool m_CanUpdateSpawnPosition;
	static bool m_FirstTimeJoin;

	static std::map<std::string, int> m_WeaponList;

	static void OnPlayerAddedToLobby(long long clientId);
	static void OnPlayerRemovedFromLobby(long long clientId);
	static bool OnPlayerAttemptBanned(long long clientId);

	static void TryAddPlayer(long long clientId, int playerId, PlayerManager* playerManager);
	static bool HasPlayer(long long clientId);
	static Player* AddPlayer(Player* player);
	static Player* GetPlayer(long long clientId);

	static void Init();
	static void Update(float dt);

	static void GiveWeapon(long long toClient, int weaponId);

	static std::vector<Player*> FindPlayers(std::string selector);
};