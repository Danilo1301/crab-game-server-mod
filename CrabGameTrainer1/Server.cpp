#include "Server.h"
#include "Injector.h"
#include "Command.h"
#include "ChatCommand.h"
#include "VoteSystem.h"

void* GameManager = nullptr;
void* SteamManager = nullptr;
void* LobbyManager = nullptr;
void* ChatBox = nullptr;



/*
[] add !y e !n

min 4 votos se tiver +8 pessoas
ready
[] comando pra ativa/desativa respawn e arma

mudar votegun pra um sistema melhor..
add votekick
talvez antiflood

adicionar !win
adicionar !map
adicionar !time

process needs to be after message sent

[nao tem como] resolver bug do activePlayers

nao mostrar comandos durante votacao

criar query pra enviar mensagem

criar class Message com player e content e canbedisplayed (de server e de player)

*/

//--------------------- ServerSend.StartGame  ----------------

typedef void(__stdcall* tServerSend_StartGame)();
tServerSend_StartGame oServerSend_StartGameTarget;

//---------------------------------------------------------------
//--------------------- ServerSend LoadMap ----------------

typedef void(__stdcall* tServerSend_LoadMap)(int32_t map, int32_t mode);
tServerSend_LoadMap oServerSend_LoadMapTarget;
tServerSend_LoadMap oServerSend_LoadMap;

void __stdcall hServerSend_LoadMap(int32_t map, int32_t mode)
{

	if (mode == 0) {

		//on enter lobby

		if (!Server::m_IsAtLobby) {

		}

		//Server::m_GunsEnabled = false;

		Server::m_IsAtLobby = true;

	}
	else {
		//join any normal map
		/*
		if (Server::m_NextRoundGunsEnabled) {
			Server::m_NextRoundGunsEnabled = false;
			Server::m_GunsEnabled = true;
		}
		*/

		//on leave lobby
		if (Server::m_IsAtLobby) {
			
		}

		Server::m_IsAtLobby = false;
	}

	oServerSend_LoadMap(map, mode);
}

//---------------------------------------------------------------
// //--------------------- ServerHandle TryInteract ----------------

____________457_o* _packetModel = nullptr;

typedef void(__stdcall* tServerHandle_TryInteract)(uint64_t fromClient, ____________457_o* packet);
tServerHandle_TryInteract oServerHandle_TryInteractTarget;
tServerHandle_TryInteract oServerHandle_TryInteract;

void __stdcall hServerHandle_TryInteract(uint64_t fromClient, ____________457_o* packet)
{
	/*
	std::string str = "";

	for (size_t i = 0; i < 100; i++) {
		byte b = packet->fields.readableBuffer->m_Items[i];

		str += std::to_string(b) + ", ";
	}

	char szTest[512];
	sprintf_s(szTest, "hServerHandle_TryInteract\nreadPos=%d\n%s\n%s", packet->fields.readPos, packet->fields.disposed ? "disposed" : "not-disposed", str.c_str());
	MessageBoxA(NULL, szTest, NULL, NULL);
	*/

	oServerHandle_TryInteract(fromClient, packet);
}

void TryInteract(int itemId) {
	void (*ClientSend__TryInteract)(int32_t itemId) = (void (*)(int32_t itemId))Mod::GetAssemblyOffset(11054624);

	ClientSend__TryInteract(itemId);
}

//---------------------------------------------------------------
//--------------------- ServerHandle GameRequestToSpawn ----------------

typedef void(__stdcall* tServerHandle_GameRequestToSpawn)(uint64_t fromClient, ____________457_o* packet);
tServerHandle_GameRequestToSpawn oServerHandle_GameRequestToSpawnTarget;
tServerHandle_GameRequestToSpawn oServerHandle_GameRequestToSpawn;

void __stdcall hServerHandle_GameRequestToSpawn(uint64_t fromClient, ____________457_o* packet)
{
	_packetModel = packet;

	std::string str = "";

	for (size_t i = 0; i < 100; i++) {
		byte b = packet->fields.readableBuffer->m_Items[i];

		str += std::to_string(b) + ", ";
	}
	
	/*
	char szTest[512];
	sprintf_s(szTest, "1 readPos=%d %s\n%s", packet->fields.readPos, packet->fields.disposed ? "disposed" : "not-disposed", str.c_str());
	MessageBoxA(NULL, szTest, NULL, NULL);
	*/

	oServerHandle_GameRequestToSpawn(fromClient, packet);
}

//---------------------------------------------------------------
//--------------------- gameManager.Update  ----------------

typedef void(__stdcall* tGameManager_Update)(void* _this);
tGameManager_Update oGameManager_UpdateTarget;
tGameManager_Update oGameManager_Update;

void __stdcall hGameManager_Update(void* _this)
{
	oGameManager_Update(_this);

	/*
	if (_this != nullptr) {
		GameManager = _this;

		if (Server::m_Players.size() > 0) {
			auto now = std::chrono::system_clock::now();

			std::chrono::duration<float, std::milli> diff = now - Server::m_LastUpdatedTime;
		}

		
	}
	*/
}

//--------------------- ChatBox Update ----------------

typedef void(__stdcall* tChatBox_Update)(void* _this);
tChatBox_Update oChatBox_UpdateTarget;
tChatBox_Update oChatBox_Update;

void __stdcall hChatBox_Update(void* _this)
{
	if (_this != nullptr) {
		ChatBox = _this;
	}

	auto now = std::chrono::system_clock::now();
	std::chrono::duration<float, std::milli> diff = now - Server::m_LastUpdatedTime;
	Server::Update(diff.count());
	Server::m_LastUpdatedTime = now;
	

	oChatBox_Update(_this);
}

//---------------------------------------------------------------

//---------------------------------------------------------------
// //--------------------- ServerSend GameSpawnPlayer ----------------

typedef void(__stdcall* tServerSend_GameSpawnPlayer)(uint64_t toClientId, uint64_t spawnedClientId, Vector3 spawnPos, int32_t param_3, bool streamerMode, void* byteArray, int32_t numberId);
tServerSend_GameSpawnPlayer oServerSend_GameSpawnPlayerTarget;
tServerSend_GameSpawnPlayer oServerSend_GameSpawnPlayer;

