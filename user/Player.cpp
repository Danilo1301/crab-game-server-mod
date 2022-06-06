#include "pch-il2cpp.h"
#include "Player.h"

#include "Server.h"
#include "PermissionGroups.h"
#include "Chat.h"

Player::Player(long long clientId)
{
	m_ClientId = clientId;
	m_Username = "Player" + std::to_string(clientId);
}

bool Player::GetIsAlive()
{
	return m_PlayerManager != NULL;
}

std::string Player::GetChatSuffix()
{
	bool showIds = true; // Chat::m_ShowIdAfterName;
	bool showIsAlive = true; // Chat::m_ShowDeathStatusAfterName;

	std::string strId = "[#" + std::to_string(m_Id) + "]";
	std::string strAlive = GetIsAlive() ? "(alive)" : "(dead)";

	return (showIds ? strId : "") + ((showIds && showIsAlive) ? " " : "") + (showIsAlive ? strAlive : "");
}

std::string Player::GetDisplayName()
{
	return m_Username + GetChatSuffix();
}

std::string Player::GetDisplayNameExtra()
{
	return GetDisplayName() + " " + "(" + std::to_string(m_ClientId) + ")";
}

void Player::UpdateInfo()
{
	std::cout << "UpdateInfo " << m_ClientId << std::endl;

	//m_Username = (SteamFriends_GetPlayerNickname(CSteamID({ (uint64_t)m_ClientId }), NULL))->toCPPString();
	//std::cout << "username:" << m_Username << std::endl;

	//
	
	auto lobbyManager = (*LobbyManager__TypeInfo)->static_fields->Instance;

	auto clientArray = lobbyManager->fields.u10A8u109Cu10A1u10A5u10A6u10A0u109Du10A3u10A5u10A7u10A8;
	auto arrLen = Array_get_Length((Array*)clientArray, NULL);


	std::cout << "clients" << std::endl;

	for (size_t i = 0; i < arrLen; i++)
	{
		auto value = clientArray->vector[i];
		if (!value) continue;
		if (value->fields.u1099u109Au10A1u1099u10A8u109Eu10A0u10A0u109Eu109Au10A0 == 0) continue;

		if (value->fields.u10A2u10A6u10A1u10A0u109Fu10A2u1099u1099u109Eu10A6u10A8.m_SteamID == m_ClientId)
		{
			m_Client = value;
		}

		/*
		std::cout << "[client]" << std::endl;
		std::cout << i << " : " << value << std::endl;
		std::cout << "" << " : " << value->fields.u1099u109Au10A1u1099u10A8u109Eu10A0u10A0u109Eu109Au10A0 << std::endl;
		std::cout << "" << " : " << value->fields.u109Au109Au10A1u109Au109Bu10A2u10A6u10A2u1099u109Bu10A7 << std::endl;
		auto bArrLen = Array_get_Length((Array*)value->fields.u109Au109Au10A1u109Au109Bu10A2u10A6u10A2u1099u109Bu10A7, NULL);
		std::cout << "bArrLen" << " : " << bArrLen << std::endl;
		*/
	}
	
	//

	auto steamIdToUID = (*LobbyManager__TypeInfo)->static_fields->steamIdToUID;
	for (size_t i = 0; i < steamIdToUID->fields.count; i++)
	{
		auto key = steamIdToUID->fields.entries->vector[i].key;
		auto value = steamIdToUID->fields.entries->vector[i].value;

		//std::cout << "[steamIdToUID] " << key << " : " << value << std::endl;

		if (key == m_ClientId)
		{
			m_Id = value;
			break;
		}
	}

	//

	if ((*GameManager__TypeInfo)->static_fields->Instance)
	{
		//std::cout << "getting player manager" << std::endl;
		
		auto activePlayers = (*GameManager__TypeInfo)->static_fields->Instance->fields.activePlayers;
		for (size_t i = 0; i < activePlayers->fields.count; i++)
		{
			auto key = activePlayers->fields.entries->vector[i].key;
			auto value = activePlayers->fields.entries->vector[i].value;

			//std::cout << "[activePlayers] " << key << " : " << value << std::endl;

			if (key == m_ClientId)
			{
				m_PlayerManager = value;
				break;
			}
		}

		auto spectators = (*GameManager__TypeInfo)->static_fields->Instance->fields.spectators;
		for (size_t i = 0; i < spectators->fields.count; i++)
		{
			auto key = spectators->fields.entries->vector[i].key;
			auto value = spectators->fields.entries->vector[i].value;

			//std::cout << "[spectators] " << key << " : " << value << std::endl;

			if (key == m_ClientId)
			{
				m_PlayerManager = value;
				break;
			}
		}
	}

	if (m_PlayerManager)
	{
		m_Username = m_PlayerManager->fields.username->toCPPString();
	}

	//std::cout << "PlayerManager: " << m_PlayerManager << std::endl;
}