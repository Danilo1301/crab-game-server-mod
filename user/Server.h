#pragma once

#include "pch.h"

#include "Player.h"

using namespace app;

struct Weapon {
	std::string name;
	int id;
	bool enabled = true;
};

class Server {
public:
	static std::map<long long, Player*> m_Players;
	static long long m_LobbyId;
	static bool m_HasCheckedUpdates;
	static Player* m_LobbyOwner;
	static int m_UniqueObjectId;

	static std::vector<Weapon> m_Weapons;

	static int m_PunchDamageId;
	static bool m_CanUseItem;

	static bool m_IsAtLobby;
	static bool m_RedLightState;

	static bool m_AutoStartEnabled;
	static int m_AutoStartTime;
	static float m_TimeUntilAutoStart;

	static bool m_UpdateRequired;

	static void Init();
	static void Update(float dt); //dt ~ 0.016
	static void LoadConfig();
	static void SaveConfig();

	static void UpdatePlayersPosition();
	static bool ProcessUpdateCheck();

	static bool HasPlayer(long long clientId);
	static Player* AddPlayer(Player* player);
	static void RemovePlayer(Player* player);
	static Player* GetPlayer(long long clientId);
	static void TryAddPlayer(long long clientId, int playerId, PlayerManager* playerManager);
	static void RemoveAllPlayers();

	static void OnCreateLobby();

	static void OnPlayerJoin(Player* player);
	static void OnPlayerLeave(Player* player);
	static bool OnPlayerDied(long long deadClient, long long damageDoerId, Vector3 damageDir);

	static void GiveWeapon(long long toClient, int weaponId);
	static Weapon* GetWeaponById(int weaponId);

	static std::vector<Player*> FindPlayers(std::string selector);
};