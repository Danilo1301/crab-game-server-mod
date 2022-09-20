#include "pch-il2cpp.h"
#include "ModeDeathMatch.h"

#include "Weapon.h"
#include "Mod.h"
#include "Server.h"

bool ModeDeathMatch::Enabled = true;

void ModeDeathMatch::Update(float dt)
{
    if (!Enabled) return;
}

void ModeDeathMatch::OnPlayerSpawn(Player* player, Vector3 position)
{
    if (!Enabled) return;

    Server::GiveWeapon(player, 1);
}

void ModeDeathMatch::OnPlayerJoin(Player* player)
{
    if (!Enabled) return;

    player->IsAlive = true;
}

void ModeDeathMatch::OnPlayerDied(Player* deadPlayer, Player* killerPlayer, Vector3 damageDir)
{
    if (!Enabled) return;

    deadPlayer->RespawnTime = 1.0f;
}