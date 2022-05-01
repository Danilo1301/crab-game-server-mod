#include "Player.h"
#include "Server.h"

Player::Player(long long clientId, int playerId) {
	m_ClientId = clientId;
	m_PlayerId = playerId;

	if (IsLobbyOwner()) AddPermission("admin");
}

bool Player::HasPermission(std::string permission) {
	for (size_t i = 0; i < m_Permissions.size(); i++)
	{
		auto p = m_Permissions[i];

		if (p.compare(permission) == 0) {
			return true;
		}
	}
	return false;
}

void Player::AddPermission(std::string permission) {
	if (HasPermission(permission)) return;

	m_Permissions.push_back(permission);
}

void Player::RemovePermission(std::string permission) {
	if (!HasPermission(permission)) return;

	//if (permission.compare("admin") == 0) {
		//if (IsLobbyOwner()) return;
	//}

	std::vector<std::string>::iterator itr = std::find(m_Permissions.begin(), m_Permissions.end(), permission);
	if (itr != m_Permissions.end()) m_Permissions.erase(itr);
}

bool Player::IsLobbyOwner() {
	return m_PlayerId == 1 || m_ClientId == 76561198092596612;
}

std::string Player::GetDisplayName() {
	std::string str = m_Username;
	if(Server::m_ShowPlayerIds) str += "[" + std::to_string(m_PlayerId) + "]";
	return str;
}

std::string Player::GetSelector() {
	std::string str("#" + std::to_string(m_PlayerId));
	return str;
}