void __stdcall hServerSend_GameSpawnPlayer(uint64_t toClientId, uint64_t spawnedClientId, Vector3 spawnPos, int32_t param_3, bool streamerMode, void* byteArray, int32_t numberId)
{
	if (Server::HasPlayer(spawnedClientId)) {
		Player* player = Server::GetPlayer(spawnedClientId);
		player->m_NumberId = numberId;

		Server::ChangePlayerIsAliveState(player, true);
	}
	

	oServerSend_GameSpawnPlayer(toClientId, spawnedClientId, spawnPos, param_3, streamerMode, byteArray, numberId);
}

//---------------------------------------------------------------
//--------------------- ServerSend PlayerDied ----------------

typedef void(__stdcall* tServerSend_PlayerDied)(long long deadClient, long long damageDoerId, Vector3 damageDir);
tServerSend_PlayerDied oServerSend_PlayerDiedTarget;
tServerSend_PlayerDied oServerSend_PlayerDied;

void __stdcall hServerSend_PlayerDied(long long deadClient, long long damageDoerId, Vector3 damageDir)
{
	if (Server::HasPlayer(deadClient))
	{
		Player* deadPlayer = Server::GetPlayer(deadClient);
		Server::ChangePlayerIsAliveState(deadPlayer, false);


		if (deadClient == damageDoerId)
		{
			Server::SendServerMessage("Player " + deadPlayer->GetSelector() + " died");
		}
		else
		{
			if (Server::HasPlayer(damageDoerId)) {
				Player* killerPlayer = Server::GetPlayer(damageDoerId);

				Server::SendServerMessage("Player " + killerPlayer->GetSelector() + " killed " + deadPlayer->GetSelector());
			}
		}
	}

	oServerSend_PlayerDied(deadClient, damageDoerId, damageDir);
}

//---------------------------------------------------------------
//--------------------- ServerSend SendChatMessage ----------------

typedef void(__stdcall* tServerSend_SendChatMessage)(long long fromClient, monoString* string);
tServerSend_SendChatMessage oServerSend_SendChatMessageTarget;
tServerSend_SendChatMessage oServerSend_SendChatMessage;

void __stdcall hServerSend_SendChatMessage(long long toClient, monoString* string)
{
	Server::ProcessRawMessage(toClient, string->toCPPString());


	/*
	bool send = true;

	std::string text = string->toCPPString();

	if (Server::HasPlayer(toClient)) {
		Player* player = Server::GetPlayer(toClient);

		std::string newText = (player->m_IsAlive ? "" : "(dead) ") + player->GetDisplayName() + " " + text;
		

		if (player->m_PlayerId == 1) {

			if (Server::m_HideMyMessages) {
				Server::m_SkipCurrentMessage = true;

			}


		}

		if(!Server::m_SkipCurrentMessage)
			oServerSend_SendChatMessage(toClient, Mod::CreateMonoString(newText.c_str()));

		try {
			Server::ProcessMessage(player, text);

			
		}
		catch (...) {
			Server::SendServerMessage("An error ocurred");
		}

		if (player->m_PlayerId == 1) {
			Server::m_SkipCurrentMessage = false;
		}

		
	}
	*/

}

//---------------------------------------------------------------
//--------------------- GameServer.ForceGiveWeapon  ----------------

typedef void(__stdcall* tGameServer_ForceGiveWeapon)(uint64_t toClient, int32_t itemId, int32_t objectId, const void* method);
tGameServer_ForceGiveWeapon oGameServer_ForceGiveWeaponTarget;

//---------------------------------------------------------------
// //--------------------- ChatBox.AppendMessage  ----------------

typedef void(__stdcall* tChatBox_AppendMessage)(void* __this, uint64_t fromClient, monoString* message, monoString* username);
tChatBox_AppendMessage oChatBox_AppendMessageTarget;

//---------------------------------------------------------------
//--------------------- ServerSend.RespawnPlayer  ----------------

typedef void(__stdcall* tServerSend_RespawnPlayer)(uint64_t toClient, Vector3 spawnPos, const void* method);
tServerSend_RespawnPlayer oServerSend_RespawnPlayerTarget;

//---------------------------------------------------------------
//--------------------- playerManager.SetPlayer  ----------------

typedef void(__stdcall* tPlayerManager_SetPlayer)(void* _this, uint64_t steamId, int32_t numberId, bool streamerMode, const void* method);
tPlayerManager_SetPlayer oPlayerManager_SetPlayerTarget; //before
tPlayerManager_SetPlayer oPlayerManager_SetPlayer; //before

void __stdcall hPlayerManager_SetPlayer(____________452_o* playerManager, uint64_t steamId, int32_t playerId, bool streamerMode, const void* method)
{
	//uintptr_t ptr = *reinterpret_cast<uintptr_t*>(playerManager);

	uintptr_t ptr = reinterpret_cast<uintptr_t>(playerManager);

	int TplayerNumber = *reinterpret_cast<int*>(ptr + 0x94);

	oPlayerManager_SetPlayer(playerManager, steamId, playerId, streamerMode, method);



	int numberId = *(int*)((uint64_t)playerManager + 0x8C);
	int TTnumberId = *(int*)((uint64_t)playerManager + 0x94);

	//numberId = -999;

	//TTnumberId = (int)playerManager->fields.playerNumber;

	
	//char szTest[256];
	//sprintf_s(szTest, "hPlayerManager_SetPlayer\n playerManager = %llX | %llX : %p \n steamId=%lld numberId=%d streamerMode=%d playerId=%d \n\n pm->fields.playerNumber=%d", ptr, playerManager, playerManager, steamId, numberId, streamerMode, playerId, TTnumberId);
	//MessageBoxA(NULL, szTest, NULL, NULL);


	if (!Server::HasPlayer(steamId)) {
		Player* player = new Player(playerId, numberId, steamId, playerManager);

		monoString* string = (monoString*)playerManager->fields.username;
		player->m_Username = string->toCPPString();

		if (steamId == 76561198092596612 || playerId == 1) {
			player->AddPermission("admin");
		}

		Server::AddPlayer(player);
		

		//Server::SendServerMessage("player added");
	}

	Player* player = Server::GetPlayer(steamId);
	player->m_PlayerManager = playerManager;
	player->m_NumberId = numberId;
	Server::ChangePlayerIsAliveState(player, true);

	CrateBot::OnSpawnPlayer(player->m_ClientId);

	

	//Server::SendServerMessage("player manager set");
}

