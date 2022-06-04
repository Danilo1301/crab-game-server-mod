#include "pch-il2cpp.h"
#include "Server.h"

#include "Mod.h"
#include "Chat.h"
#include "SocketServer.h"
#include "PermissionGroups.h"
#include "Config.h"

std::map<long long, Player*> Server::m_Players;
long long Server::m_LobbyId = 0;
bool Server::m_HasCheckedUpdates = false;
Player* Server::m_LobbyOwner = NULL;
int Server::m_UniqueObjectId = 100;

int Server::m_PunchDamageId = -1;
bool Server::m_CanUseItem = true;

bool Server::m_IsAtLobby = false;
bool Server::m_RedLightState = false;

bool Server::m_AutoStartEnabled = false;
int Server::m_AutoStartTime = 15;
float Server::m_TimeUntilAutoStart = 0;

bool Server::m_UpdateRequired = false;
bool sentUpdateCheck = false;

float Server::m_SaveConfigTime = 0;

std::vector<Weapon> Server::m_Weapons = {
		{ "Ak", 0 },
		{ "Glock", 1 },
		{ "Revolver", 2 },
		{ "Dual", 3 },
		{ "Bat", 4 },
		{ "Bomb", 5 },
		{ "Katana", 6 },
		{ "Knife", 7 },
		{ "Pipe", 8 },
		{ "Snowball", 9 },
		{ "Stick", 10 },
		{ "Milk", 11 },
		{ "Pizza", 12 },
		{ "Grenade", 13 }
};

void Server::Init()
{
	LoadConfig();

	Chat::Init();

	//oops
	if (!PermissionGroups::HasGroup("default"))
	{
		auto permissionGroup = PermissionGroups::AddGroup("default");
		permissionGroup->AddPermission("help");
		permissionGroup->AddPermission("ahelp");
		permissionGroup->AddPermission("w");
		permissionGroup->AddPermission("playerinfo");
		permissionGroup->AddPermission("tp");
		permissionGroup->AddPermission("kill");
		permissionGroup->AddPermission("respawn");
		permissionGroup->AddPermission("autorespawn");
		permissionGroup->AddPermission("hover");
		permissionGroup->AddPermission("jumppunch");
		permissionGroup->AddPermission("superpunch");
		permissionGroup->AddPermission("forcefield");
		permissionGroup->AddPermission("snowball2");

		for (auto weapon : m_Weapons)
		{
			permissionGroup->AddPermission(toLower(weapon.name));
		}
	}

	if (!PermissionGroups::HasGroup("moderator"))
	{
		auto moderatorPermissionGroup = PermissionGroups::AddGroup("moderator");
		moderatorPermissionGroup->m_InheritsFromGroup = "default";

		moderatorPermissionGroup->AddPermission("kick");
		moderatorPermissionGroup->AddPermission("ban");
		moderatorPermissionGroup->AddPermission("bc");
		moderatorPermissionGroup->AddPermission("w.others");
		moderatorPermissionGroup->AddPermission("respawn.others");
		moderatorPermissionGroup->AddPermission("tp.others");
		moderatorPermissionGroup->AddPermission("god");
		moderatorPermissionGroup->AddPermission("god.others");
		moderatorPermissionGroup->AddPermission("time");
		moderatorPermissionGroup->AddPermission("r");
		moderatorPermissionGroup->AddPermission("mute");
		moderatorPermissionGroup->AddPermission("lobbyonly");
		moderatorPermissionGroup->AddPermission("start");
		moderatorPermissionGroup->AddPermission("fly");
	}

	if (!PermissionGroups::HasGroup("admin"))
	{
		auto adminPermissionGroup = PermissionGroups::AddGroup("admin");
		adminPermissionGroup->AddPermission("*");
	}

	SaveConfig();
}

