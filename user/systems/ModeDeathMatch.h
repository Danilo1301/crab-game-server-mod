#pragma once

#include "pch.h"
#include "Player.h"

class ModeDeathMatch {
public:
	static bool Enabled;
	static int WeaponID;

	static void Update(float dt);
	static void OnPlayerSpawn(Player* player, Vector3 position);
	static void OnPlayerJoin(Player* player);
	static void OnPlayerDied(Player* deadPlayer, Player* killerPlayer, Vector3 damageDir);
};