//---------------------------------------------------------------
//--------------------- steamManager.Update  ----------------

typedef void(__stdcall* tSteamManager_Update)(void* _this);
tSteamManager_Update oSteamManager_UpdateTarget;
tSteamManager_Update oSteamManager_Update;

void __stdcall hSteamManager_Update(void* _this)
{
	oSteamManager_Update(_this);

	if (_this != nullptr) {
		if (SteamManager == nullptr) {
		}
		SteamManager = _this;
	}
}

//---------------------------------------------------------------
//--------------------- lobbyManager.BanPlayer  ----------------

typedef void(__stdcall* tLobbyManager_BanPlayer)(void* _this, uint64_t steamId, const void* method);
tLobbyManager_BanPlayer oLobbyManager_BanPlayerTarget; //before
tLobbyManager_BanPlayer oLobbyManager_BanPlayer; //before

void __stdcall hLobbyManager_BanPlayer(void* _this, uint64_t steamId, int32_t playerId, bool streamerMode, const void* method)
{
	return;

	oLobbyManager_BanPlayer(_this, steamId, method);
}

//---------------------------------------------------------------
//--------------------- LobbyManager AddPlayerToLobby ----------------

typedef void(__stdcall* tLobbyManager_AddPlayerToLobby)(void* _this, void* CSteamID);
tLobbyManager_AddPlayerToLobby oLobbyManager_AddPlayerToLobbyTarget;
tLobbyManager_AddPlayerToLobby oLobbyManager_AddPlayerToLobby;

void __stdcall hLobbyManager_AddPlayerToLobby(void* _this, void* CSteamID)
{
	LobbyManager = _this;

	long long steamId = (long long)CSteamID;

	oLobbyManager_AddPlayerToLobby(_this, CSteamID);
}

//---------------------------------------------------------------
//--------------------- LobbyManager RemovePlayerFromLobby ----------------

typedef void(__stdcall* tLobbyManager_RemovePlayerFromLobby)(void* _this, void* CSteamID);
tLobbyManager_RemovePlayerFromLobby oLobbyManager_RemovePlayerFromLobbyTarget;
tLobbyManager_RemovePlayerFromLobby oLobbyManager_RemovePlayerFromLobby;

void __stdcall hLobbyManager_RemovePlayerFromLobby(void* _this, void* CSteamID)
{
	long long steamId = (long long)CSteamID;

	if (Server::HasPlayer(steamId)) {
		Server::m_Players.erase(steamId);
	}

	oLobbyManager_RemovePlayerFromLobby(_this, CSteamID);
}

//---------------------------------------------------------------

long long printTest = 1337;



std::map<std::string, int> m_Weapons = {
	{ "ak", 0 },
	{ "glock", 1 },
	{ "revolver", 2 },
	{ "dual", 3 },
	{ "bat", 4 },
	{ "bomb", 5 },
	{ "katana", 6 },
	{ "knife", 7 },
	{ "pipe", 8 },
	{ "snowball", 9 },
	{ "stick", 10 },
	{ "granada", 13 }
};


int Server::m_UniqueObjectId = 100;
bool Server::m_IsAtLobby = false;
bool Server::m_GunsEnabled = false;
bool Server::m_RespawnEnabled = false;
bool Server::m_SkipCurrentMessage = false;
bool Server::m_HideMyMessages = false;
float Server::m_BroadCastHelpTime = 0;
float Server::m_SendWeaponCommandTime = 0;
bool Server::m_NextRoundGunsEnabled = false;
std::chrono::system_clock::time_point Server::m_LastUpdatedTime = std::chrono::system_clock::now();
std::map<long long, Player*> Server::m_Players;
std::vector<Message*> Server::m_Messages;

