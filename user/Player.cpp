#include "pch-il2cpp.h"
#include "Player.h"

#include "Server.h"
#include "PermissionGroups.h"

Player::Player(long long clientId, int id)
{
	m_ClientId = clientId;
	m_Id = id;
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
	return m_Username + "[" + std::to_string(m_Id) + "]";
}

PermissionGroup* Player::GetPermissionGroup()
{
	return PermissionGroups::GetGroup(m_PermissionGroup);
}

void Player::SetAlive(bool alive)
{
	if (!m_JustSpawned)
	{
		m_JustSpawned = true;

		std::cout << "[Player] " << GetDisplayNameExtra() << " just spawned" << std::endl;
	}

	m_IsAlive = alive;
}