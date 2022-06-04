#include "pch-il2cpp.h"
#include "Player.h"

#include "Server.h"
#include "PermissionGroups.h"
#include "Chat.h"

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