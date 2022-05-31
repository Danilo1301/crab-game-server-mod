#include "pch-il2cpp.h"
#include "Mod.h"

#include "Injector.h"
#include "Config.h"
#include "Server.h"
#include "templates.h"

bool Mod::m_DebugMode = false;
std::string Mod::m_Version = "2.0.1" + std::string(m_DebugMode ? "-dev" : "");

void Mod::Init()
{
	std::cout << "[Mod] Init v" << m_Version << std::endl;

	Injector::Init();
	
	Injector::Inject(HF_ChatBox_Update, ChatBox_Update, &Template_ChatBox_Update);
	Injector::Inject(HF_LobbyManager_AddPlayerToLobby, LobbyManager_AddPlayerToLobby, &Template_LobbyManager_AddPlayerToLobby);
	Injector::Inject(HF_LobbyManager_RemovePlayerFromLobby, LobbyManager_RemovePlayerFromLobby, &Template_LobbyManager_RemovePlayerFromLobby);
	Injector::Inject(HF_LobbyManager_BanPlayer, LobbyManager_BanPlayer, &Template_LobbyManager_BanPlayer);
	Injector::Inject(HF_PlayerManager_SetPlayer, PlayerManager_SetPlayer, &Template_PlayerManager_SetPlayer);
	Injector::Inject(HF_ServerSend_SendChatMessage, ServerSend_SendChatMessage, &Template_ServerSend_SendChatMessage);
	Injector::Inject(HF_ServerSend_PlayerDied, ServerSend_PlayerDied, &Template_ServerSend_PlayerDied);
	Injector::Inject(HF_ServerSend_GameSpawnPlayer, ServerSend_GameSpawnPlayer, &Template_ServerSend_GameSpawnPlayer);
	Injector::Inject(HF_ServerSend_LoadMap_1, ServerSend_LoadMap_1, &Template_ServerSend_LoadMap_1);
	Injector::Inject(HF_ServerHandle_PlayerDied, ServerHandle_PlayerDied, &Template_ServerHandle_PlayerDied);
	Injector::Inject(HF_ServerSend_UseItemAll, ServerSend_UseItemAll, &Template_ServerSend_UseItemAll);
	Injector::Inject(HF_ServerSend_UseItem, ServerSend_UseItem, &Template_ServerSend_UseItem);
	Injector::Inject(HF_ServerSend_PlayerDamage, ServerSend_PlayerDamage, &Template_ServerSend_PlayerDamage);
	Injector::Inject(HF_ServerSend_PunchPlayer, ServerSend_PunchPlayer, &Template_ServerSend_PunchPlayer);
	Injector::Inject(HF_ServerSend_RedLight, ServerSend_RedLight, &Template_ServerSend_RedLight);

	/*
	Injector::Inject(HF_ServerSend_u109Au109Du109Eu109Du10A1u10A2u1099u10A8u10A6u109Cu10A2, ServerSend_u109Au109Du109Eu109Du10A1u10A2u1099u10A8u10A6u109Cu10A2, &Template_ServerSend_u109Au109Du109Eu109Du10A1u10A2u1099u10A8u10A6u109Cu10A2);
	Injector::Inject(HF_ServerSend_u109Au10A0u109Fu10A6u10A8u10A3u10A5u10A5u10A5u10A5u109D, ServerSend_u109Au10A0u109Fu10A6u10A8u10A3u10A5u10A5u10A5u10A5u109D, &Template_ServerSend_u109Au10A0u109Fu10A6u10A8u10A3u10A5u10A5u10A5u10A5u109D);
	Injector::Inject(HF_ServerSend_u109Cu10A3u10A3u10A2u109Eu109Fu10A6u10A4u10A5u109Fu109C, ServerSend_u109Cu10A3u10A3u10A2u109Eu109Fu10A6u10A4u10A5u109Fu109C, &Template_ServerSend_u109Cu10A3u10A3u10A2u109Eu109Fu10A6u10A4u10A5u109Fu109C);
	Injector::Inject(HF_ServerSend_u10A1u1099u10A1u109Du10A4u10A2u10A3u10A5u10A3u109Au10A5, ServerSend_u10A1u1099u10A1u109Du10A4u10A2u10A3u10A5u10A3u109Au10A5, &Template_ServerSend_u10A1u1099u10A1u109Du10A4u10A2u10A3u10A5u10A3u109Au10A5);
	//Injector::Inject(HF_ServerHandle_PlayerDamage, ServerHandle_PlayerDamage, &Template_ServerHandle_PlayerDamage); doesnt work
	*/

	Config::LoadJSON();

	Server::Init();
}

/*
long long Mod::GetLobbyOwnerId()
{
	return (long long)(*u10A0u10A4u10A8u10A1u10A8u109Au10A8u10A1u109Eu1099u109F__TypeInfo)->static_fields->Instance->fields.originalLobbyOwnerId.m_SteamID;
}
*/

