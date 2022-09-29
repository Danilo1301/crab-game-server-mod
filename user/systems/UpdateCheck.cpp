#include "pch-il2cpp.h"
#include "UpdateCheck.h"

#include "SocketServer.h"
#include "Mod.h"
#include "Server.h"

bool UpdateCheck::HasCheckedUpdates = false;

bool updateRequired = false;
bool sentUpdateCheck = false;

bool UpdateCheck::Check()
{
	if (!HasCheckedUpdates) {
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
			data["version"] = Mod::Version;
			data["lobbyId"] = Server::LobbyId;
			data["ownerId"] = Mod::GetCurrentLobbyOwnerId();

			SocketServer::Emit("joinLobby", data);

		}
		else {
			if (!SocketServer::m_LastPacket.isNull()) {
				auto packet = SocketServer::m_LastPacket;

				if (packet["id"].asString().compare("update") == 0) {
					HasCheckedUpdates = true;

					auto data = packet["data"];

					auto version = data["version"].asString();
					auto required = data["required"].asBool();
					auto changelog = data["changelog"].asString();

					if (version.compare(Mod::Version) == 0) {
						Mod::AppendLocalChatMessage(3, "Mod", "Mod started!");

						//HasCheckedUpdates = true;
					}
					else {
						std::string requiredText = (required ? "REQUIRED" : "optional");

						Mod::AppendLocalChatMessage(1, "Mod", "---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- ---- --");
						Mod::AppendLocalChatMessage(1, "Mod", "New version available (" + requiredText + ")");
						Mod::AppendLocalChatMessage(1, "Mod", "Current: v" + Mod::Version + " | New: v" + version);
						Mod::AppendLocalChatMessage(1, "Mod", "About: " + changelog);
						Mod::AppendLocalChatMessage(1, "Mod", "Download URL:  https://bit.ly/crabgame-mod");

						/*
						if (Mod::m_DebugMode)
						{
							SocketServer::m_LastPacket = Json::nullValue;
							SocketServer::Close();
							return true;
						}
						*/

						updateRequired = required;
					}

					SocketServer::m_LastPacket = Json::nullValue;
					SocketServer::Close();
				}
			}
		}

		return false;
	}

	if (updateRequired) return false;

	return true;
}