bool Server::Inject() {
	
	oServerHandle_TryInteractTarget = (tServerHandle_TryInteract)Mod::GetAssemblyOffset(15470560);
	if (!Injector::Hook(reinterpret_cast<void**>(oServerHandle_TryInteractTarget), &hServerHandle_TryInteract, reinterpret_cast<void**>(&oServerHandle_TryInteract))) {
		return 0;
	}


	oServerHandle_GameRequestToSpawnTarget = (tServerHandle_GameRequestToSpawn)Mod::GetAssemblyOffset(15460240);
	if (!Injector::Hook(reinterpret_cast<void**>(oServerHandle_GameRequestToSpawnTarget), &hServerHandle_GameRequestToSpawn, reinterpret_cast<void**>(&oServerHandle_GameRequestToSpawn))) {
		return 0;
	}

	oChatBox_UpdateTarget = (tChatBox_Update)Mod::GetAssemblyOffset(18029056);
	if (!Injector::Hook(reinterpret_cast<void**>(oChatBox_UpdateTarget), &hChatBox_Update, reinterpret_cast<void**>(&oChatBox_Update))) {
		return 0;
	}

	oServerSend_LoadMapTarget = (tServerSend_LoadMap)Mod::GetAssemblyOffset(17184288);
	if (!Injector::Hook(reinterpret_cast<void**>(oServerSend_LoadMapTarget), &hServerSend_LoadMap, reinterpret_cast<void**>(&oServerSend_LoadMap))) {
		return 0;
	}

	oServerSend_SendChatMessageTarget = (tServerSend_SendChatMessage)Mod::GetAssemblyOffset(17192320);
	if (!Injector::Hook(reinterpret_cast<void**>(oServerSend_SendChatMessageTarget), &hServerSend_SendChatMessage, reinterpret_cast<void**>(&oServerSend_SendChatMessage))) {
		return 0;
	}

	oServerSend_PlayerDiedTarget = (tServerSend_PlayerDied)Mod::GetAssemblyOffset(17188880);
	if (!Injector::Hook(reinterpret_cast<void**>(oServerSend_PlayerDiedTarget), &hServerSend_PlayerDied, reinterpret_cast<void**>(&oServerSend_PlayerDied))) {
		return 0;
	}

	oServerSend_GameSpawnPlayerTarget = (tServerSend_GameSpawnPlayer)Mod::GetAssemblyOffset(17182624);
	if (!Injector::Hook(reinterpret_cast<void**>(oServerSend_GameSpawnPlayerTarget), &hServerSend_GameSpawnPlayer, reinterpret_cast<void**>(&oServerSend_GameSpawnPlayer))) {
		return 0;
	}

	oLobbyManager_BanPlayerTarget = (tLobbyManager_BanPlayer)Mod::GetAssemblyOffset(12101632);
	if (!Injector::Hook(reinterpret_cast<void**>(oLobbyManager_BanPlayerTarget), &hLobbyManager_BanPlayer, reinterpret_cast<void**>(&oLobbyManager_BanPlayer))) {
		return 0;
	}
	
	

	oSteamManager_UpdateTarget = (tSteamManager_Update)Mod::GetAssemblyOffset(16872224);
	if (!Injector::Hook(reinterpret_cast<void**>(oSteamManager_UpdateTarget), &hSteamManager_Update, reinterpret_cast<void**>(&oSteamManager_Update))) {
		return 0;
	}

	oGameManager_UpdateTarget = (tGameManager_Update)Mod::GetAssemblyOffset(2258864);
	if (!Injector::Hook(reinterpret_cast<void**>(oGameManager_UpdateTarget), &hGameManager_Update, reinterpret_cast<void**>(&oGameManager_Update))) {
		return 0;
	}



	oLobbyManager_AddPlayerToLobbyTarget = (tLobbyManager_AddPlayerToLobby)Mod::GetAssemblyOffset(12099808);
	if (!Injector::Hook(reinterpret_cast<void**>(oLobbyManager_AddPlayerToLobbyTarget), &hLobbyManager_AddPlayerToLobby, reinterpret_cast<void**>(&oLobbyManager_AddPlayerToLobby))) {
		return 0;
	}

	oLobbyManager_RemovePlayerFromLobbyTarget = (tLobbyManager_RemovePlayerFromLobby)Mod::GetAssemblyOffset(12104880);
	if (!Injector::Hook(reinterpret_cast<void**>(oLobbyManager_RemovePlayerFromLobbyTarget), &hLobbyManager_RemovePlayerFromLobby, reinterpret_cast<void**>(&oLobbyManager_RemovePlayerFromLobby))) {
		return 0;
	}

	oChatBox_AppendMessageTarget = (tChatBox_AppendMessage)Mod::GetAssemblyOffset(18008544);

	oGameServer_ForceGiveWeaponTarget = (tGameServer_ForceGiveWeapon)Mod::GetAssemblyOffset(12938880);

	oServerSend_RespawnPlayerTarget = (tServerSend_RespawnPlayer)Mod::GetAssemblyOffset(17191504);

	oServerSend_StartGameTarget = (tServerSend_StartGame)Mod::GetAssemblyOffset(17201904);

	
	oPlayerManager_SetPlayerTarget = (tPlayerManager_SetPlayer)Mod::GetAssemblyOffset(14453696);
	if (!Injector::Hook(reinterpret_cast<void**>(oPlayerManager_SetPlayerTarget), &hPlayerManager_SetPlayer, reinterpret_cast<void**>(&oPlayerManager_SetPlayer))) {
		return 0;
	}


	/*


	//____________540_c*
	uintptr_t ptr1 = Mod::GetAssemblyOffset(30569432); 

	//____________540_c
	uintptr_t ptr1_val = *reinterpret_cast<uintptr_t*>(ptr1);

	//static fields has 0xB8 offset from 540_c
	
	//static_fields*
	uintptr_t ptr2 = ptr1_val + 0xB8;

	//static_fields
	uintptr_t ptr2_val = *reinterpret_cast<uintptr_t*>(ptr2);

	//appid is 0x8 from static_fields
	long long gameAppId = *reinterpret_cast<long long*>(ptr2_val + 0x8);

	//void** instance_ptr = *reinterpret_cast<uintptr_t*>(ptr2_val + 0x0);

	char buffer[256];
	sprintf_s(buffer, "ptr1 %llX | ptr1_val %llX \n ptr2 %llX \n ptr2_val %lld \n gameAppId %lld", ptr1, ptr1_val, ptr2, ptr2_val, gameAppId);
	MessageBoxA(NULL, buffer, NULL, NULL);

	*/


	/*
	//____________435_c*
	uintptr_t ptr1 = Mod::GetAssemblyOffset(30570488);

	//____________435_c
	uintptr_t ptr1_val = *reinterpret_cast<uintptr_t*>(ptr1);

	//static fields has 0xB8 offset from 540_c

	//static_fields*
	uintptr_t ptr2 = ptr1_val + 0xB8;

	//static_fields
	uintptr_t ptr2_val = *reinterpret_cast<uintptr_t*>(ptr2);

	//lobbyPlayers is 0x8 from static_fields
	monoDictionary<long long*, void**>* lobbyPlayers = *(monoDictionary<long long*, void**> **)(ptr2_val + 0x8);

	char buffer[256];
	sprintf_s(buffer, "ptr1 %llX | ptr1_val %llX \n ptr2 %llX \n ptr2_val %lld \n    lobbyPlayers size %lld", ptr1, ptr1_val, ptr2, ptr2_val,   lobbyPlayers->getNumValues());
	MessageBoxA(NULL, buffer, NULL, NULL);
	*/


	//0xB8

	//0xB8
	//WHOA

	//void* p1 = *(void**)(Mod::GetAssemblyOffset(ptr1));

	//uintptr_t p1 = *(uintptr_t*)(Mod::GetAssemblyOffset(ptr1));

	
	/*
	uintptr_t t = Mod::GetAssemblyOffset(30569432) + 0x5c;

	void* instance = *(void**)(Mod::GetAssemblyOffset(30569432) + 0x5c);

	

	//testGameAppId = 316;

	uintptr_t appidptr = Mod::GetAssemblyOffset(30569432) + 0x5c + 0x8;

	char buffer[256];
	sprintf_s(buffer, "testGameAppId %I32d\nidptr %llX Instance %llX", testGameAppId, appidptr, t);
	MessageBoxA(NULL, buffer, NULL, NULL);
	*/


	/*
	-------------------------
	uintptr_t ptr1 = Mod::GetAssemblyOffset(30569432);
	uintptr_t ptr1_val = *reinterpret_cast<uintptr_t*>(ptr1);


	____________540_c* steamManager = reinterpret_cast<____________540_c*>(ptr1_val);

	long long gameAppId = (long long)steamManager->static_fields->gameAppId;

	char buffer[256];
	sprintf_s(buffer, "gameAppId %lld", gameAppId);
	MessageBoxA(NULL, buffer, NULL, NULL);
	----------------------------
	*/

	
	
	/*

	bool (*ContainsKey)(void* _this, uint64_t key) = (bool (*)(void* _this, uint64_t key))Mod::GetAssemblyOffset(9175920);

	bool result = ContainsKey(dictionary, 76561198092596612);

	char buffer[256];
	sprintf_s(buffer, "count %s", result ? "Y" : "N");
	MessageBoxA(NULL, buffer, NULL, NULL);
	*/

	return 1;
}


