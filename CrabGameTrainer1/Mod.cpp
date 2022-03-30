#include "Mod.h"
#include "Tests.h"
#include "SocketServer.h"

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

void* LobbyManager;


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
			ServerSend_PunchPlayer->original(a, a, Vector3(0, 3, 0));
		}

		if (player->m_SuperPunchEnabled) {
			ServerSend_PunchPlayer->original(a, b, Vector3(0, 4, 0));
		}
	}

	if (Server::HasPlayer(b)) {
		if (Server::GetPlayer(b)->m_ForceFieldEnabled) {
			Vector3 newDir = Vector3(dir.x * -3, dir.y * -3, dir.z * -3);

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



	if(canBan) LobbyManager_BanPlayer->original(_this, steamId, method);
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

	LobbyManager = _this;

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

auto ChatBox_Update = new HookFunction<void*>(15689360);
void Template_ChatBox_Update(void* _this)
{

	auto now = std::chrono::system_clock::now();
	std::chrono::duration<float, std::milli> diff = now - Server::m_LastUpdatedTime;
	Server::Update(diff.count());
	Server::m_LastUpdatedTime = now;

	ChatBox_Update->original(_this);
}


auto ClientHandle_UseItem = new HookFunction<void*, void*>(13938432);
void Template_ClientHandle_UseItem(____________470_o* packet, void* method)
{
	std::cout << "use item" << std::endl;
	std::cout << packet->fields._1____________->bounds->length << std::endl;
	std::cout << packet->fields._2____________ << std::endl;
	std::cout << (packet->fields._3____________ ? "Y" : "N") << std::endl;

	ClientHandle_UseItem->original(packet, method);
}

//-------------------------------------------------



//-------------------------------------------------

auto ServerHandle_TryInteract = new HookFunction<uint64_t, Packet*>(12506752);
void Template_ServerHandle_TryInteract(uint64_t fromClient, Packet* packet)
{
	/*
	char buffer[256];
	sprintf_s(buffer, "Interact from= %lld", fromClient);
	Mod::SendChatMessage(1, buffer);
	*/

	ServerHandle_TryInteract->original(fromClient, packet);
}

//-------------------------------------------------



//-------------------------------------------------

auto PlayerManager_SetPlayer = new HookFunction<PlayerManager*, uint64_t, int32_t, bool, const void*>(15599840);
void Template_PlayerManager_SetPlayer(PlayerManager* playerManager, uint64_t steamId, int32_t playerId, bool streamerMode, const void* method)
{
	PlayerManager_SetPlayer->original(playerManager, steamId, playerId, streamerMode, method);

	Server::TryAddPlayer(steamId, playerId, playerManager);
}

//-------------------------------------------------



//-------------------------------------------------


void Mod::SendChatMessage(long long fromClient, std::string message) {
	std::cout << "[ChatMessage] fromClient=" << fromClient << "', message='" << message << "'\n";

	if (Injector::m_AssemblyBase == 0) return;

	ServerSend_SendChatMessage->original(fromClient, Mod::CreateMonoString(message.c_str()));
}

void Mod::AppendLocalChatMessage(long long fromClient, std::string username, std::string message) {
	std::cout << "[LocalChatMessage] fromClient=" << fromClient << ", username='" << username << "', message='" << message << "'\n";

	if (Injector::m_AssemblyBase == 0) return;

	ChatBox_AppendMessage->original(GetChatBox()->static_fields->Instance, fromClient, CreateMonoString(message.c_str()), CreateMonoString(username.c_str()));
}

void Mod::SendDropItem(long long toClient, int objectId, int itemId, int ammo) {
	std::cout << "[Mod::SendDropItem] toClient=" << toClient << ", objectId='" << objectId << "', itemId='" << itemId << "', ammo='" << ammo << "'\n";

	if (Injector::m_AssemblyBase == 0) return;


	void (*ForceGiveItem)(uint64_t clientId, int32_t int1, int32_t int2) = (void (*)(uint64_t clientId, int32_t int1, int32_t int2))(Injector::m_AssemblyBase + 19768080);
	ForceGiveItem(toClient, objectId, itemId);

	

	//void (*DropItem)(uint64_t clientId, int32_t int1, int32_t int2, int32_t int3) = (void (*)(uint64_t clientId, int32_t int1, int32_t int2, int32_t int3))(Injector::m_AssemblyBase + 19767472);
	//DropItem(toClient, objectId, itemId, ammo);
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
	if (Injector::m_AssemblyBase == 0) return;

	ServerSend_PlayerDied->original(clientId, clientId, Vector3(0, 1, 0));
}


void Mod::BanPlayer(long long clientId) {
	if (Injector::m_AssemblyBase == 0) return;

	LobbyManager_BanPlayer->original(LobbyManager, clientId, NULL);
}

void Mod::RespawnPlayer(long long clientId, Vector3 position) {
	if (Injector::m_AssemblyBase == 0) return;

	/*
	char str[256];
	sprintf_s(str, "at %.3f, %.3f, %.3f", position.x, position.y, position.z);
	Mod::AppendLocalChatMessage(2, "RESPAWN", str);
	*/

	void (*Respawn)(uint64_t, Vector3, const void*) = (void (*)(uint64_t toClient, Vector3 spawnPos, const void* method))(Injector::m_AssemblyBase + 19778288);
	Respawn(clientId, position, NULL);
}

void Mod::RestartGame() {
	if (Injector::m_AssemblyBase == 0) return;

	void (*Restart)() = (void (*)())(Injector::m_AssemblyBase + 19788976);
	Restart();
}

void Mod::SetCurrentGameModeTime(float time) {
	auto gameMode = GetGameManager()->static_fields->Instance->fields.gameMode;

	void (*GameMode__SetGameModeTimer)(GameMode_o * _this, float time, uint64_t param_2) = (void (*)(GameMode_o * _this, float time, uint64_t param_2))(Injector::m_AssemblyBase + 17156720);

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

//ChatBox_AppendMessage->original(_this, fromClient, message, username);

GameManager_c* Mod::GetGameManager() {
	uintptr_t ptr1 = Injector::m_AssemblyBase + 30962952;
	uintptr_t ptr1_val = *reinterpret_cast<uintptr_t*>(ptr1);
	GameManager_c* c = reinterpret_cast<GameManager_c*>(ptr1_val);

	return c;
}

SteamManager_c* Mod::GetSteamManager() {
	uintptr_t ptr1 = Injector::m_AssemblyBase + 30961704;
	uintptr_t ptr1_val = *reinterpret_cast<uintptr_t*>(ptr1);
	SteamManager_c* c = reinterpret_cast<SteamManager_c*>(ptr1_val);
	return c;
}

ChatBox_c* Mod::GetChatBox() {
	uintptr_t ptr1 = Injector::m_AssemblyBase + 30956328;
	uintptr_t ptr1_val = *reinterpret_cast<uintptr_t*>(ptr1);
	ChatBox_c* c = reinterpret_cast<ChatBox_c*>(ptr1_val);
	return c;
}

int main() {
	//SocketServer::Connect();

	Server::Init();

	Chat::SendHelpMessage(0);
	Chat::SendHelpMessage(1);
	Chat::SendHelpMessage(2);
	Chat::SendHelpMessage(3);


	std::cout << ("exit") << std::endl;

	Tests::Test2();
	//

	//Server::Init();

	//Tests::Test1();

	return 1;
}

DWORD WINAPI MainThread(LPVOID param) {
	//MessageBox(NULL, L"MainThread", L"MainThread", NULL);

	Injector::Init();

	ServerSend_GameSpawnPlayer->SetTemplate(&Template_ServerSend_GameSpawnPlayer);
	Injector::Inject(ServerSend_GameSpawnPlayer);

	PlayerManager_SetPlayer->SetTemplate(&Template_PlayerManager_SetPlayer);
	Injector::Inject(PlayerManager_SetPlayer);

	ServerSend_SendChatMessage->SetTemplate(&Template_ServerSend_SendChatMessage);
	Injector::Inject(ServerSend_SendChatMessage);
	

	ServerHandle_TryInteract->SetTemplate(&Template_ServerHandle_TryInteract);
	Injector::Inject(ServerHandle_TryInteract);

	LobbyManager_AddPlayerToLobby->SetTemplate(&Template_LobbyManager_AddPlayerToLobby);
	Injector::Inject(LobbyManager_AddPlayerToLobby);

	LobbyManager_RemovePlayerFromLobby->SetTemplate(&Template_LobbyManager_RemovePlayerFromLobby);
	Injector::Inject(LobbyManager_RemovePlayerFromLobby);


	ChatBox_AppendMessage->SetTemplate(&Template_ChatBox_AppendMessage);
	Injector::Inject(ChatBox_AppendMessage);



	ClientHandle_UseItem->SetTemplate(&Template_ClientHandle_UseItem);
	Injector::Inject(ClientHandle_UseItem);



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

	bool running = true;
	while (running)
	{
		if (GetAsyncKeyState(VK_NUMPAD0)) {
			//running = false;
			Sleep(200);
		}
		Sleep(10);
	}
	
	FreeLibraryAndExitThread((HMODULE)param, 0);
	return 1;
}

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(NULL, NULL, MainThread, hModule, NULL, NULL);
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}