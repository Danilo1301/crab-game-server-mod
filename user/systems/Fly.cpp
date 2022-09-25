#include "pch-il2cpp.h"
#include "Fly.h"

#include "Server.h"
#include "Mod.h"

void Fly::Update(float dt)
{
	for (auto player : Server::GetOnlinePlayers())
	{
		if (!player->FlyEnabled) continue;

		if (!player->IsAlive) continue;

		if (player->FlyVelocity > 0)
		{
			player->FlyVelocity -= 1.0f * dt;
			if (player->FlyVelocity < 0) player->FlyVelocity = 0;
		}

		Vector3 newPos = player->Position;

		if (player->FlyVelocity > 0)
			newPos = newPos + (player->LookDir) * (player->FlyVelocity * player->FlySpeed) * dt;

		Server::RespawnActivePlayerAtPos(player->ClientId, newPos);

		player->Position = newPos;
	}
}

void Fly::OnPunch(Player* player)
{
	if (player->FlyEnabled)
		player->FlyVelocity = 1.0f;
}