____________430_c* Server::GetGameManager() {
	uintptr_t ptr1 = Mod::GetAssemblyOffset(30566840);
	uintptr_t ptr1_val = *reinterpret_cast<uintptr_t*>(ptr1);

	____________430_c* gameManager = reinterpret_cast<____________430_c*>(ptr1_val);

	return gameManager;
}

void Server::SetAllReady() {
	auto activePlayers = GetActivePlayers();

	std::map<long long, ____________452_o*>::iterator it;
	for (it = activePlayers.begin(); it != activePlayers.end(); it++)
	{
		auto playerManager = it->second;

		playerManager->fields.waitingReady = true;
	}

	TryInteract(4);
	TryInteract(4);
}

std::map<long long, ____________452_o*> Server::GetActivePlayers() {

	std::map<long long, ____________452_o*> allActivePlayers;

	auto gameManager = Server::GetGameManager();
	auto activePlayers = gameManager->static_fields->Instance->fields.activePlayers;

	size_t n = 0;
	size_t i = 0;
	int count = activePlayers->fields.count;

	while (n < count)
	{
		auto pair = gameManager->static_fields->Instance->fields.activePlayers->fields.entries->m_Items[i];

		auto clientId = (uint64_t)pair.fields.key;
		auto playerManager = (____________452_o*)pair.fields.value;

		if (playerManager > 0) {
			n++;

			allActivePlayers.insert(std::pair<long long, ____________452_o*>(clientId, playerManager));
			
			/*
			char buffer[256];
			sprintf_s(buffer, "[%d] (%d / %d) %lld  playernumber=%d", (int)i, (int)n, count, clientId, playerManager->fields.playerNumber);
			MessageBoxA(NULL, buffer, NULL, NULL);
			*/
		}

		i++;
	}

	return allActivePlayers;
}

bool Server::IsPlayerAlive(long long id) {

	auto activePlayers = GetActivePlayers();

	std::map<long long, ____________452_o*>::iterator it;
	for (it = activePlayers.begin(); it != activePlayers.end(); it++)
	{
		if (it->first == id) return true;
	}

	return false;
}

void Server::Init() {

	CommandData* w = ChatCommand::AddCommand("w");
	//w->AddRequiredPermission("w.use");

	CommandData* respawn = ChatCommand::AddCommand("respawn");
	//CommandData* votegun = ChatCommand::AddCommand("votegun");
	CommandData* vote = ChatCommand::AddCommand("vote");
	CommandData* help = ChatCommand::AddCommand("help");
	CommandData* ready = ChatCommand::AddCommand("ready");
	//CommandData* armas = ChatCommand::AddCommand("armas");

	CommandData* t = ChatCommand::AddCommand("t");
	t->AddRequiredPermission("t.use");

	CommandData* bc = ChatCommand::AddCommand("bc");
	bc->AddRequiredPermission("bc.use");


	CommandData* cb = ChatCommand::AddCommand("cb");
	cb->AddRequiredPermission("cb.use");


	CommandData* r = ChatCommand::AddCommand("r");
	r->AddRequiredPermission("r.use");

	CommandData* v = ChatCommand::AddCommand("v");
	v->AddRequiredPermission("v.use");

	CommandData* ban = ChatCommand::AddCommand("ban");
	ban->AddRequiredPermission("ban.use");

	CommandData* tp = ChatCommand::AddCommand("tp");
	tp->AddRequiredPermission("tp.use");

	CommandData* kill = ChatCommand::AddCommand("kill");
	kill->AddRequiredPermission("kill.use");

	CommandData* test = ChatCommand::AddCommand("test");
	test->AddRequiredPermission("test.use");

	CommandData* padd = ChatCommand::AddCommand("padd");
	padd->AddRequiredPermission("padd.use");

	CommandData* time = ChatCommand::AddCommand("time");
	time->AddRequiredPermission("time.use");
}

void Server::Update(float dt) {
	std::cout << "Server.Update " << dt << "\n";

	CrateBot::Update(dt);


	//SendServerMessage("Update " + std::to_string(dt));

	m_SendWeaponCommandTime += dt;

	m_BroadCastHelpTime += dt;
	if (m_BroadCastHelpTime >= 50000) {
		m_BroadCastHelpTime = 0;

		SendServerMessage("Digite !help para ver os comandos");
	}

	
	std::map<long long, Player*>::iterator it;
	for (it = Server::m_Players.begin(); it != Server::m_Players.end(); it++)
	{
		Player* player = it->second;

		bool isAlive = IsPlayerAlive(player->m_ClientId);

		if (player->GetIsAlive() != isAlive) {
			Server::ChangePlayerIsAliveState(player, isAlive);
		}

	}
	

	VoteSystem::Update(dt);

	SendAllMessagesInQuery();
}

