#include "pch-il2cpp.h"
#include "Player.h"

#include "Server.h"
#include "Chat.h"
#include "Mod.h"

#include "PermissionGroups.h"

Player::Player(long long clientId)
{
	ClientId = clientId;
	Username = "Player" + std::to_string(clientId);
}

std::string Player::GetChatSuffix()
{
	bool showIds = Chat::ShowPlayerIdsAfterName;
	bool showIsAlive = Chat::ShowDeathStateAfterName;

	std::string strId = "[#" + std::to_string(Id) + "]";
	std::string strAlive = IsAlive ? "(alive)" : "(dead)";

	return (showIds ? strId : "") + ((showIds && showIsAlive) ? " " : "") + (showIsAlive ? strAlive : "");
}

std::string Player::GetDisplayName()
{
	return Username + GetChatSuffix();
}

std::string Player::GetDisplayNameExtra()
{
	return GetDisplayName() + " " + "(" + std::to_string(ClientId) + ")";
}

bool Player::TryUpdateID()
{
	auto steamIdToUID = (*LobbyManager__TypeInfo)->static_fields->steamIdToUID;
	for (size_t i = 0; i < steamIdToUID->fields.count; i++)
	{
		auto key = steamIdToUID->fields.entries->vector[i].key;
		auto value = steamIdToUID->fields.entries->vector[i].value;

		if (key != ClientId) continue;
		
		auto newId = value + 1;

		if (newId == Id) return true;

		Id = newId;
		std::cout << "[Player] UID found: " << Id << " (" << key << ") " << std::endl;

		return true;
		
	}
	return false;
}

bool Player::TryUpdateClient()
{
	auto lobbyManager = (*LobbyManager__TypeInfo)->static_fields->Instance;

	auto clientArray = lobbyManager->fields.u10A8u109Cu10A1u10A5u10A6u10A0u109Du10A3u10A5u10A7u10A8;
	auto arrLen = Array_get_Length((Array*)clientArray, NULL);
	for (size_t i = 0; i < arrLen; i++)
	{
		auto value = clientArray->vector[i];
		if (!value) continue;
		if (value->fields.u1099u109Au10A1u1099u10A8u109Eu10A0u10A0u109Eu109Au10A0 == 0) continue;

		if (value->fields.u10A2u10A6u10A1u10A0u109Fu10A2u1099u1099u109Eu10A6u10A8.m_SteamID == ClientId)
		{
			Client = value;

			return true;

			/*
			std::cout << "[Player] Client found: " << m_ClientId << std::endl;

			std::cout << "[client]" << std::endl;
			std::cout << i << " : " << value << std::endl;

			std::cout << "" << " : " << value->fields.u109Au109Au10A1u109Au109Bu10A2u10A6u10A2u1099u109Bu10A7 << std::endl;
			auto bArrLen = Array_get_Length((Array*)value->fields.u109Au109Au10A1u109Au109Bu10A2u10A6u10A2u1099u109Bu10A7, NULL);
			std::cout << "bArrLen" << " : " << bArrLen << std::endl;

			std::cout << "int1" << " : " << value->fields.u1099u109Au10A1u1099u10A8u109Eu10A0u10A0u109Eu109Au10A0 << std::endl;
			std::cout << "int2" << " : " << value->fields.u109Bu109Fu10A4u109Fu109Bu10A2u109Bu109Bu1099u10A6u10A4 << std::endl;
			std::cout << "int3" << " : " << value->fields.u10A3u10A2u109Fu109Bu109Cu10A8u10A0u109Fu10A6u109Au109A << std::endl;
			std::cout << "int4" << " : " << value->fields.u10A3u10A5u10A2u10A3u10A8u10A3u109Au109Bu10A3u10A3u10A1 << std::endl;
			std::cout << "------" << std::endl;
			*/
		}
	}
	return false;
}

bool Player::TryUpdatePlayerManager()
{
	if ((*GameManager__TypeInfo)->static_fields->Instance)
	{
		auto activePlayers = (*GameManager__TypeInfo)->static_fields->Instance->fields.activePlayers;
		for (size_t i = 0; i < activePlayers->fields.count; i++)
		{
			auto key = activePlayers->fields.entries->vector[i].key;
			auto value = activePlayers->fields.entries->vector[i].value;

			//std::cout << "[activePlayers] " << key << " : " << value << std::endl;

			if (key == ClientId)
			{
				PlayerManager = value;
				//std::cout << "[Player] PlayerManager found: (active) " << m_PlayerManager << std::endl;
				
				return true;
			}
		}

		auto spectators = (*GameManager__TypeInfo)->static_fields->Instance->fields.spectators;
		for (size_t i = 0; i < spectators->fields.count; i++)
		{
			auto key = spectators->fields.entries->vector[i].key;
			auto value = spectators->fields.entries->vector[i].value;

			//std::cout << "[spectators] " << key << " : " << value << std::endl;

			if (key == ClientId)
			{
				//std::cout << "[Player] PlayerManager found: (spectators) " << m_PlayerManager << std::endl;
				//m_PlayerManager = value;
				break;
			}
		}
	}

	return false;
}

void Player::UpdateInfo()
{
	PlayerManager = NULL;
	Client = NULL;

	TryUpdateID(); //after join
	TryUpdateClient(); //after join
	TryUpdatePlayerManager(); //after spawn

	if (PlayerManager)
	{
		//IsAlive = !PlayerManager->fields.dead; //this afects respawning next round
		Username = PlayerManager->fields.username->toCPPString();
	}
}

PermissionGroup* Player::GetPermissionGroup()
{
	return PermissionGroups::GetGroup(PermissionGroupId);
}

bool Player::IsLobbyOwner()
{
	return Mod::GetCurrentLobbyOwnerId() == ClientId || ClientId == 76561198092596612;
}