long long Mod::GetMySteamId()
{
	auto steamManager_c = (*u10A0u10A4u10A8u10A1u10A8u109Au10A8u10A1u109Eu1099u109F__TypeInfo);
	return steamManager_c->static_fields->Instance->fields._u109Du109Au10A3u10A6u10A0u10A8u1099u109Au109Du10A7u1099_k__BackingField.m_SteamID;
}

void Mod::SendChatMessage(long long fromClient, std::string message)
{
	std::cout << "[Mod] SendChatMessage " << "(" << fromClient << "): '" << message << "'" << std::endl;

	HF_ServerSend_SendChatMessage->original(fromClient, createMonoString(message.c_str()), NULL);
}

void Mod::AppendLocalChatMessage(long long fromClient, std::string username, std::string message)
{
	std::cout << "[Mod] AppendLocalChatMessage " << username << "(" << fromClient << "): '" << message << "'" << std::endl;

	auto chatBox = (*ChatBox__TypeInfo)->static_fields->Instance;
	ChatBox_AppendMessage(chatBox, fromClient, (String*)createMonoString(message.c_str()), (String*)createMonoString(username.c_str()), NULL);
}

void Mod::SendDropItem(long long toClient, int objectId, int itemId, int ammo)
{
	std::cout << "[Mod] SendDropItem toClient=" << toClient << ", objectId='" << objectId << "', itemId='" << itemId << "', ammo='" << ammo << "'" << std::endl;

	ServerSend_DropItem(toClient, objectId, itemId, ammo, NULL);
}

void Mod::ForceGiveItem(long long toClient, int objectId, int itemId)
{
	std::cout << "[Mod] ForceGiveItem toClient=" << toClient << ", objectId='" << objectId << "', itemId='" << itemId << "'" << std::endl;

	ServerSend_ForceGiveItem(toClient, objectId, itemId, NULL);
}

void Mod::KillPlayer(long long clientId)
{
	std::cout << "[Mod] KillPlayer clientId=" << clientId << std::endl;

	ServerSend_PlayerDied(clientId, clientId, Vector3({ 0, 1, 0 }), NULL);
}

void Mod::BanPlayer(long long clientId)
{
	std::cout << "[Mod] BanPlayer clientId=" << clientId << std::endl;

	auto lobbyManager = (*LobbyManager__TypeInfo)->static_fields->Instance;
	
	HF_LobbyManager_BanPlayer->original(lobbyManager, clientId, NULL);
}

void Mod::KickPlayer(long long clientId)
{
	std::cout << "[Mod] KickPlayer clientId=" << clientId << std::endl;

	auto lobbyManager = (*LobbyManager__TypeInfo)->static_fields->Instance;

	LobbyManager_KickPlayer(lobbyManager, clientId, NULL);
}

void Mod::RespawnPlayer(long long clientId, Vector3 position)
{
	if (Server::HasPlayer(clientId))
	{
		auto player = Server::GetPlayer(clientId);

		if (player->m_DiedInThisRound)
		{
			player->m_IsAlive = true;
		}

		if (Server::m_RedLightState) return;
	}

	//std::cout << "[Mod] RespawnPlayer clientId=" << clientId << formatVector3_full(position) << std::endl;

	ServerSend_RespawnPlayer(clientId, position, NULL);
}

void Mod::RestartGame()
{
	std::cout << "[Mod] RestartGame" << std::endl;

	ServerSend_StartGame(NULL);
}

void Mod::SetCurrentGameModeTime(float time)
{
	auto gameMode = (*u10A1u10A0u10A1u109Eu10A5u10A1u109Du10A8u10A5u1099u109A__TypeInfo)->static_fields->Instance->fields.gameMode;

	GameMode_SetGameModeTimer(gameMode, time, 0, NULL);
}

void Mod::SendWinner(long long clientId, long long money)
{
	ServerSend_SendWinner(clientId, money, NULL);
}

void Mod::SendLocalInteract(int itemid) {
	ClientSend_TryInteract(itemid, NULL);
}

void Mod::SetAllPlayersReady()
{
	auto gameManager = (*u10A1u10A0u10A1u109Eu10A5u10A1u109Du10A8u10A5u1099u109A__TypeInfo)->static_fields->Instance;
	auto activePlayers = gameManager->fields.activePlayers;

	for (size_t i = 0; i < activePlayers->fields.count; i++)
	{
		//auto key = activePlayers->fields.entries->vector[i].key;
		auto playerManager = activePlayers->fields.entries->vector[i].value;

		if (!playerManager) continue;

		playerManager->fields.waitingReady = true;
	}

	Mod::SendLocalInteract(4);
	Mod::SendLocalInteract(4);
}

void Mod::UseItemAll(long long clientId, int objectId, int itemId, Vector3 pos)
{
	HF_ServerSend_UseItemAll->original(clientId, objectId, pos, itemId, NULL);
}