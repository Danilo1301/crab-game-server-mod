#include "pch-il2cpp.h"
#include "Server.h"

#include "Chat.h"
#include "Commands.h"
#include "Mod.h"
#include "SocketServer.h"

std::map<long long, Player*> Server::m_Players;
std::chrono::system_clock::time_point Server::m_LastUpdatedTime;
int Server::m_UniqueObjectId = 100;
float Server::m_BroadCastHelpTime = 0;
bool Server::m_LightState = false;
Player* Server::m_LobbyOwner = NULL;
Vector3 Server::m_SpawnPosition = Vector3({ 0, 5, 0 });
bool Server::m_CanUpdateSpawnPosition = true;
bool Server::m_ShowHelpMessage = true;
bool Server::m_ShowPlayerIds = true;
long long Server::m_LobbyId = 0;
long long Server::m_LastLobbyId = 0;
bool Server::m_HasCheckedForUpdate = false;

bool Server::m_AutoStartEnabled = false;
int Server::m_AutoStartTime = 15;
float Server::m_TimeUntilAutoStart = 0;

bool Server::m_IsAtLobby = false;

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
	{ "grenade", 13 }
};
std::vector<int> Server::m_DisabledWeapons;

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

void Server::TryAddPlayer(long long clientId, int playerId, u10A5u109Au109Eu109Eu1099u10A8u10A8u109Au109Du109Fu109C* playerManager) {
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
	std::cout << "[Server] Init" << std::endl;

	Chat::RegisterCommands();
}

void Server::Update(float dt) {
	//std::cout << "[Server::Update] " << dt << "\n";

	if (SocketServer::m_IsConnected) {
		if (m_LobbyId != m_LastLobbyId) {
			m_LastLobbyId = m_LobbyId;
			m_HasCheckedForUpdate = false;

			std::cout << "[Server] Joined lobby " << m_LobbyId << std::endl;

			Json::Value data;
			data["version"] = Mod::m_Version;
			data["lobbyId"] = m_LobbyId;
			data["ownerId"] = m_LobbyOwner ? m_LobbyOwner->m_ClientId : NULL;

			SocketServer::Emit("joinLobby", data);

			Mod::AppendLocalChatMessage(0, "Mod", "Checking for updates...");
		}

		if (!m_HasCheckedForUpdate) {
			if (!SocketServer::m_LastPacket.isNull()) {
				auto packet = SocketServer::m_LastPacket;

				if (packet["id"].asString().compare("update") == 0) {
					auto data = packet["data"];

					auto version = data["version"].asString();
					auto required = data["required"].asBool();
					auto changelog = data["changelog"].asString();

					if (version.compare(Mod::m_Version) == 0) {
						Mod::AppendLocalChatMessage(0, "Mod", "Mod started!");

						m_HasCheckedForUpdate = true;
					}
					else {
						std::string requiredText = (required ? "REQUIRED" : "optional");

						Mod::AppendLocalChatMessage(1, "Mod", "-----------------------------------");
						Mod::AppendLocalChatMessage(1, "Mod", "New version available (" + requiredText + ")");
						Mod::AppendLocalChatMessage(1, "Mod", "Current: v" + Mod::m_Version + ", new: v" + version);
						Mod::AppendLocalChatMessage(1, "Mod", "About: " + changelog);
						Mod::AppendLocalChatMessage(1, "Mod", "Download URL:  https://bit.ly/crabgame-mod");

						if (!required) {
							m_HasCheckedForUpdate = true;
						}
					}

					SocketServer::m_LastPacket = Json::nullValue;
				}
			}
			//return;
		}
	}

	m_BroadCastHelpTime += dt;
	if (m_BroadCastHelpTime >= 50000 && m_ShowHelpMessage) {
		//std::cout << "[Server] Sending help message " << m_BroadCastHelpTime << " dt" << dt << std::endl;

		m_BroadCastHelpTime = 0;

		Chat::SendServerMessage(" Type !help for a list of commands");
		//Chat::SendServerMessage(" Digite !help para ver os comandos");
	}

	/*
	if (SocketServer::m_IsConnected) {
		if (m_Players.size() > 0) {
			if (SocketServer::m_LastSentLobbyId != m_LobbyId) {
				SocketServer::m_LastSentLobbyId = m_LobbyId;
				SocketServer::Emit("log", "New lobby created " + std::to_string(m_LobbyId));
			}
		}
	}
	*/

	auto gameManager = Mod::GetGameManager()->static_fields->Instance;
	auto activePlayers = gameManager->fields.activePlayers;
	for (size_t i = 0; i < activePlayers->fields.count; i++)
	{
		auto key = activePlayers->fields.entries->vector[i].key;
		auto playerManager = activePlayers->fields.entries->vector[i].value;

		auto transform = Component_get_transform((Component*)playerManager, nullptr);
		auto pos = Transform_get_position(transform, nullptr);

		auto headTransfor = playerManager->fields.head;
		auto headPos = Transform_get_position(headTransfor, nullptr);

		//std::cout << i << " : " << key << ", dead=" << playerManager->fields.dead << ", justdied=" << playerManager->fields.justDied << std::endl;
		//std::cout << key << " transform pos" << pos.x << ", " << pos.y << ", " << pos.z << std::endl;
		//std::cout << "head pos" << headPos.x << ", " << headPos.y << ", " << headPos.z << std::endl;

		if (HasPlayer(key)) {
			GetPlayer(key)->m_Position = pos;
			//std::cout << key << " transform pos" << Mod::FormatVector(GetPlayer(key)->m_Position) << std::endl;
		}
		//u10A0u10A8u10A0u10A4u10A8u10A0u109Au10A5u10A7u10A7u109C_SpectatorSpawn(key, nullptr);
	}

	if (m_AutoStartEnabled)
	{
		if (m_TimeUntilAutoStart > 0 && m_Players.size() > 1)
		{
			m_TimeUntilAutoStart -= 1 * dt;

			//std::cout << "start in " << m_TimeUntilAutoStart << std::endl;

			if (m_TimeUntilAutoStart <= 0)
			{
				m_TimeUntilAutoStart = 0;

				Mod::SetAllPlayersReady();

				Chat::SendServerMessage("Starting game in 3 seconds");
			}
		}
		
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

bool Server::IsWeaponDisabled(int weaponId) {
	return (std::find(Server::m_DisabledWeapons.begin(), Server::m_DisabledWeapons.end(), weaponId) != Server::m_DisabledWeapons.end());
}

void Server::DisableWeapon(int weaponId) {
	if (IsWeaponDisabled(weaponId)) return;
	m_DisabledWeapons.push_back(weaponId);
}

void Server::EnableWeapon(int weaponId) {
	if (!IsWeaponDisabled(weaponId)) return;

	std::vector<int>::iterator itr = std::find(m_DisabledWeapons.begin(), m_DisabledWeapons.end(), weaponId);
	if (itr != m_DisabledWeapons.end()) m_DisabledWeapons.erase(itr);
}