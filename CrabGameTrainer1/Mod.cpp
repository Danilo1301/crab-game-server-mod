#include "Mod.h"
#include "Injector.h"
#include "Server.h"
#include "Command.h"
#include "VoteSystem.h"

uintptr_t Mod::m_AssemblyBase = 0;
uintptr_t Mod::m_CrabGameBase = 0;

DWORD WINAPI MainThread(LPVOID param) {
	Injector::Init();
	Server::Inject();
	Server::Init();

	MessageBox(NULL, L"INJECTED", L"INJECTED", NULL);

	bool running = true;
	while (running)
	{
		if (GetAsyncKeyState(VK_NUMPAD1)) {
			Sleep(1000);
		}

		if (GetAsyncKeyState(VK_NUMPAD2)) {
			Sleep(200);

		}
		if (GetAsyncKeyState(VK_NUMPAD0)) {
			//running = false;
			Sleep(200);

		}
		Sleep(10);
	}
	

	MessageBox(NULL, L"EXIT", L"EXIT", NULL);
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

static void SimulateProcessMessage(Player* player, std::string message) {
	Server::ProcessRawMessage(player->m_ClientId, message);
}

static void TestPermission() {
	Player* player = Server::AddPlayer(new Player(1, 416, 11111111111111, nullptr));
	player->AddPermission("admin");

	Player* player2 = Server::AddPlayer(new Player(2, 127, 2222222222222, nullptr));

	SimulateProcessMessage(player2, "!glock");
}



static void TestVoteGun() {
	Player* player = Server::AddPlayer(new Player(1, 416, 11111111111111, nullptr));
	player->AddPermission("admin");

	Player* player2 = Server::AddPlayer(new Player(2, 127, 2222222222222, nullptr));

	SimulateProcessMessage(player, "!votegun");

	Server::Update(250);
	Sleep(250);

	SimulateProcessMessage(player, "!votegun");

	VoteSystem::m_TimeLeft = 3000;

	SimulateProcessMessage(player, "!vote c");

	VoteSystem::RegisterVote(1, true);
	VoteSystem::RegisterVote(2, false);
	VoteSystem::RegisterVote(3, false);

	VoteSystem::RegisterVote(1, true);
	VoteSystem::RegisterVote(1, true);
	VoteSystem::RegisterVote(1, true);

	while (true)
	{
		Server::Update(250);
		Sleep(250);
	}
}

static void TestV() {
	Player* player2 = Server::AddPlayer(new Player(2, 416, 222222222, nullptr));
	Player* player3 = Server::AddPlayer(new Player(3, 416, 333333333, nullptr));

	Player* player = Server::AddPlayer(new Player(1, 416, 11111111111111, nullptr));
	player->AddPermission("admin");

	SimulateProcessMessage(player, "normal");
	SimulateProcessMessage(player, "!v");
	SimulateProcessMessage(player, "nao me ve");
	SimulateProcessMessage(player, "!bc bom dia night city");
	SimulateProcessMessage(player, "nem agr");
	SimulateProcessMessage(player, "!test");
	SimulateProcessMessage(player, "!v");
	SimulateProcessMessage(player, "me ve");
}



int main() {
	Server::Init();

	Server::m_IsAtLobby = true;

	TestV();


	return 1;
}