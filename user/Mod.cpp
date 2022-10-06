#include "pch-il2cpp.h"
#include "Mod.h"

#include "Injector.h"
#include "Server.h"
#include "templates\templates.h"

#include "Test.h"

std::string Mod::Version = "3.3";
bool Mod::ConsoleMode = false;
int Mod::UniqueObjectId = 100;
bool Mod::LoadAllTemplates = false;

void Mod::Init()
{
	std::cout << "[Mod] Init v" << Version << std::endl;

	if (ConsoleMode)
	{
		InitConsole();
	}
	else
	{
		Injector::Init();
		Inject_Templates();
		Inject_Templates_GameServer();
		Inject_Templates_LobbyManager();
		Inject_Templates_ServerSend();
		Inject_Templates_GameManager();
	}

	Server::Init();
}

void Mod::InitConsole()
{
	std::cout << "[Mod] InitConsole" << std::endl;

	Test();

	float loopTime = 250.0f;
	while (true)
	{
		std::cout << "[Mod] --- Loop " << loopTime << " ---" << std::endl;

		Server::Update(loopTime);

		Sleep((DWORD)loopTime);
	}
}

void Mod::AppendLocalChatMessage(long long fromClient, std::string username, std::string content)
{
	if (!*ChatBox__TypeInfo) return;

	auto chatBox = (*ChatBox__TypeInfo)->static_fields->Instance;

	if (!chatBox) return;

	ChatBox_AppendMessage(chatBox, fromClient, (String*)il2cpp_string_new(content.c_str()), (String*)il2cpp_string_new(username.c_str()), NULL);
}

void Mod::SendChatMessage(long long fromClient, std::string content)
{
	if (ConsoleMode) return;

	HF_ServerSend_SendChatMessage->original((uint64_t)fromClient, (String*)il2cpp_string_new(content.c_str()), NULL);
}

void Mod::SendDropItem(long long toClient, int itemId, int objectId, int ammo)
{
	std::cout << "[Mod] SendDropItem toClient=" << toClient << ", itemId='" << itemId << "', objectId='" << objectId << "', ammo='" << ammo << "'" << std::endl;

	ServerSend_DropItem(toClient, itemId, objectId, ammo, NULL);
}

void Mod::ForceGiveItem(long long toClient, int itemId, int objectId)
{
	std::cout << "[Mod] ForceGiveItem toClient=" << toClient << ", itemId='" << itemId << "', objectId='" << objectId << "'" << std::endl;
	
	
	GameServer_ForceGiveWeapon(toClient, itemId, objectId, NULL);
	//ServerSend_ForceGiveItem(toClient, itemId, objectId, NULL);
	//ServerSend_PlayerActiveItem(toClient, itemId, NULL);

}

void Mod::RestartGame()
{
	std::cout << "[Mod] RestartGame" << std::endl;

	ServerSend_StartGame(NULL);
}

void Mod::SetCurrentGameModeTime(float time)
{
	std::cout << "[Mod] SetCurrentGameModeTime " << time << std::endl;

	auto gameMode = (*GameManager__TypeInfo)->static_fields->Instance->fields.gameMode;
	GameMode_SetGameModeTimer(gameMode, time, 0, NULL);
}

long long Mod::GetMySteamId()
{
	auto steamManager_c = (*u10A0u10A4u10A8u10A1u10A8u109Au10A8u10A1u109Eu1099u109F__TypeInfo);
	return steamManager_c->static_fields->Instance->fields._u109Du109Au10A3u10A6u10A0u10A8u1099u109Au109Du10A7u1099_k__BackingField.m_SteamID;
}

/*
Maybe offset is wrong?
.currentLobby returns the originalLobbyOwnerId
and .originalLobbyOwnerId returns 256  ??
*/
long long Mod::GetCurrentLobbyOwnerId()
{
	auto steamManager_c = (*u10A0u10A4u10A8u10A1u10A8u109Au10A8u10A1u109Eu1099u109F__TypeInfo);

	if (!steamManager_c) return 0;
	if (!steamManager_c->static_fields->Instance) return 0;

	return steamManager_c->static_fields->Instance->fields.currentLobby.m_SteamID;
}

bool Mod::IsInAnyLobby()
{
	return GetCurrentLobbyOwnerId() != 0;
}

bool Mod::IsLobbyOwner()
{
	return GetCurrentLobbyOwnerId() == GetMySteamId();
}

void Mod::ModBanPlayer(long long clientId)
{
	std::cout << "[Mod] ModBanPlayer clientId=" << clientId << std::endl;

	auto lobbyManager = (*LobbyManager__TypeInfo)->static_fields->Instance;

	HF_LobbyManager_BanPlayer->original(lobbyManager, clientId, NULL);
}

void Mod::KickPlayer(long long clientId)
{
	std::cout << "[Mod] KickPlayer clientId=" << clientId << std::endl;

	auto lobbyManager = (*LobbyManager__TypeInfo)->static_fields->Instance;

	LobbyManager_KickPlayer(lobbyManager, clientId, NULL);
}

void Mod::SendWinner(long long clientId, long long money)
{
	ServerSend_SendWinner(clientId, money, NULL);
}

void Mod::SendLocalInteract(int itemid)
{
	ClientSend_TryInteract(itemid, NULL);
}

void Mod::SetAllPlayersReady()
{
	auto gameManager = (*GameManager__TypeInfo)->static_fields->Instance;
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