void Server::Update(float dt)
{
	m_SaveConfigTime += dt;
	if (m_SaveConfigTime >= 40.0f) {
		m_SaveConfigTime = 0;
		SaveConfig();
	}

	if (!(*LobbyManager__TypeInfo)->static_fields->Instance) return;

	if (m_Players.size() == 0) return;

	if (m_LobbyOwner->m_ClientId != Mod::GetMySteamId()) return;

	if (!ProcessUpdateCheck()) return;

	UpdatePlayersPosition();

	for (auto pair : m_Players)
	{
		auto player = pair.second;

		if (player->m_FlyEnabled)
		{
			if (player->m_FlyVelocity > 0)
			{
				player->m_FlyVelocity -= 1.0f * dt;
				
				if (player->m_FlyVelocity < 0) player->m_FlyVelocity = 0;
			}

			Vector3 newPos = player->m_Position;

			if (player->m_FlyVelocity > 0)
				newPos = newPos + (player->m_LookDir) * (player->m_FlyVelocity * player->m_FlySpeed) * dt;
			
			Mod::SetPlayerPosition(player->m_ClientId, newPos);
		}

		if (player->m_RespawnTime > 0)
		{
			player->m_RespawnTime -= dt;
			if (player->m_RespawnTime < 0)
			{
				player->m_RespawnTime = 0;
				Mod::RespawnPlayer(player->m_ClientId, player->m_RespawnPosition);
			}
		}


		if (player->m_HoveringPlayer != -1)
		{
			player->m_HoveringAngle += 6 * dt;

			if (HasPlayer(player->m_HoveringPlayer))
			{
				auto toHoverPlayer = GetPlayer(player->m_HoveringPlayer);

				if (toHoverPlayer->m_IsAlive)
				{
					float height = 4.5f;
					float distance = player->m_HoveringRadius;

					auto lDirection = Vector3({
						std::sin(player->m_HoveringAngle) * distance,
						0,
						std::cos(player->m_HoveringAngle) * distance
					});

					Mod::SetPlayerPosition(player->m_ClientId, Vector3({
						lDirection.x + toHoverPlayer->m_Position.x,
						lDirection.y + toHoverPlayer->m_Position.y + height,
						lDirection.z + toHoverPlayer->m_Position.z
					}));
				}
			}
			
		}


		/*
		if (player->m_ParticleEnabled)
		{
			player->m_ParticleTime -= dt;

			if (player->m_ParticleTime < 0)
			{
				player->m_ParticleTime = 1.0f;

				auto id = m_UniqueObjectId++;

				Mod::ForceGiveItem(player->m_ClientId, 9, id);
				Mod::UseItemAll(player->m_ClientId, 9, id, Vector3({ player->m_Position.x, player->m_Position.y - 1000, player->m_Position.z }));
				Mod::UseItemAll(player->m_ClientId, 9, id, Vector3({ player->m_Position.x, player->m_Position.y - 1000, player->m_Position.z }));
			}
		}
		*/
	}

	

	if (m_AutoStartEnabled)
	{
		if (m_Players.size() > 1)
		{
			if (m_TimeUntilAutoStart == 0 && m_IsAtLobby)
			{
				m_TimeUntilAutoStart = (float)m_AutoStartTime;

				Chat::SendServerMessage("Starting game in " + std::to_string(m_AutoStartTime) + " seconds");
			}

			if (m_TimeUntilAutoStart > 0)
			{
				m_TimeUntilAutoStart -= 1 * dt;

				//std::cout << "start in " << m_TimeUntilAutoStart << std::endl;

				if (m_TimeUntilAutoStart <= 0)
				{
					m_TimeUntilAutoStart = -1;

					Mod::SetAllPlayersReady();
					Chat::SendServerMessage("Starting game in 3 seconds");
				}
			}
		}
	}
	else {
		m_TimeUntilAutoStart = 0;
	}

	Chat::Update(dt);
}

void Server::LoadConfig()
{
	Config::LoadJSON();
}

void Server::SaveConfig()
{
	Config::SaveJSON();
}

