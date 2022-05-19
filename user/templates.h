#pragma once

#include "Injector.h"
#include "Server.h"
#include "Chat.h"
/*
Template

auto CLASSNAME_METHODNAME = new HookFunction<void*>(00000000000);
void Template_CLASSNAME_METHODNAME(void* _this)
{
	CLASSNAME_METHODNAME->original(_this);
}

CLASSNAME_METHODNAME->SetTemplate(&Template_CLASSNAME_METHODNAME);
Injector::Inject(CLASSNAME_METHODNAME);

*/


auto ServerSend_LoadMap = new HookFunction<void*>(19771072);
void Template_ServerSend_LoadMap(void* _this)
{
	Server::m_CanUpdateSpawnPosition = true;

	ServerSend_LoadMap->original(_this);
}


auto ServerSend_GameSpawnPlayer = new HookFunction<uint64_t, uint64_t, Vector3, int32_t, bool, void*, int32_t>(19769408);
void Template_ServerSend_GameSpawnPlayer(uint64_t toClientId, uint64_t spawnedClientId, Vector3 spawnPos, int32_t param_3, bool streamerMode, void* byteArray, int32_t numberId)
{


	if (Server::m_CanUpdateSpawnPosition) {
		Server::m_CanUpdateSpawnPosition = false;
		Server::m_SpawnPosition = spawnPos;
	}

	if (Server::HasPlayer(spawnedClientId)) {
		Player* player = Server::GetPlayer(spawnedClientId);
		player->m_IsAlive = true;

		//player->lastSpawnPos->x = spawnPos.x;
		//player->lastSpawnPos->y = spawnPos.y;
		//player->lastSpawnPos->z = spawnPos.z;

		//player->m_NumberId = numberId;
		//Server::ChangePlayerIsAliveState(player, true);
	}

	ServerSend_GameSpawnPlayer->original(toClientId, spawnedClientId, spawnPos, param_3, streamerMode, byteArray, numberId);
}


auto ServerSend_PlayerDied = new HookFunction<long long, long long, Vector3>(19775664);
void Template_ServerSend_PlayerDied(long long deadClient, long long damageDoerId, Vector3 damageDir)
{
	if (Server::HasPlayer(deadClient))
	{
		Player* deadPlayer = Server::GetPlayer(deadClient);
		deadPlayer->m_IsAlive = false;

		//Server::ChangePlayerIsAliveState(deadPlayer, false);

		if (deadPlayer->m_GodEnabled) return;

		if (deadClient == damageDoerId)
		{
			Chat::SendServerMessage("" + deadPlayer->GetDisplayName() + " died");
		}
		else
		{
			if (Server::HasPlayer(damageDoerId)) {
				Player* killerPlayer = Server::GetPlayer(damageDoerId);

				Chat::SendServerMessage("" + killerPlayer->GetDisplayName() + " killed " + deadPlayer->GetDisplayName());
			}
			else {
				Chat::SendServerMessage("" + deadPlayer->GetDisplayName() + " died");
			}
		}


	}

	ServerSend_PlayerDied->original(deadClient, damageDoerId, damageDir);
}



auto ServerSend_PunchPlayer = new HookFunction<uint64_t, uint64_t, Vector3>(19777456);
void Template_ServerSend_PunchPlayer(uint64_t a, uint64_t b, Vector3 dir)
{

	//move later

	/*
	char str[256];
	sprintf_s(str, "%.3f, %.3f, %.3f", dir.x, dir.y, dir.z);

	char buffer[256];
	sprintf_s(buffer, "%lld punched %lld, %s", a, b, str);

	Mod::AppendLocalChatMessage(2, "PUNCH-PLAYER", buffer);
	*/


	if (Server::HasPlayer(a)) {
		auto player = Server::GetPlayer(a);

		if (player->m_JumpPunchEnabled) {
			ServerSend_PunchPlayer->original(a, a, Vector3({ 0, 3, 0 }));
		}

		if (player->m_SuperPunchEnabled) {
			ServerSend_PunchPlayer->original(a, b, Vector3({ 0, 4, 0 }));
		}
	}

	if (Server::HasPlayer(b)) {
		if (Server::GetPlayer(b)->m_ForceFieldEnabled) {
			Vector3 newDir = Vector3({ dir.x * -3, dir.y * -3, dir.z * -3 });

			ServerSend_PunchPlayer->original(b, a, newDir);
			return;
		}
	}

	ServerSend_PunchPlayer->original(a, b, dir);
}


