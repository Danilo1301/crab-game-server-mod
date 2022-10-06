#include "pch-il2cpp.h"
#include "Config.h"

#include "PermissionGroups.h"
#include "Server.h"
#include "Mod.h"
#include "Chat.h"
#include "systems/BanSystem.h"
#include "INIRead.h"

std::string Config::PATH_SERVER_FOLDER = "/server/";
std::string Config::PATH_DATA_FOLDER = PATH_SERVER_FOLDER + "/data/";
std::string Config::PATH_PERMISSIONS_FOLDER = PATH_SERVER_FOLDER + "/permissions/";
std::string Config::PATH_PERMISSION_GROUPS_FOLDER = PATH_PERMISSIONS_FOLDER + "/groups/";

std::string Config::PATH_CONFIG_FILE = PATH_SERVER_FOLDER + "config.ini";
std::string Config::PATH_PLAYERS_FILE = PATH_DATA_FOLDER + "players.json";
std::string Config::PATH_VERSION_FILE = PATH_SERVER_FOLDER + "version";

float Config::AutoSaveTimeElapsed = 0.0f;
float Config::AutoSaveInterval = 20.0f;

bool Config::Exists(std::string path)
{
	return std::experimental::filesystem::v1::exists(path);
}

void Config::CreatePath(std::string path)
{
	if (!std::experimental::filesystem::v1::is_directory(path) || !std::experimental::filesystem::v1::exists(path)) {
		std::experimental::filesystem::v1::create_directory(path);
	}
}

std::string Config::GetPath(std::string path)
{
	std::experimental::filesystem::path cwd = std::experimental::filesystem::current_path() / path;
	return cwd.string();
}

void Config::WriteToFile(std::string path, Json::Value value)
{
	//std::cout << "[Config] WriteToFile " << path << std::endl;

	Json::StyledWriter writer;
	std::string strJson = writer.write(value);

	std::ofstream file(path);
	file << strJson;
	file.close();
}

Json::Value Config::ReadFile(std::string path)
{
	//std::cout << "[Config] ReadFile " << path << std::endl;

	std::ifstream file(path);

	Json::Value value;
	Json::Reader reader;

	if (!reader.parse(file, value, true)) {
		std::cout << "[Config] ERROR reading " << path << std::endl;
	}

	return value;
}

void Config::Save()
{
	std::cout << "[Config] Save" << std::endl;

	Config::CreatePaths();

	//version
	std::ofstream versionFile(GetPath(PATH_VERSION_FILE));
	versionFile << Mod::Version << std::endl;
	versionFile.close();

	//config.ini
	SaveConfigFile();

	//players
	SavePlayers();

	//permissions
	PermissionGroups::SaveConfig();
}

void Config::Load()
{
	std::cout << "[Config] Load" << std::endl;

	if (!Exists(GetPath(PATH_SERVER_FOLDER)))
	{
		std::cout << "[Config] Config not found" << std::endl;

		CreateFirstConfig();

		return;
	}

	ProcessV2toV3ConfigLoad();

	//version
	std::string versionLine;
	std::ifstream versionFile(GetPath(PATH_VERSION_FILE));
	std::getline(versionFile, versionLine);
	versionFile.close();
	ProcessVersionChange(versionLine);

	//config.ini
	LoadConfigFile();

	//players
	LoadPlayers();
	
	//permissions
	PermissionGroups::LoadConfig();
}

void Config::CreateFirstConfig()
{
	PermissionGroups::CheckDefaultGroups();

	Save();
}

void Config::Reload()
{
	LoadConfigFile();
	LoadPlayers();
	PermissionGroups::ReloadConfig();
}

void Config::ProcessAutoSave(float dt)
{
	AutoSaveTimeElapsed += dt;
	if (AutoSaveTimeElapsed >= AutoSaveInterval)
	{
		AutoSaveTimeElapsed = 0;
		
		SavePlayers();
	}
}

void Config::SaveConfigFile()
{
	std::cout << "[Config] Saving config.ini" << std::endl;

	INIWrite::CreateINIFile(GetPath(PATH_CONFIG_FILE));
	INIWrite::AddLine("[Server]");
	INIWrite::AddBool("show_player_ids", Chat::ShowPlayerIdsAfterName);
	INIWrite::AddBool("show_death_status_after_name", Chat::ShowDeathStateAfterName);
	INIWrite::AddBool("help_message_show", Chat::ShowHelpMessage);
	INIWrite::AddString("help_message", Chat::HelpMessage);
	INIWrite::AddFloat("help_message_interval", Chat::BroadcastHelpInterval);
	INIWrite::AddBool("command_show_help_on_invalid_syntax", Command::AutoShowHelp);
	INIWrite::AddFloat("auto_save_interval", Config::AutoSaveInterval);

	INIWrite::CloseINIFile();
}

