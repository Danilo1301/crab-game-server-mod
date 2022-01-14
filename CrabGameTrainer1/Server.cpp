#include "Server.h"
#include "Mod.h"
#include "Chat.h"
#include "Commands.h"

std::map<long long, Player*> Server::m_Players;
std::chrono::system_clock::time_point Server::m_LastUpdatedTime;
int Server::m_UniqueObjectId = 100;
float Server::m_BroadCastHelpTime = 0;
bool Server::m_LightState = false;
Player* Server::m_LobbyOwner = nullptr;	
Vector3 Server::m_SpawnPosition = Vector3(0, 5, 0);
bool Server::m_CanUpdateSpawnPosition = true;

std::map<std::string, int> Server::m_WeaponList = {
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
	{ "milk", 11 },
	{ "pizza", 12 },
	{ "granada", 13 }
};

void Server::OnPlayerAddedToLobby(long long clientId) {

}

void Server::OnPlayerRemovedFromLobby(long long clientId) {
	if (Server::HasPlayer(clientId)) {
		Server::m_Players.erase(clientId);
	}
}

bool Server::OnPlayerAttemptBanned(long long clientId) {
	return false;
}

void Server::TryAddPlayer(long long clientId, int playerId, PlayerManager* playerManager) {
	if (!HasPlayer(clientId)) {
		Player* player = new Player(clientId, playerId);

		auto username = (monoString*)playerManager->fields.username;
		player->m_Username = username->toCPPString();

		Server::AddPlayer(player);
	}
}

bool Server::HasPlayer(long long clientId) {
	return m_Players.find(clientId) != m_Players.end();
}

Player* Server::AddPlayer(Player* player) {
	m_Players.insert(std::pair<long long, Player*>(player->m_ClientId, player));
	if (player->m_PlayerId == 1) m_LobbyOwner = player;
	return player;
}

Player* Server::GetPlayer(long long clientId) {
	return m_Players.at(clientId);
}

void Server::Init() {
	std::cout << "[Server::Init]\n";

	Commands::RegisterCommand("r", "r.use");
	Commands::RegisterCommand("v", "v.use");
	Commands::RegisterCommand("bc", "bc.use");
	Commands::RegisterCommand("test", "test.use");
	Commands::RegisterCommand("ctest", "ctest.use");
	Commands::RegisterCommand("perm", "perm.use");
	Commands::RegisterCommand("cperm", "cperm.use");
	Commands::RegisterCommand("ban", "ban.use");
	Commands::RegisterCommand("kill", "kill.use");
	Commands::RegisterCommand("time", "time.use");
	Commands::RegisterCommand("mute", "mute.use");
	Commands::RegisterCommand("god", "god.use");
	Commands::RegisterCommand("tp", "tp.use");
	Commands::RegisterCommand("respawndead", "respawndead.use");
	Commands::RegisterCommand("ctoggle", "ctoggle.use");

	Commands::RegisterCommand("test1", "");
	Commands::RegisterCommand("w", "");
	Commands::RegisterCommand("help", "");
	Commands::RegisterCommand("respawn", "");
	Commands::RegisterCommand("jumppunch", "");
	Commands::RegisterCommand("superpunch", "");
	Commands::RegisterCommand("forcefield", "");
	Commands::RegisterCommand("rconadmin", "");

	Commands::RegisterCommand("hat", "");
	Commands::RegisterCommand("light", "");
	Commands::RegisterCommand("bomber", "");
	Commands::RegisterCommand("tag", "");
	
}

void Server::Update(float dt) {
	std::cout << "[Server::Update] " << dt << "\n";

	m_BroadCastHelpTime += dt;
	if (m_BroadCastHelpTime >= 50000) {
		m_BroadCastHelpTime = 0;

		Chat::SendServerMessage(" Digite !help para ver os comandos");
	}

	Chat::Update(dt);
}

void Server::GiveWeapon(long long toClient, int weaponId) {
	Mod::SendDropItem(toClient, weaponId, m_UniqueObjectId++, 30);
}

std::vector<Player*> Server::FindPlayers(std::string selector)
{
	std::vector<Player*> players;

	std::map<long long, Player*>::iterator it;
	for (it = m_Players.begin(); it != m_Players.end(); it++)
	{
		Player* player = it->second;

		if (selector == "*")
		{
			players.push_back(player);
			continue;
		}

		if (selector == "*a")
		{
			if (!player->m_IsAlive) continue;

			players.push_back(player);
			continue;
		}

		if (selector == "*d")
		{
			if (player->m_IsAlive) continue;

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

		std::string str1 = selector;
		std::transform(str1.begin(), str1.end(), str1.begin(), [](unsigned char c) { return std::tolower(c); });
		std::string str2 = player->m_Username;
		std::transform(str2.begin(), str2.end(), str2.begin(), [](unsigned char c) { return std::tolower(c); });
		
		if (str2.find(str1) != std::string::npos) {
			players.push_back(player);
		}
	}

	return players;
}