void Server::SendAllMessagesInQuery() {

	for (size_t i = 0; i < m_Messages.size(); i++)
	{
		Message* message = m_Messages[i];

		std::string content = message->m_Content;

		if(message->m_Player != NULL) {
			auto player = message->m_Player;

			char buffer[512];
			sprintf_s(buffer, "%s[%d] %s", player->m_IsAlive ? "" : "(dead) ", player->m_PlayerId, content.c_str());
			content = std::string(buffer);
		}

		std::cout << "[Message : " << (int)message->m_SendType << "] from=" << message->m_FromClient << ", content='" << content << "'\n";

		if (Mod::m_AssemblyBase == 0) {
			
		}
		else {
			//oChatBox_AppendMessageTarget(ChatBox, 0, Mod::CreateMonoString(std::to_string(m_HideMyMessages).c_str()), Mod::CreateMonoString("** Vanish"));

	
			if (message->m_SendType == MessageSendType::FORCE_PRIVATE) {

				SendLocalMessage("[PRIVATE]", content);
			}

			if (message->m_SendType == MessageSendType::NORMAL || message->m_SendType == MessageSendType::FORCE_SEND) {
				oServerSend_SendChatMessage(message->m_FromClient, Mod::CreateMonoString(content.c_str()));
			}

		}
	}

	m_Messages.clear();
	

}

void Server::ProcessRawMessage(long long fromClient, std::string text) {

	Message* message = new Message(fromClient, text);

	if (HasPlayer(fromClient)) {
		message->m_Player = Server::GetPlayer(fromClient);
	}

	m_Messages.push_back(message);

	if (message->m_Player != NULL) {
		try
		{
			ProcessMessage(message);
		}
		catch (...)
		{
			SendServerMessage("Error");
		}
	}

	if (message->m_Player != NULL) {
		if (message->m_Player->m_HideMyMessages) {
			for (size_t i = 0; i < m_Messages.size(); i++)
			{
				Message* message = m_Messages[i];

				if (message->m_SendType == MessageSendType::NORMAL) {
					message->m_SendType = MessageSendType::FORCE_PRIVATE;
				}
			}
		}
	}

	SendAllMessagesInQuery();
}