void Config::LoadConfigFile()
{
	std::cout << "[Config] Loading config.ini" << std::endl;

	Chat::ShowPlayerIdsAfterName = INIRead::GetBool(GetPath(PATH_CONFIG_FILE), "Server", "show_player_ids");
	Chat::ShowDeathStateAfterName = INIRead::GetBool(GetPath(PATH_CONFIG_FILE), "Server", "show_death_status_after_name");
	Chat::ShowHelpMessage = INIRead::GetBool(GetPath(PATH_CONFIG_FILE), "Server", "help_message_show");
	Chat::HelpMessage = INIRead::GetString(GetPath(PATH_CONFIG_FILE), "Server", "help_message");
	Chat::BroadcastHelpInterval = INIRead::GetFloat(GetPath(PATH_CONFIG_FILE), "Server", "help_message_interval");
	Command::AutoShowHelp = INIRead::GetBool(GetPath(PATH_CONFIG_FILE), "Server", "command_show_help_on_invalid_syntax");
	Config::AutoSaveInterval = INIRead::GetFloat(GetPath(PATH_CONFIG_FILE), "Server", "auto_save_interval");

	std::cout << "[Config] AutoSaveInterval= " << Config::AutoSaveInterval << std::endl;
}

void Config::SavePlayers()
{
	std::cout << "[Config] Saving players.json" << std::endl;

	Json::Value playersValue = Json::objectValue;
	for (auto pair : Server::Players)
	{
		auto key = pair.first;
		auto player = pair.second;

		Json::Value playerValue;
		playerValue["username"] = player->Username;
		playerValue["group"] = player->PermissionGroupId;

		if (BanSystem::IsPlayerBanned(player->ClientId))
		{
			auto banInfo = BanSystem::BannedPlayers[player->ClientId];

			playerValue["banInfo"] = Json::objectValue;
			playerValue["banInfo"]["reason"] = banInfo.reason;
			playerValue["banInfo"]["unban_at"] = (int)banInfo.unbanTime;
		}

		playersValue[std::to_string(key)] = playerValue;
	}

	WriteToFile(GetPath(PATH_PLAYERS_FILE), playersValue);
}

void Config::LoadPlayers()
{
	std::cout << "[Config] Loading players.json" << std::endl;

	Json::Value usersValue = ReadFile(GetPath(PATH_PLAYERS_FILE));
	for (auto key : usersValue.getMemberNames())
	{
		auto playerValue = usersValue[key];
		auto clientId = std::stoll(key);
		auto player = Server::GetPlayer(clientId);

		if (!player) player = new Player(clientId);

		player->Username = playerValue["username"].asString();
		player->PermissionGroupId = playerValue["group"].asString();

		if (!playerValue["banInfo"].isNull())
		{
			std::string reason = playerValue["banInfo"]["reason"].asString();
			int time = playerValue["banInfo"]["time"].asInt();

			BanSystem::BannedPlayers[clientId] = { reason, time };
		}

		if (!Server::HasPlayer(clientId)) Server::AddPlayer(player);
	}
}

void Config::ProcessV2toV3ConfigLoad()
{
	if (Exists(GetPath(PATH_SERVER_FOLDER)) && !Exists(GetPath(PATH_VERSION_FILE)))
	{
		std::string msg = "The server folder (v1/v2) is incompatible with this new version (v3)\n\n> You need to DELETE the '/server/' folder to continue\n(Don't forget to backup)\n\nServer folder at:\n> " + GetPath(PATH_SERVER_FOLDER) + "";
		MessageBoxA(NULL, msg.c_str(), "Incompatible config", MB_OK | MB_ICONERROR);

		exit(0);
	}
}

void Config::ProcessVersionChange(std::string oldVersion)
{
	std::cout << "[Config] Updating from " << oldVersion << " to " << Mod::Version << std::endl;

	if (oldVersion == "3.2")
	{
		std::cout << "Applying patch 3.3" << std::endl;

		CreatePaths();

		std::cout << "Moving players" << std::endl;

		std::experimental::filesystem::rename(
			GetPath(PATH_SERVER_FOLDER + "players.json"),
			GetPath(PATH_SERVER_FOLDER + "data/players.json")
		);

		oldVersion = "3.3";
	}

	/*
	* EXAMPLE PATCH
	* 
	if (oldVersion == "3.0")
	{
		std::cout << "Applying test patch 3.1" << std::endl;
		oldVersion = "3.1";
	}

	test patch
	and test from fresh install
	*/
}

/*
void Config::CreateBroadcastMessagesFile()
{
	auto path = GetPath(Config::PATH_SERVER_FOLDER) + "broadcast_messages.ini";

	if (Exists(path)) return;

	std::cout << "[Config] CreateBroadcastMessagesFile" << std::endl;

	INIWrite::CreateINIFile(path);
	INIWrite::AddLine("[Messages]");
	INIWrite::AddLine("Type help for a list of commands");
	INIWrite::AddLine("");
	INIWrite::AddLine("[Config]");
	INIWrite::AddLine("send_messages_interval = 60");
	INIWrite::AddLine("");
	INIWrite::AddLine("#");
	INIWrite::AddLine("# Use | to add a new line. Example:");
	INIWrite::AddLine("# First line|Second line|Third line");
	INIWrite::AddLine("#");
	INIWrite::CloseINIFile();
}
*/

void Config::CreatePaths()
{
	CreatePath(GetPath(PATH_SERVER_FOLDER));
	CreatePath(GetPath(PATH_DATA_FOLDER));
	CreatePath(GetPath(PATH_PERMISSIONS_FOLDER));
	CreatePath(GetPath(PATH_PERMISSION_GROUPS_FOLDER));
}