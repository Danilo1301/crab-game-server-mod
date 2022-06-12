#pragma once

#include "Injector.h"
#include "Server.h"
#include "Chat.h"

#include "templates_GameServer.h"
#include "templates_GameManager.h"

auto HF_ChatBox_Update = new HookFunction<void, ChatBox*, MethodInfo*>("ChatBox::Update");
void Template_ChatBox_Update(ChatBox* a, MethodInfo* method)
{
	//std::cout << "ChatBox::Update" << " a=" << a << ", " << std::endl;

	float dt = Time_get_deltaTime(NULL);
	Server::Update(dt);

	HF_ChatBox_Update->original(a, method);
}

auto HF_ChatBox_AppendMessage = new HookFunction<void, ChatBox*, uint64_t, String*, String*, MethodInfo*>("ChatBox::AppendMessage");
void Template_ChatBox_AppendMessage(ChatBox* a, uint64_t b, String* c, String* d, MethodInfo* method)
{
	//std::cout << "ChatBox::AppendMessage" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	if (b == 0) return;

	HF_ChatBox_AppendMessage->original(a, b, c, d, method);
}

auto HF_LobbyManager_AddPlayerToLobby = new HookFunction<void, LobbyManager*, CSteamID, MethodInfo*>("LobbyManager::AddPlayerToLobby");
void Template_LobbyManager_AddPlayerToLobby(LobbyManager* a, CSteamID b, MethodInfo* method)
{

	auto testId = a->fields._u109Du10A7u10A2u10A4u10A5u10A1u10A7u10A5u109Du10A5u10A4_k__BackingField.m_SteamID;

	uintptr_t ptr2 = (uintptr_t)a + 0x18;
	long long lobbyId = *(long long*)ptr2;

	//std::cout << "LobbyManager::AddPlayerToLobby" << " a=" << a << ", " << " b=" << b.m_SteamID << ", lobbyId=" << lobbyId << ", testId=" << testId << std::endl;

	if (Server::m_LobbyId != lobbyId) {
		Server::OnCreateLobby();
	}

	Server::m_LobbyId = lobbyId;

	HF_LobbyManager_AddPlayerToLobby->original(a, b, method);
}

auto HF_LobbyManager_RemovePlayerFromLobby = new HookFunction<void, LobbyManager*, CSteamID, MethodInfo*>("LobbyManager::RemovePlayerFromLobby");
void Template_LobbyManager_RemovePlayerFromLobby(LobbyManager* a, CSteamID b, MethodInfo* method)
{
	//std::cout << "LobbyManager::RemovePlayerFromLobby" << " a=" << a << ", " << " b=" << b.m_SteamID << ", " << std::endl;

	if (Server::HasPlayer(b.m_SteamID)) {
		auto player = Server::GetPlayer(b.m_SteamID);
		player->m_IsOnline = false;

		Server::OnPlayerLeave(player);
		//Server::RemovePlayer(player);
	}

	HF_LobbyManager_RemovePlayerFromLobby->original(a, b, method);
}

auto HF_LobbyManager_BanPlayer = new HookFunction<void, LobbyManager*, uint64_t, MethodInfo*>("LobbyManager::BanPlayer");
void Template_LobbyManager_BanPlayer(LobbyManager* a, uint64_t b, MethodInfo* method)
{
	//std::cout << "LobbyManager::BanPlayer" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	//HF_LobbyManager_BanPlayer->original(a, b, method);
}

auto HF_PlayerManager_SetPlayer = new HookFunction<void, PlayerManager*, uint64_t, int32_t, bool, MethodInfo*>("PlayerManager::SetPlayer");
void Template_PlayerManager_SetPlayer(PlayerManager* playerManager, uint64_t clientId, int32_t playerId, bool d, MethodInfo* method)
{
	//std::cout << "PlayerManager::SetPlayer" << " playerManager=" << playerManager << ", " << " clientId=" << clientId << ", " << " playerId=" << playerId << ", " << " d=" << d << ", " << std::endl;

	HF_PlayerManager_SetPlayer->original(playerManager, clientId, playerId, d, method);

	Server::TryAddPlayer(clientId, playerId, playerManager);
}