void Server::UpdatePlayersPosition()
{
	for (auto pair : m_Players)
	{
		auto player = pair.second;
		player->m_PlayerManager = NULL;
	}

	auto gameManager = (*GameManager__TypeInfo)->static_fields->Instance;
	auto activePlayers = gameManager->fields.activePlayers;

	for (size_t i = 0; i < activePlayers->fields.count; i++)
	{
		auto key = activePlayers->fields.entries->vector[i].key;
		auto playerManager = activePlayers->fields.entries->vector[i].value;

		if (!playerManager) continue;

		auto player = GetPlayer(key);
		player->m_PlayerManager = playerManager;

		auto transform = Component_get_transform((Component*)playerManager, nullptr);
		auto pos = Transform_get_position(transform, nullptr);

		if(!player->m_FlyEnabled)
			player->m_Position = pos;

		//auto headTransform = playerManager->fields.head;
		//auto headPos = Transform_get_position(headTransform, nullptr);
		//std::cout << "headPos" << headPos.toString() << std::endl;

		//auto euler = Transform_get_eulerAngles(headTransform, nullptr);
		//std::cout << "head euler" << euler.toString() << std::endl;

		//std::cout << "head forward" << player->m_FlyDir.toString() << std::endl;

		auto quat = PlayerManager_GetRotation(playerManager, NULL); //thank god (or thank Dani) this function exists lol
		auto forward = Quaternion_op_Multiply_1(quat, Vector3_get_forward(NULL), NULL);
		player->m_LookDir = Vector3_Normalize(forward, NULL);

		//Quaternion__Boxed* myQuat = (Quaternion__Boxed*)il2cpp_object_new((Il2CppClass*)*Quaternion__TypeInfo);
		//Quaternion__ctor(myQuat, quat.x, quat.y, quat.z, quat.w, NULL);


		/*
		auto quatEuler = Quaternion_get_eulerAngles(myQuat, NULL);

		auto pitch = -quatEuler.y * (M_PI / 180.0);
		auto yaw = quatEuler.x * (M_PI / 180.0);

		Vector3 direction(
			std::cos(yaw) * std::cos(pitch),
			std::sin(yaw) * std::cos(pitch),
			std::sin(pitch)
		);

		std::cout << "quatEuler" << quatEuler.toString() << std::endl;
		std::cout << "direction" << direction.toString() << std::endl;
		*/

		//Quaternion_

		//auto quatEuler = Quaternion_get_eulerAngles(quat, NULL);

		//boxed

		//targetRot * Vector3.forward;

		//Quaternion_iden


		//player->m_FlyDir = euler;

		// 
		//auto headTransform = playerManager->fields.head;
		//auto headPos = Transform_get_position(headTransform, nullptr);

		//std::cout << i << " : " << key << ", dead=" << playerManager->fields.dead << ", justdied=" << playerManager->fields.justDied << std::endl;
		//std::cout << key << " transform pos" << pos.x << ", " << pos.y << ", " << pos.z << std::endl;
		//std::cout << "head pos" << headPos.x << ", " << headPos.y << ", " << headPos.z << std::endl;

		

			//std::cout << key << " transform pos" << Mod::FormatVector(GetPlayer(key)->m_Position) << std::endl;
		
	}
}

bool Server::ProcessUpdateCheck() {
	if (!m_HasCheckedUpdates) {
		if (!SocketServer::m_Connected && !SocketServer::m_Connecting) {

			//std::cout << "needs to connect" << std::endl;
			SocketServer::Connect();

			Mod::AppendLocalChatMessage(3, "Mod", "Checking for updates...");
		}

		if (!SocketServer::m_Connected) {
			//std::cout << "not connected" << std::endl;
			return false;
		}

		//std::cout << "not checked" << std::endl;

		if (!sentUpdateCheck) {
			sentUpdateCheck = true;

			//std::cout << "sent" << std::endl;

			Json::Value data;
			data["version"] = Mod::m_Version;
			data["lobbyId"] = m_LobbyId;
			data["ownerId"] = m_LobbyOwner ? m_LobbyOwner->m_ClientId : NULL;

			SocketServer::Emit("joinLobby", data);

		}
		else {
			if (!SocketServer::m_LastPacket.isNull()) {
				auto packet = SocketServer::m_LastPacket;

				if (packet["id"].asString().compare("update") == 0) {
					m_HasCheckedUpdates = true;

					auto data = packet["data"];

					auto version = data["version"].asString();
					auto required = data["required"].asBool();
					auto changelog = data["changelog"].asString();

					if (version.compare(Mod::m_Version) == 0) {
						Mod::AppendLocalChatMessage(3, "Mod", "Mod started!");

						//m_HasCheckedUpdates = true;
					}
					else {
						std::string requiredText = (required ? "REQUIRED" : "optional");

						Mod::AppendLocalChatMessage(1, "Mod", "-----------------------------------");
						Mod::AppendLocalChatMessage(1, "Mod", "New version available (" + requiredText + ")");
						Mod::AppendLocalChatMessage(1, "Mod", "Current: v" + Mod::m_Version + " | New: v" + version);
						Mod::AppendLocalChatMessage(1, "Mod", "About: " + changelog);
						Mod::AppendLocalChatMessage(1, "Mod", "Download URL:  https://bit.ly/crabgame-mod");

						if (Mod::m_DebugMode)
						{
							SocketServer::m_LastPacket = Json::nullValue;
							SocketServer::Close();
							return true;
						}

						m_UpdateRequired = required;
					}

					SocketServer::m_LastPacket = Json::nullValue;
					SocketServer::Close();
				}
			}
		}

		return false;
	}

	if (m_UpdateRequired) return false;

	return true;
}

bool Server::HasPlayer(long long clientId)
{
	return m_Players.find(clientId) != m_Players.end();
}

Player* Server::AddPlayer(Player* player)
{
	m_Players.insert(std::pair<long long, Player*>(player->m_ClientId, player));
	return player;
}