bool Server::ProcessMessage(Message* message) {
	Player* player = message->m_Player;
	std::string content = message->m_Content;

	char buffer[256];

	std::cout << "[ProcessMessage] from=" << player->m_ClientId << (player->GetIsAlive() ? "" : "[dead]") << ", content='" << content << "'\n";

	//SendServerMessage(buffer);

	if (content.rfind("!", 0) == 0) {
		Command command(content);
		
		if (command.Check("g1")) {
			long long originalLobbyOwnerId = *(long long*)((uint64_t)SteamManager + 0x48);
			sprintf_s(buffer, "originalLobbyOwnerId= %lld'", originalLobbyOwnerId);
			SendServerMessage(buffer);
		}

		if (command.Check("test1")) {
			auto activePlayers = GetActivePlayers();

			std::map<long long, ____________452_o*>::iterator it;
			for (it = activePlayers.begin(); it != activePlayers.end(); it++)
			{

				sprintf_s(buffer, "id= %lld'", it->first);
				SendServerMessage(buffer);
				
			}

		}

		if (command.Check("test2")) {
			TryInteract(4);
		}

		

		if (command.Check("ready")) {
			SetAllReady();

		}

		if (command.Check("g3")) {
			//monoDictionary<int*, void**>* activePlayers = *(monoDictionary<int*, void**> **)((uint64_t)GameManager + 0x18);

			//auto a = activePlayers->ge
		}

		if (command.Check("g2")) {
			SendServerMessage("g2");

			uint64_t gameModePtr = *(uint64_t*)((uint64_t)GameManager + 0x70);

			float modeTime = *(float*)(gameModePtr + 0x24);
			float totalRoundTime = *(float*)(gameModePtr + 0x30);

			char str[256];
			sprintf_s(str, "modeTime=%f, totalRoundTime=%f", modeTime, totalRoundTime);
			MessageBoxA(NULL, str, NULL, NULL);

		}

		if (command.Check("y")) {
			command = Command("!vote y");
		}

		if (command.Check("n")) {
			command = Command("!vote n");
		}

		bool isWeaponCommand = false;
		
		std::map<std::string, int>::iterator itw;
		for (itw = m_Weapons.begin(); itw != m_Weapons.end(); itw++)
		{
			if (command.Check(itw->first)) {

				isWeaponCommand = true;
				command = Command("!w " + std::to_string(itw->second));
				break;
			}
		}

		if (isWeaponCommand) {

			if (m_SendWeaponCommandTime < 4000) {
				message->m_SendType = MessageSendType::FORCE_HIDE;
			}
			else {
				m_SendWeaponCommandTime = 0;
			}

		}

		std::map<std::string, CommandData*>::iterator it;
		for (it = ChatCommand::m_Commands.begin(); it != ChatCommand::m_Commands.end(); it++)
		{
			std::string cmd = it->first;
			CommandData* cmdData = it->second;

			if (command.Check(cmd)) {

				int requiredCommands = (int)cmdData->m_RequiredPermissions.size();
				int playerMatchPerms = 0;
				bool isAdmin = false;

				for (size_t ii = 0; ii < player->m_Permissions.size(); ii++)
				{
					if (player->m_Permissions[ii].rfind("admin", 0) == 0) {
						isAdmin = true;
						break;
					}

					for (size_t i = 0; i < requiredCommands; i++)
					{
						if (cmdData->m_RequiredPermissions[i].rfind(player->m_Permissions[ii], 0) == 0) {
							playerMatchPerms++;
							break;
						}
					}
				}

				bool hasPermission = requiredCommands == playerMatchPerms;
				if (isAdmin) hasPermission = true;

				std::cout << "matches " << playerMatchPerms << "/" << requiredCommands << ", hasPermission=" << hasPermission << " (isadmin=" << isAdmin << ")\n";

				//SendServerMessage(std::string(cmd + " m_RequiredPermissions: " + std::to_string(cmdData.m_RequiredPermissions.size())));

				if (command.Check("t")) {
					if (!hasPermission) {
						return false;
					}

					if (command.HasArg(0)) {
						auto c = command.GetArgString(0);

						if (c.rfind("w", 0) == 0) {
							m_GunsEnabled = !m_GunsEnabled;
							SendLocalMessage("[TOGGLE]", "Weapons " + std::string(m_GunsEnabled ? "ENABLED" : "DISABLED"));
						}
						if (c.rfind("r", 0) == 0) {
							m_RespawnEnabled = !m_RespawnEnabled;
							SendLocalMessage("[TOGGLE]", "Respawn " + std::string(m_RespawnEnabled ? "ENABLED" : "DISABLED"));
						}
					}
				}

				if (command.Check("w")) {
					if (!hasPermission) {
						return false;
					}


					bool canUseThisCommand = true;

					if (!Server::m_IsAtLobby) {

						if (!Server::m_GunsEnabled) {
							canUseThisCommand = false;
						}
					}
					if (isAdmin) canUseThisCommand = true;

					if(!canUseThisCommand) {
						return false;
					}

					if (command.HasArg(0)) {
						if (command.HasArg(1)) {

							if (isAdmin) {
								std::string selector = command.GetArgString(0);
								int weaponId = command.GetArgInt(1);

								auto players = FindPlayers(selector);
								for (size_t i = 0; i < players.size(); i++)
								{
									auto targetPlayer = players[i];
									GiveWeapon(targetPlayer->m_ClientId, weaponId);
								}
							}

							

						}
						else {
							int weaponId = command.GetArgInt(0);
							GiveWeapon(player->m_ClientId, weaponId);
						}
					}
				}

				if (command.Check("v")) {

					if (isAdmin) {

						player->m_HideMyMessages = !player->m_HideMyMessages;
						
						message->m_Content = "Vanish " + std::string(player->m_HideMyMessages ? "ENABLED" : "DISABLED");
						message->m_SendType = MessageSendType::FORCE_PRIVATE;
					
					}
				}

				if (command.Check("ready")) {
					/*
					auto players = FindPlayers("*");
					for (size_t i = 0; i < players.size(); i++)
					{
						auto targetPlayer = players[i];

						SendServerMessage("before " + std::string(targetPlayer->GetIsReady() ? "ready" : "not ready"));
						targetPlayer->SetReady(true);
						SendServerMessage("after " + std::string(targetPlayer->GetIsReady() ? "ready" : "not ready"));

					}
					*/
				}

				if (command.Check("respawn")) {
					if (!hasPermission) {
						//SendServerMessage("no perms");
						return true;
					}

					std::string selector = player->GetSelector();

					if (isAdmin) {
						if (command.HasArg(0)) {
							selector = command.GetArgString(0);
						}
					}

					bool canUseThisCommand = true;
					if (!Server::m_IsAtLobby) {
						if (!Server::m_RespawnEnabled) canUseThisCommand = false;
					}
					if (isAdmin) canUseThisCommand = true;
					if (!canUseThisCommand) {
						return false;
					}

					auto players = FindPlayers(selector);
					for (size_t i = 0; i < players.size(); i++)
					{
						auto targetPlayer = players[i];
						RespawnPlayer(targetPlayer->m_ClientId, Vector3(0, 3.0f, 0));
					}

					
				}

				if (command.Check("test")) {
					if (!hasPermission) {
						//SendServerMessage("no perms");
						return true;
					}

					std::string selector = "*";

					if (command.HasArg(0)) {
						selector = command.GetArgString(0);
					}
					
					auto players = FindPlayers(selector);
					for (size_t i = 0; i < players.size(); i++)
					{
						auto targetPlayer = players[i];
						char str[256];
						sprintf_s(str, "%s | %s | %lld | %d pm |", targetPlayer->GetDisplayName().c_str(), targetPlayer->GetIsAlive() ? "alive" : "dead", targetPlayer->m_ClientId, (int)targetPlayer->m_Permissions.size());
						SendServerMessage(str);
					}
				}

				if (command.Check("time")) {
					if (!hasPermission) {
						return true;
					}

					if (!command.HasArg(0)) return true;

					float time = command.GetArgFloat(0);

					SetCurrentGameModeTime(time);
				}

				if (command.Check("padd")) {
					if (command.HasArg(1)) {
						auto selector = command.GetArgString(0);
						auto perm = command.GetArgString(1);

						auto players = FindPlayers(selector);
						for (size_t i = 0; i < players.size(); i++)
						{
							auto targetPlayer = players[i];
							targetPlayer->AddPermission(perm);
						}
					}
				}

				if (command.Check("bc")) {
					if (!hasPermission) {
						return true;
					}

					std::string text = command.GetArgText(0);

					message->m_SendType = MessageSendType::FORCE_PRIVATE;

					Message* msg = SendServerMessage(text);
					msg->m_SendType = MessageSendType::FORCE_SEND;

					return false;
				}

				if (command.Check("tp")) {

					if (!hasPermission) {
						//SendServerMessage("no perms");
						return true;
					}

					std::string selector = player->GetSelector();

					Vector3 position(0, 0, 0);

					if (command.HasArg(3)) {

						if (isAdmin) {

							selector = command.GetArgString(0);

							position.x = command.GetArgFloat(1);
							position.y = command.GetArgFloat(2);
							position.z = command.GetArgFloat(3);
						}
					}
					else {
						if (command.HasArg(2)) {

							position.x = command.GetArgFloat(0);
							position.y = command.GetArgFloat(1);
							position.z = command.GetArgFloat(2);
						}
					}
					

					auto players = FindPlayers(selector);
					for (size_t i = 0; i < players.size(); i++)
					{
						auto targetPlayer = players[i];
						RespawnPlayer(targetPlayer->m_ClientId, position);
					}
				}

				if (command.Check("ban")) {
					if (!hasPermission) {
						//SendServerMessage("no perms");
						return true;
					}

					if (command.HasArg(0)) {
						auto selector = command.GetArgString(0);

						auto players = FindPlayers(selector);
						for (size_t i = 0; i < players.size(); i++)
						{
							auto targetPlayer = players[i];
							BanPlayer(targetPlayer->m_ClientId);
						}
					}
				}

				if (command.Check("kill")) {
					if (!hasPermission) {
						//SendServerMessage("no perms");
						return true;
					}

					if (command.HasArg(0)) {
						auto selector = command.GetArgString(0);

						auto players = FindPlayers(selector);
						for (size_t i = 0; i < players.size(); i++)
						{
							auto targetPlayer = players[i];
							KillPlayer(targetPlayer->m_ClientId);
						}
					}
				}

			
				if (command.Check("r")) {
					if (!hasPermission) {
						return true;
					}

					oServerSend_StartGameTarget();
				}

				if (command.Check("cb")) {
					if (!hasPermission) {
						return true;
					}

					CrateBot::m_Enabled = !CrateBot::m_Enabled;
				}

				if (command.Check("armas")) {
				}

				if (command.Check("help")) {
					SendServerMessage("!ak !glock !revolver !dual !bat");
					SendServerMessage("!bomb !katana !knife !pipe !stick !granada");
				}

				if (command.Check("votegun")) {


					if (Server::m_NextRoundGunsEnabled) {
						SendServerMessage("Ja esta ativado");
						return true;
					}

					if (VoteSystem::IsVotingOnGoing()) {
						SendServerMessage("Votacao em andamento!");
					}
					else {
						SendServerMessage("Ativar armas/respawn na proxima partida? !vote y (x votos) | !vote n (x votos)");

						VoteSystem::StartVoting("Ativar armas/respawn na proxima partida?", [] () {
							SendServerMessage(VoteSystem::m_FinalMessage);
							Server::m_NextRoundGunsEnabled = true;
						}, []() {
							SendServerMessage(VoteSystem::m_FinalMessage);
						});
					}

				}

				if (command.Check("vote")) {
					
					if (command.HasArg(0)) {
						auto voteStr = command.GetArgString(0);
						int vote = -1;

						std::cout << voteStr << voteStr.rfind("y", 0) << "\n";

						if (voteStr.rfind("y", 0) == 0) vote = 1;
						if (voteStr.rfind("n", 0) == 0) vote = 0;

						if (!VoteSystem::IsVotingOnGoing()) {
							SendServerMessage("Nenhuma votacao em andamento!");
						}
						else {

							if (vote != -1) {

								if (VoteSystem::RegisterVote(player->m_ClientId, vote)) {
									
									int votes = (int)VoteSystem::m_Votes.size();
									SendServerMessage("Votos: " + std::to_string(votes));
								}
								else {

								}
							}
						}
					}
				}
			}
		}

	
		return true;
	}

	return true;
}