auto HF_ServerSend_SendChatMessage = new HookFunction<void, uint64_t, monoString*, MethodInfo*>("ServerSend::SendChatMessage");
void Template_ServerSend_SendChatMessage(uint64_t clientId, monoString* message, MethodInfo* method)
{
	//std::cout << "ServerSend::SendChatMessage" << " a=" << clientId << ", " << " b=" << message->toCPPString() << ", " << std::endl;

	auto owner = Server::m_LobbyOwner;
	if (owner->m_ClientId == clientId) {
		if (!owner->m_HideMessages) {
			Mod::AppendLocalChatMessage(2, owner->m_Username, owner->GetChatSuffix() + " " + message->toCPPString().c_str());
		}
	}

	if (Server::HasPlayer(clientId))
	{
		Chat::ProcessRawMessage(clientId, message->toCPPString(), false);
		return;
	}

	HF_ServerSend_SendChatMessage->original(clientId, message, method);
}

auto HF_ServerSend_PlayerDied = new HookFunction<void, uint64_t, uint64_t, Vector3, MethodInfo*>("ServerSend::PlayerDied");
void Template_ServerSend_PlayerDied(uint64_t deadClient, uint64_t damageDoerId, Vector3 damageDir, MethodInfo* method)
{
	//std::cout << "ServerSend::PlayerDied" << " deadClient=" << deadClient << ", " << " damageDoerId=" << damageDoerId << ", " << " damageDir=" << formatVector3_full(damageDir) << ", " << std::endl;

	if (!Server::OnPlayerDied(deadClient, damageDoerId, damageDir)) return;

	HF_ServerSend_PlayerDied->original(deadClient, damageDoerId, damageDir, method);
}


auto HF_ServerSend_GameSpawnPlayer = new HookFunction<void, uint64_t, uint64_t, Vector3, int32_t, bool, Byte__Array*, int32_t, MethodInfo*>("ServerSend::GameSpawnPlayer");
void Template_ServerSend_GameSpawnPlayer(uint64_t toClientId, uint64_t spawnedClientId, Vector3 spawnPos, int32_t d, bool streamerMode, Byte__Array* byteArray, int32_t numberId, MethodInfo* method)
{
	std::cout << "ServerSend::GameSpawnPlayer" << " toClientId=" << toClientId << ", " << " spawnedClientId=" << spawnedClientId << ", " << " spawnPos=" << formatVector3_full(spawnPos) << ", " << " d=" << d << ", " << " streamerMode=" << streamerMode << ", " << " byteArray=" << byteArray << ", " << " numberId=" << numberId << ", " << std::endl;

	if (Server::HasPlayer(spawnedClientId))
	{
		Player* player = Server::GetPlayer(spawnedClientId);
		player->m_ByteArray = byteArray;
		player->m_SpawnNumberId = numberId;

		if (player->m_AutoDieEnabled && !Server::m_IsAtLobby)
		{
			ServerSend_SpectatorSpawn(spawnedClientId, NULL);
			return;
		}
	}

	HF_ServerSend_GameSpawnPlayer->original(toClientId, spawnedClientId, spawnPos, d, streamerMode, byteArray, numberId, method);

	
	if (Server::HasPlayer(spawnedClientId))
	{
		Player* player = Server::GetPlayer(spawnedClientId);

		if (toClientId == spawnedClientId)
		{
			if (!player->m_IsAlive)
			{
				player->m_IsAlive = true;
				player->OnSpawn(spawnPos);
			}
		}
	}

	/*
	if (Server::m_IsAtLobby && Server::m_LobbyOwner != NULL)
	{
		auto gameManager = (*GameManager__TypeInfo)->static_fields->Instance;
		auto activePlayers = gameManager->fields.activePlayers;

		if (activePlayers->fields.count >= 2)
		{
			for (size_t i = 0; i < activePlayers->fields.count; i++)
			{
				auto key = activePlayers->fields.entries->vector[i].key;
				auto playerManager = activePlayers->fields.entries->vector[i].value;


				if (!playerManager) continue;

				playerManager->fields.waitingReady = (key == Server::m_LobbyOwner->m_ClientId);
			}

			Mod::SendLocalInteract(4);
			Mod::SendLocalInteract(4);
		}
	}
	*/
}