auto ServerSend_SendChatMessage = new HookFunction<uint64_t, monoString*>(19779104);
void Template_ServerSend_SendChatMessage(uint64_t fromClient, monoString* message)
{
	/*
	if (SocketServer::m_IsConnected) {

		long long currentLobby = Mod::GetSteamManager()->static_fields->Instance->fields.currentLobby.fields.m_SteamID;
		long long originalLobbyOwnerId = Mod::GetSteamManager()->static_fields->Instance->fields.originalLobbyOwnerId.fields.m_SteamID;

		//SocketServer::SendLobbyInfo(lobbyId);

		SocketServer::Emit("currentLobby:" + std::to_string(currentLobby));
		SocketServer::Emit("originalLobbyOwnerId:" + std::to_string(originalLobbyOwnerId));

		Mod::AppendLocalChatMessage(0, "currentLobby", std::to_string(currentLobby));
		Mod::AppendLocalChatMessage(0, "originalLobbyOwnerId", std::to_string(originalLobbyOwnerId));

	}
	*/


	if (Server::m_LobbyOwner->m_ClientId == fromClient) {
		if (!Server::m_LobbyOwner->m_HideMessages) {
			Mod::AppendLocalChatMessage(2, Server::m_LobbyOwner->GetDisplayName(), message->toCPPString().c_str());
		}
	}


	Chat::ProcessRawMessage(fromClient, message->toCPPString());
}

//-------------------------------------------------


auto LobbyManager_BanPlayer = new HookFunction<void*, uint64_t, const void*>(13701920);
void Template_LobbyManager_BanPlayer(void* _this, uint64_t steamId, const void* method)
{
	bool canBan = Server::OnPlayerAttemptBanned(steamId);



	if (canBan) LobbyManager_BanPlayer->original(_this, steamId, method);
}

auto LobbyManager_AddPlayerToLobby = new HookFunction<void*, void*>(13700096);
void Template_LobbyManager_AddPlayerToLobby(void* _this, void* CSteamID)
{
	uintptr_t ptr1 = (uintptr_t)_this;
	uintptr_t ptr2 = ptr1 + 0x18;
	long long lobbyId = *(long long*)ptr2;

	Server::m_LobbyId = lobbyId;

	/*
	char buffer[256];
	sprintf_s(buffer, "add= %lld\n%p\nval=%lld", id, _this, lobbyId);
	MessageBoxA(NULL, buffer, NULL, NULL);
	*/

	//LobbyManager = _this;

	LobbyManager_AddPlayerToLobby->original(_this, CSteamID);
	Server::OnPlayerAddedToLobby((long long)CSteamID);
}

auto LobbyManager_RemovePlayerFromLobby = new HookFunction<void*, void*>(13705168);
void Template_LobbyManager_RemovePlayerFromLobby(void* _this, void* CSteamID)
{
	LobbyManager_RemovePlayerFromLobby->original(_this, CSteamID);
	Server::OnPlayerRemovedFromLobby((long long)CSteamID);
}


//-------------------------------------------------


auto ChatBox_AppendMessage = new HookFunction<void*, uint64_t, monoString*, monoString*>(15681968);
void Template_ChatBox_AppendMessage(void* _this, uint64_t fromClient, monoString* message, monoString* username)
{
	if (fromClient == 0) return;

	ChatBox_AppendMessage->original(_this, fromClient, message, username);
}

auto ChatBox_Update = new HookFunction<u109Du10A6u109Eu10A3u10A7u10A2u10A3u10A8u10A8u109Eu10A1*>(15689360);
void Template_ChatBox_Update(u109Du10A6u109Eu10A3u10A7u10A2u10A3u10A8u10A8u109Eu10A1* _this)
{
	auto now = std::chrono::system_clock::now();
	std::chrono::duration<float, std::milli> diff = now - Server::m_LastUpdatedTime;
	Server::Update(diff.count());
	Server::m_LastUpdatedTime = now;

	ChatBox_Update->original(_this);
}

//-------------------------------------------------



//-------------------------------------------------

/*
auto ServerHandle_TryInteract = new HookFunction<uint64_t, Packet*>(12506752);
void Template_ServerHandle_TryInteract(uint64_t fromClient, Packet* packet)
{
	char buffer[256];
	sprintf_s(buffer, "Interact from= %lld", fromClient);
	Mod::SendChatMessage(1, buffer);

	ServerHandle_TryInteract->original(fromClient, packet);
}
*/

//-------------------------------------------------



//-------------------------------------------------

auto PlayerManager_SetPlayer = new HookFunction<u10A5u109Au109Eu109Eu1099u10A8u10A8u109Au109Du109Fu109C*, uint64_t, int32_t, bool, const void*>(15599840);
void Template_PlayerManager_SetPlayer(u10A5u109Au109Eu109Eu1099u10A8u10A8u109Au109Du109Fu109C* playerManager, uint64_t steamId, int32_t playerId, bool streamerMode, const void* method)
{
	PlayerManager_SetPlayer->original(playerManager, steamId, playerId, streamerMode, method);

	Server::TryAddPlayer(steamId, playerId, playerManager);
}