void Server::RemovePlayer(Player* player)
{
	std::cout << "[Server] RemovePlayer " << player->GetDisplayNameExtra() << std::endl;

	m_Players.erase(player->m_ClientId);
	delete player;
}

Player* Server::GetPlayer(long long clientId)
{
	return m_Players.at(clientId);
}

void Server::TryAddPlayer(long long clientId, int playerId, PlayerManager* playerManager)
{
	auto username = (monoString*)playerManager->fields.username;

	bool newPlayer = false;
	Player* player = NULL;

	if (HasPlayer(clientId))
	{
		player = GetPlayer(clientId);
	}
	else
	{
		player = new Player(clientId);
		Server::AddPlayer(player);

		newPlayer = true;
	}

	player->m_Username = username->toCPPString();

	player->m_Id = playerId;

	if (playerId == 1)
	{
		Server::m_LobbyOwner = player;
	}

	if (player->IsLobbyOwner())
	{
		player->m_PermissionGroup = "admin";
	}

	if (!player->m_IsOnline)
	{
		player->m_IsOnline = true;
		Server::OnPlayerJoin(player);
	}

	if (newPlayer)
	{
		std::cout << "[Server] New player " << player->GetDisplayNameExtra() << " (" << std::to_string(m_Players.size()) << " in total)" << std::endl;
	}

}

void Server::RemoveAllPlayers()
{
	while (m_Players.size() > 0) {
		auto player = (*m_Players.begin()).second;
		RemovePlayer(player);
	}
}

void Server::OnCreateLobby()
{
	std::cout << "[Server] Lobby created " << m_LobbyId << std::endl;

	for (auto pair : m_Players)
	{
		auto player = pair.second;

		player->m_IsOnline = false;
		player->m_IsAlive = false;
		player->m_DiedInThisRound = false;
	}

	//RemoveAllPlayers();
	Chat::RemoveAllMessages();

	m_HasCheckedUpdates = false;
	sentUpdateCheck = false;
	m_UpdateRequired = false;
}

void Server::OnPlayerJoin(Player* player)
{
	std::cout << "[Server] Player joined: " << player->GetDisplayNameExtra() << std::endl;
}

void Server::OnPlayerLeave(Player* player)
{
	std::cout << "[Server] Player left: " << player->GetDisplayNameExtra() << std::endl;
}

bool Server::OnPlayerDied(long long deadClient, long long damageDoerId, Vector3 damageDir)
{
	if (Server::HasPlayer(deadClient))
	{
		Player* deadPlayer = GetPlayer(deadClient);
		//Server::ChangePlayerIsAliveState(deadPlayer, false);

		if (deadPlayer->m_Godmode) return false;

		deadPlayer->SetAlive(false);

		if (deadClient == damageDoerId)
		{
			Chat::SendServerMessage("" + deadPlayer->GetDisplayName() + " died");
		}
		else
		{
			if (HasPlayer(damageDoerId)) {
				Player* killerPlayer = GetPlayer(damageDoerId);

				Chat::SendServerMessage("" + killerPlayer->GetDisplayName() + " killed " + deadPlayer->GetDisplayName());
			}
			else {
				Chat::SendServerMessage("" + deadPlayer->GetDisplayName() + " died");
			}
		}


		if (HasPlayer(deadClient)) {
			auto player = GetPlayer(deadClient);

			player->m_DiedInThisRound = true;
			
			if (player->m_AutoRespawnEnabled) {
				player->m_RespawnTime = 1.6f;
			}
		}
	}

	return true;
}

void Server::GiveWeapon(long long toClient, int weaponId)
{
	if (!GetPlayer(toClient)->m_IsAlive) return;

	Mod::SendDropItem(toClient, weaponId, m_UniqueObjectId++, 30);
}

void Server::GiveWeaponHand(long long toClient, int weaponId)
{
	if (!GetPlayer(toClient)->m_IsAlive) return;

	Mod::ForceGiveItem(toClient, weaponId, m_UniqueObjectId++);
}


Weapon* Server::GetWeaponById(int weaponId)
{
	for (auto& weapon : Server::m_Weapons)
	{
		if (weaponId == weapon.id)
		{
			return &weapon;
		}
	}

	return NULL;
}

std::vector<Player*> Server::FindPlayers(std::string selector)
{
	//add check for online

	std::vector<Player*> players;

	std::map<long long, Player*>::iterator it;
	for (it = m_Players.begin(); it != m_Players.end(); it++)
	{
		Player* player = it->second;

		if (!player->m_IsOnline) continue;

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

			if (player->m_Id == id)
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