auto HF_ServerSend_SpectatorSpawn = new HookFunction<void, uint64_t, MethodInfo*>("ServerSend::SpectatorSpawn");
void Template_ServerSend_SpectatorSpawn(uint64_t a, MethodInfo* method)
{
	std::cout << "ServerSend::SpectatorSpawn " << " a=" << a << ", " << std::endl;

	if (Server::HasPlayer(a))
	{
		auto player = Server::GetPlayer(a);

		if (!player->m_AutoDieEnabled) {

			if (player->m_IsOnline)
			{
				if (player->m_IsAlive && player->m_ByteArray)
				{
					GameServer_PlayerSpawnRequest(a, false, player->m_ByteArray, player->m_SpawnNumberId, NULL);
					return;
				}

				player->m_Spectating = true;
			}
		}
	}

	
	//spawn player on join
	//GameServer_PlayerSpawnRequest(a, false, Server::m_LobbyOwner->m_ByteArray, Server::m_UniqueObjectId++, NULL);

	HF_ServerSend_SpectatorSpawn->original(a, method);
}


auto HF_ServerSend_LoadMap_1 = new HookFunction<void, int32_t, int32_t, MethodInfo*>("ServerSend::LoadMap_1");
void Template_ServerSend_LoadMap_1(int32_t a, int32_t b, MethodInfo* method)
{
	std::cout << "[Mod] Load map " << a << ", mode=" << b << std::endl;

	Server::m_IsAtLobby = b == 0;
	Server::m_TimeUntilAutoStart = 0;
	
	Chat::RemoveAllMessages();

	for (auto pair : Server::m_Players)
	{
		auto player = pair.second;
		player->m_FirstRoundSpawn = true;
	}

	GameServer_ForceRemoveAllWeapons(NULL);

	HF_ServerSend_LoadMap_1->original(a, b, method);
}


auto HF_ServerHandle_PlayerDied = new HookFunction<void, uint64_t, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D*, MethodInfo*>("ServerHandle::PlayerDied");
void Template_ServerHandle_PlayerDied(uint64_t a, u10A5u109Cu10A4u1099u10A0u10A3u109Bu109Du10A4u10A6u109D* b, MethodInfo* method)
{
	//std::cout << "ServerHandle::PlayerDied" << " a=" << a << ", " << " b=" << b << ", " << std::endl;

	HF_ServerHandle_PlayerDied->original(a, b, method);
}


auto HF_ServerSend_UseItemAll = new HookFunction<void, uint64_t, int32_t, Vector3, int32_t, MethodInfo*>("ServerSend::UseItemAll");
void Template_ServerSend_UseItemAll(uint64_t a, int32_t b, Vector3 c, int32_t d, MethodInfo* method)
{
	//std::cout << "ServerSend::UseItemAll" << " a=" << a << ", " << " b=" << b << ", " << " c=" << formatVector3_full(c) << ", " << " d=" << d << ", " << std::endl;

	if (!Server::m_CanUseItem)
	{
		std::cout << "blocked" << std::endl;
		return;
	}

	HF_ServerSend_UseItemAll->original(a, b, c, d, method);
	if (Server::HasPlayer(a))
	{
		if (Server::GetPlayer(a)->m_MultiSnowballEnabled)
		{
			HF_ServerSend_UseItemAll->original(a, b, Vector3({ c.x + 2, c.y, c.z }), d, method);
			HF_ServerSend_UseItemAll->original(a, b, Vector3({ c.x - 2, c.y, c.z }), d, method);
			HF_ServerSend_UseItemAll->original(a, b, Vector3({ c.x, c.y, c.z + 2 }), Server::m_UniqueObjectId++, method);
			HF_ServerSend_UseItemAll->original(a, b, Vector3({ c.x, c.y, c.z - 2 }), Server::m_UniqueObjectId++, method);
		}
	}
}

