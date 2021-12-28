#include "Player.h"

Player::Player(int playerId, int numberId, long long clientId, void* playerManager) {
	m_PlayerId = playerId;
	m_NumberId = numberId;
	m_ClientId = clientId;
	m_PlayerManager = playerManager;
}

bool Player::GetIsAlive() {
	//if (m_PlayerManager == nullptr) return false;
	//return *(bool*)((uint64_t)m_PlayerManager + 0x39);

	return m_IsAlive;
}

std::string Player::GetDisplayName() {
	std::string str(m_Username + "[" + GetSelector() + "]");
	return str;
}

std::string Player::GetSelector() {
	std::string str("#" + std::to_string(m_PlayerId));
	return str;
}

void Player::AddPermission(std::string permission) {
	m_Permissions.push_back(permission);
}