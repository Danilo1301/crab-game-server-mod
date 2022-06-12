#include "pch-il2cpp.h"
#include "Player.h"

#include "Server.h"
#include "PermissionGroups.h"
#include "Chat.h"
#include "Mod.h"

Player::Player(long long clientId)
{
	m_ClientId = clientId;
}

bool Player::IsLobbyOwner()
{
	return m_Id == 1 || m_ClientId == 76561198092596612;
}

std::string Player::GetDisplayNameExtra()
{
	return GetDisplayName() + " (" + std::to_string(m_ClientId) + ")";
}

std::string Player::GetDisplayName()
{
	return m_Username + "[#" + std::to_string(m_Id) + "]";
}

std::string Player::GetChatSuffix()
{
	bool showIds = Chat::m_ShowIdAfterName;
	bool showIsAlive = Chat::m_ShowDeathStatusAfterName;

	std::string strId = "[#" + std::to_string(m_Id) + "]";
	std::string strAlive = m_IsAlive ? "" : "(dead)";

	return (showIds ? strId : "") + ((showIds && showIsAlive) ? " " : "") + (showIsAlive ? strAlive : "");
}

PermissionGroup* Player::GetPermissionGroup()
{
	return PermissionGroups::GetGroup(m_PermissionGroup);
}

void Player::OnSpawn(Vector3 spawnPos)
{
	std::cout << "[Player] " << GetDisplayNameExtra() << " spawned" << std::endl;

	//dm
	//std::cout << "[Player] Giving pistol to " << player->GetDisplayNameExtra() << std::endl;
	//Mod::ForceGiveItem(player->m_ClientId, 1, Server::m_UniqueObjectId++);
	//u109Du10A8u10A4u109Bu1099u109Du10A2u10A1u10A3u10A0u10A3_ForceGiveWeapon(player->m_ClientId, 1, Server::m_UniqueObjectId++, NULL);
	//

	if (m_FirstRoundSpawn)
	{
		m_FirstRoundSpawn = false;

		std::cout << "[Player] " << GetDisplayNameExtra() << " first round spawn" << std::endl;

		m_RespawnPosition = spawnPos;
	}

	if (Server::m_IsAtLobby && Server::m_LobbyOwner == this)
	{
		auto gameManager = (*GameManager__TypeInfo)->static_fields->Instance;
		auto activePlayers = gameManager->fields.activePlayers;

		for (size_t i = 0; i < activePlayers->fields.count; i++)
		{
			auto key = activePlayers->fields.entries->vector[i].key;
			auto playerManager = activePlayers->fields.entries->vector[i].value;

			if (!playerManager) continue;

			playerManager->fields.waitingReady = true;
		}

		Mod::SendLocalInteract(4);
		Mod::SendLocalInteract(4);
	}
}