auto HF_ServerSend_UseItem = new HookFunction<void, uint64_t, int32_t, Vector3, MethodInfo*>("ServerSend::UseItem");
void Template_ServerSend_UseItem(uint64_t a, int32_t b, Vector3 c, MethodInfo* method)
{
	//std::cout << "ServerSend::UseItem" << " a=" << a << ", " << " b=" << b << ", " << " c=" << formatVector3_full(c) << ", " << std::endl;

	if (!Server::m_CanUseItem)
	{
		std::cout << "blocked" << std::endl;
		return;
	}

	HF_ServerSend_UseItem->original(a, b, c, method);
}

auto HF_ServerSend_PlayerDamage = new HookFunction<void, uint64_t, uint64_t, int32_t, Vector3, int32_t, MethodInfo*>("ServerSend::PlayerDamage");
void Template_ServerSend_PlayerDamage(uint64_t a, uint64_t b, int32_t c, Vector3 d, int32_t e, MethodInfo* method)
{
	//std::cout << "ServerSend::PlayerDamage" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << formatVector3_full(d) << ", " << " e=" << e << ", " << std::endl;

	HF_ServerSend_PlayerDamage->original(a, b, c, d, e, method);
}

auto HF_ServerSend_PunchPlayer = new HookFunction<void, uint64_t, uint64_t, Vector3, MethodInfo*>("ServerSend::PunchPlayer");
void Template_ServerSend_PunchPlayer(uint64_t playerId, uint64_t punchedPlayerId, Vector3 dir, MethodInfo* method)
{
	std::cout << "ServerSend::PunchPlayer" << " playerId=" << playerId << ", " << " punchedPlayerId=" << punchedPlayerId << ", " << " dir=" << formatVector3_full(dir) << std::endl;



	if (Server::HasPlayer(playerId)) {
		auto player = Server::GetPlayer(playerId);

		if (player->m_FlyEnabled)
		{
			player->m_FlyVelocity = 1.0f;
		}

		if (player->m_JumpPunchEnabled) {
			HF_ServerSend_PunchPlayer->original(player->m_ClientId, player->m_ClientId, Vector3({ 0, 3, 0 }), NULL);
		}


		if (player->m_SuperPunchEnabled) {

			auto intensity = Server::m_IsAtLobby ? 2.5f : 1.5f;

			HF_ServerSend_PunchPlayer->original(player->m_ClientId, punchedPlayerId, Vector3({ dir.x * intensity, intensity, dir.z * intensity }), NULL);
		}
	}

	if (Server::HasPlayer(punchedPlayerId)) {
		if (Server::GetPlayer(punchedPlayerId)->m_ForceFieldEnabled) {
			Vector3 newDir = Vector3({ dir.x * -3, dir.y * -3, dir.z * -3 });

			HF_ServerSend_PunchPlayer->original(punchedPlayerId, playerId, newDir, NULL);
			return;
		}
	}

	HF_ServerSend_PunchPlayer->original(playerId, punchedPlayerId, dir, method);

	auto punchDamageId = Server::m_IsAtLobby ? 4 : Server::m_PunchDamageId;

	ServerSend_PlayerDamage(playerId, punchedPlayerId, 0, Vector3({ -dir.x, -dir.y, -dir.z }), punchDamageId, NULL);
}

auto HF_ServerSend_RedLight = new HookFunction<void, uint64_t, bool, float, MethodInfo*>("ServerSend::RedLight");
void Template_ServerSend_RedLight(uint64_t a, bool b, float c, MethodInfo* method)
{
	//std::cout << "ServerSend::RedLight" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << std::endl;

	Server::m_RedLightState = b;

	HF_ServerSend_RedLight->original(a, b, c, method);
}

auto HF_ServerSend_FreezePlayers = new HookFunction<void, bool, MethodInfo*>("ServerSend::FreezePlayers");
void Template_ServerSend_FreezePlayers(bool a, MethodInfo* method)
{
	std::cout << "ServerSend::FreezePlayers" << " a=" << a << ", " << std::endl;

	HF_ServerSend_FreezePlayers->original(a, method);
}