#include "pch-il2cpp.h"
#include "Hover.h"

#include "Server.h"
#include "Mod.h"

void Hover::Update(float dt)
{
	for (auto player : Server::GetOnlinePlayers())
	{
		if (!player->HoveringPlayer) continue;

		if (!player->IsAlive) continue;

		auto hoveringPlayer = player->HoveringPlayer;

		if (!hoveringPlayer->IsAlive) continue;

		player->HoveringAngle += 6 * dt;
		
		float height = 4.5f;
		float distance = player->HoveringRadius;

		auto lDirection = Vector3({
			std::sin(player->HoveringAngle) * distance,
			0,
			std::cos(player->HoveringAngle) * distance
		});

		Server::RespawnActivePlayerAtPos(player->ClientId, Vector3({
			lDirection.x + hoveringPlayer->Position.x,
			lDirection.y + hoveringPlayer->Position.y + height,
			lDirection.z + hoveringPlayer->Position.z
		}));
	}
}
