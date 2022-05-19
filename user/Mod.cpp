#include "pch-il2cpp.h"
#include "Mod.h"

#include "Injector.h"
#include "SocketServer.h"
#include "templates.h"

std::string Mod::m_Version = "1.3";

void Mod::Init() {
	std::cout << "[Mod] Init v" << m_Version << std::endl;

	Injector::Init();

	ServerSend_GameSpawnPlayer->SetTemplate(&Template_ServerSend_GameSpawnPlayer);
	Injector::Inject(ServerSend_GameSpawnPlayer);

	PlayerManager_SetPlayer->SetTemplate(&Template_PlayerManager_SetPlayer);
	Injector::Inject(PlayerManager_SetPlayer);

	ServerSend_SendChatMessage->SetTemplate(&Template_ServerSend_SendChatMessage);
	Injector::Inject(ServerSend_SendChatMessage);

	/*
	ServerHandle_TryInteract->SetTemplate(&Template_ServerHandle_TryInteract);
	Injector::Inject(ServerHandle_TryInteract);
	*/

	LobbyManager_AddPlayerToLobby->SetTemplate(&Template_LobbyManager_AddPlayerToLobby);
	Injector::Inject(LobbyManager_AddPlayerToLobby);

	LobbyManager_RemovePlayerFromLobby->SetTemplate(&Template_LobbyManager_RemovePlayerFromLobby);
	Injector::Inject(LobbyManager_RemovePlayerFromLobby);

	ChatBox_AppendMessage->SetTemplate(&Template_ChatBox_AppendMessage);
	Injector::Inject(ChatBox_AppendMessage);

	ChatBox_Update->SetTemplate(&Template_ChatBox_Update);
	Injector::Inject(ChatBox_Update);

	ServerSend_PunchPlayer->SetTemplate(&Template_ServerSend_PunchPlayer);
	Injector::Inject(ServerSend_PunchPlayer);

	LobbyManager_BanPlayer->SetTemplate(&Template_LobbyManager_BanPlayer);
	Injector::Inject(LobbyManager_BanPlayer);

	ServerSend_PlayerDied->SetTemplate(&Template_ServerSend_PlayerDied);
	Injector::Inject(ServerSend_PlayerDied);

	ServerSend_LoadMap->SetTemplate(&Template_ServerSend_LoadMap);
	Injector::Inject(ServerSend_LoadMap);

	Server::Init();

	SocketServer::Connect();
}

void Mod::SendChatMessage(long long fromClient, std::string message) {
	//std::cout << "[Mod] SendChatMessage " << "(" << fromClient << "): '" << message << "'" << std::endl;

	ServerSend_SendChatMessage->original(fromClient, Mod::CreateMonoString(message.c_str()));
}

void Mod::AppendLocalChatMessage(long long fromClient, std::string username, std::string message) {
	//std::cout << "[Mod] AppendLocalChatMessage " << username << "(" << fromClient << "): '" << message << "'" << std::endl;

	ChatBox_AppendMessage->original(GetChatBox()->static_fields->Instance, fromClient, CreateMonoString(message.c_str()), CreateMonoString(username.c_str()));
}

void Mod::SendDropItem(long long toClient, int objectId, int itemId, int ammo) {
	std::cout << "[Mod] SendDropItem toClient=" << toClient << ", objectId='" << objectId << "', itemId='" << itemId << "', ammo='" << ammo << "'" << std::endl;

	void (*DropItem)(uint64_t clientId, int32_t int1, int32_t int2, int32_t int3) = (void (*)(uint64_t clientId, int32_t int1, int32_t int2, int32_t int3))(Injector::m_AssemblyBase + 19767472);
	DropItem(toClient, objectId, itemId, ammo);
}

void Mod::ForceGiveItem(long long toClient, int objectId, int itemId) {
	std::cout << "[Mod] ForceGiveItem toClient=" << toClient << ", objectId='" << objectId << "', itemId='" << itemId << "'" << std::endl;

	void (*ForceGiveItem)(uint64_t clientId, int32_t int1, int32_t int2) = (void (*)(uint64_t clientId, int32_t int1, int32_t int2))(Injector::m_AssemblyBase + 19768080);
	ForceGiveItem(toClient, objectId, itemId);
}

void Mod::SendLocalInteract(int itemid) {
	void (*TryInteract)(int32_t itemId) = (void (*)(int32_t itemId))(Injector::m_AssemblyBase + 19285136);
	TryInteract(itemid);
}