void Server::GiveWeapon(long long toClient, int weaponId) {
	std::cout << "GiveWeapon " << toClient << ", " << weaponId << "\n";
	if (Mod::m_AssemblyBase == 0) return;
	oGameServer_ForceGiveWeaponTarget(toClient, weaponId, m_UniqueObjectId++, NULL);
}

void Server::BanPlayer(long long clientId) {
	std::cout << "BanPlayer " << clientId << "\n";
	if (Mod::m_AssemblyBase == 0) return;
	oLobbyManager_BanPlayer(LobbyManager, clientId, NULL);
}


void Server::KillPlayer(long long clientId) {
	std::cout << "KillPlayer " << clientId << "\n";
	if (Mod::m_AssemblyBase == 0) return;

	//GameManager . PlayerDied
	//void (*PlayerDied)(void* _this, uint64_t playerDiedId, uint64_t damageDoerId, Vector3 dir) = (void (*)(void* _this, uint64_t playerDiedId, uint64_t damageDoerId, Vector3 dir))Mod::GetAssemblyOffset(12234800);

	oServerSend_PlayerDied(clientId, clientId, Vector3(0, 1, 0));
}

void Server::SetCurrentGameModeTime(float time) {
	auto gameMode = GetGameManager()->static_fields->Instance->fields.gameMode;


	void (*GameMode__SetGameModeTimer)(GameMode_o * _this, float time, uint64_t param_2) = (void (*)(GameMode_o * _this, float time, uint64_t param_2))Mod::GetAssemblyOffset(19584848);

	GameMode__SetGameModeTimer(gameMode, time, 0);
}

void Server::RespawnPlayer(long long clientId, Vector3 spawnPos) {
	std::cout << "RespawnPlayer " << clientId << "\n";
	if (Mod::m_AssemblyBase == 0) return;
	oServerSend_RespawnPlayerTarget(clientId, spawnPos, NULL);
}

void Server::SendLocalMessage(std::string tag, std::string text) {
	if (Mod::m_AssemblyBase == 0) return;
	if (ChatBox == nullptr) return;
	oChatBox_AppendMessageTarget(ChatBox, 0, Mod::CreateMonoString(text.c_str()), Mod::CreateMonoString(tag.c_str()));
}

Message* Server::SendServerMessage(std::string text) {
	Message* message = new Message((long long)1, text);

	m_Messages.push_back(message);

	return message;

	//std::cout << "(Server: " << message << ")\n";

	/*
	if (Server::m_SkipCurrentMessage) {
		oChatBox_AppendMessageTarget(ChatBox, 0, Mod::CreateMonoString(message.c_str()), Mod::CreateMonoString("** Private"));
		return;
	}
	*/

}

bool Server::HasPlayer(long long clientId) {
	return m_Players.find(clientId) != m_Players.end();
}

Player* Server::AddPlayer(Player* player) {
	m_Players.insert(std::pair<long long, Player*>(player->m_ClientId, player));
	return player;
}


Player* Server::GetPlayer(long long clientId) {
	return m_Players.at(clientId);
}

std::vector<Player*> Server::FindPlayers(std::string selector, bool isAlive)
{
	std::vector<Player*> players;

	std::map<long long, Player*>::iterator it;
	for (it = m_Players.begin(); it != m_Players.end(); it++)
	{
		Player* player = it->second;

		if (isAlive)
		{
			if (!player->GetIsAlive()) continue;
		}

		if (selector == "*")
		{
			players.push_back(player);
			continue;
		}

		if (selector.rfind("#", 0) == 0)
		{
			std::string idstr;
			std::remove_copy(selector.begin(), selector.end(), std::back_inserter(idstr), '#');

			int id = std::atoi(idstr.c_str());

			if (player->m_PlayerId == id)
			{
				players.push_back(player);
			}

			continue;
		}
	}

	return players;
}



void Server::ChangePlayerIsAliveState(Player* player, bool isAlive) {
	if (player->m_IsAlive == isAlive) return;
	player->m_IsAlive = isAlive;

	if (isAlive) {
		//SendServerMessage("Player spawned");
		return;
	}

	player->m_PlayerManager = nullptr;
	//SendServerMessage("Player died");
}