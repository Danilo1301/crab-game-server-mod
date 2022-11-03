#include "pch-il2cpp.h"
#include "AutoMessages.h"

#include "Chat.h"
#include "Config.h"
#include "INIRead.h"

std::vector<std::string> AutoMessages::Messages;

bool AutoMessages::Enabled = true;
float AutoMessages::SendInterval = 40;
float AutoMessages::SendTimeElapsed = 0;

int _sendIndex = 0;

void AutoMessages::Update(float dt)
{
	if (!Enabled) return;

	SendTimeElapsed += dt;
	if (SendTimeElapsed >= SendInterval)
	{
		SendTimeElapsed = 0;

		BroadcastNextMessage();
	}
}

void AutoMessages::AddMessage(std::string text)
{
	std::cout << "[AutoMessages] AddMessage: " << text << std::endl;

	Messages.push_back(text);
}

void AutoMessages::ClearMessages()
{
	Messages.clear();
}

void AutoMessages::BroadcastNextMessage()
{
	auto maxMessages = Messages.size();

	std::cout << "[AutoMessages] BroadcastNextMessage " << (_sendIndex+1) << " / " << maxMessages << std::endl;

	auto message = Messages[_sendIndex];
	auto lines = split_1(message, '|');

	Chat::SendServerMessage(lines);

	_sendIndex++;
	if (_sendIndex >= Messages.size()) _sendIndex = 0;
}

void AutoMessages::SaveConfig()
{
	std::cout << "[AutoMessages] SaveConfig" << std::endl;

	auto path = Config::GetPath(Config::PATH_SERVER_FOLDER) + "broadcast_messages.ini";

	//if (Exists(path)) return;

	INIWrite::CreateINIFile(path);
	INIWrite::AddLine("[Messages]");

	for(auto message : Messages) INIWrite::AddLine(message);

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

void AutoMessages::LoadConfig()
{
	std::cout << "[AutoMessages] LoadConfig" << std::endl;
	
	auto path = Config::GetPath(Config::PATH_SERVER_FOLDER) + "broadcast_messages.ini";

	if (!Config::Exists(path))
	{
		std::cout << "[AutoMessages] broadcast_messages.ini not found" << std::endl;
		CreateFirstConfig();
		SaveConfig();
		return;
	}

	SendInterval = INIRead::GetFloat(path, "Config", "send_messages_interval", SendInterval);

	auto messages = INIRead::GetMultipleStrings(path, "Messages");
	for (auto message : messages) AddMessage(message);

	std::cout << "[AutoMessages] Interval= " << SendInterval << std::endl;
}

void AutoMessages::ReloadConfig()
{
	std::cout << "[AutoMessages] ReloadConfig" << std::endl;

	ClearMessages();
	LoadConfig();
}

void AutoMessages::CreateFirstConfig()
{
	std::cout << "[AutoMessages] CreateFirstConfig" << std::endl;

	AddMessage(" Type !help for a list of commands");
}