void Mod::SendInteract(long long clientId, int itemid) {
	void (*TryInteract)(uint64_t clientId, int32_t itemId) = (void (*)(uint64_t clientId, int32_t itemId))(Injector::m_AssemblyBase + 19285136);
	TryInteract(clientId, itemid);
}

void Mod::KillPlayer(long long clientId) {
	std::cout << "[Mod] KillPlayer clientId=" << clientId << std::endl;

	ServerSend_PlayerDied->original(clientId, clientId, Vector3({ 0, 1, 0 }));
}

void Mod::BanPlayer(long long clientId) {
	std::cout << "[Mod] BanPlayer clientId=" << clientId << std::endl;

	auto lobbyManager = (*u109Bu10A2u10A4u10A6u109Du10A3u109Cu1099u109Du109Cu10A4__TypeInfo)->static_fields->Instance;

	u109Bu10A2u10A4u10A6u109Du10A3u109Cu1099u109Du109Cu10A4_BanPlayer(lobbyManager, clientId, NULL);
}

void Mod::KickPlayer(long long clientId) {
	std::cout << "[Mod] KickPlayer clientId=" << clientId << std::endl;

	auto lobbyManager = (*u109Bu10A2u10A4u10A6u109Du10A3u109Cu1099u109Du109Cu10A4__TypeInfo)->static_fields->Instance;

	u109Bu10A2u10A4u10A6u109Du10A3u109Cu1099u109Du109Cu10A4_KickPlayer(lobbyManager, clientId, NULL);
}

void Mod::RespawnPlayer(long long clientId, Vector3 position) {
	std::cout << "[Mod] RespawnPlayer clientId=" << clientId << Mod::FormatVector(position) << std::endl;

	void (*Respawn)(uint64_t, Vector3, const void*) = (void (*)(uint64_t toClient, Vector3 spawnPos, const void* method))(Injector::m_AssemblyBase + 19778288);
	Respawn(clientId, position, NULL);
}

void Mod::RestartGame() {
	std::cout << "[Mod] RestartGame" << std::endl;

	void (*Restart)() = (void (*)())(Injector::m_AssemblyBase + 19788976);
	Restart();
}

void Mod::SetCurrentGameModeTime(float time) {
	auto gameMode = GetGameManager()->static_fields->Instance->fields.gameMode;

	void (*GameMode__SetGameModeTimer)(void* _this, float time, uint64_t param_2) = (void (*)(void* _this, float time, uint64_t param_2))(Injector::m_AssemblyBase + 17156720);

	GameMode__SetGameModeTimer(gameMode, time, 0);
}

void Mod::SetBomber(long long clientId) {
	void (*Fn)(uint64_t param1, uint64_t param2) = (void (*)(uint64_t, uint64_t))(Injector::m_AssemblyBase + 19787040);
	Fn(clientId, clientId);
	Fn(clientId, 0);
}

void Mod::TagPlayer(long long clientId) {
	void (*Fn)(uint64_t param1, uint64_t param2) = (void (*)(uint64_t, uint64_t))(Injector::m_AssemblyBase + 19790432);
	Fn(clientId, clientId);
}

void Mod::ToggleLights(bool on) {
	void (*Fn)(bool param1) = (void (*)(bool))(Injector::m_AssemblyBase + 19790688);
	Fn(on);
}

void Mod::GiveHat(long long clientId) {
	void (*Fn)(uint64_t param1, uint64_t param2) = (void (*)(uint64_t, uint64_t))(Injector::m_AssemblyBase + 19770272);
	Fn(clientId, clientId);
}

void Mod::SendWinner(long long clientId, long long money) {
	void (*Fn)(uint64_t param1, uint64_t param2) = (void (*)(uint64_t, uint64_t))(Injector::m_AssemblyBase + 19786784);
	Fn(clientId, money);
}

u10A1u10A0u10A1u109Eu10A5u10A1u109Du10A8u10A5u1099u109A__Class* Mod::GetGameManager() {
	return (*u10A1u10A0u10A1u109Eu10A5u10A1u109Du10A8u10A5u1099u109A__TypeInfo);
}

u10A0u10A4u10A8u10A1u10A8u109Au10A8u10A1u109Eu1099u109F__Class* Mod::GetSteamManager() {
	return (*u10A0u10A4u10A8u10A1u10A8u109Au10A8u10A1u109Eu1099u109F__TypeInfo);
}

u109Du10A6u109Eu10A3u10A7u10A2u10A3u10A8u10A8u109Eu10A1__Class* Mod::GetChatBox() {
	return (*u109Du10A6u109Eu10A3u10A7u10A2u10A3u10A8u10A8u109Eu10A1__TypeInfo);
}
