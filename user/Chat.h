#pragma once

#include "pch.h"

#include "Message.h"
#include "Command.h"

class Chat {
public:
	static std::vector<Message*> Messages;
	static std::vector<Command*> Commands;

	static bool ShowPlayerIdsAfterName;
	static bool ShowDeathStateAfterName;
	static bool ShowNoPermissionMessage;

	static void Init();
	static void Update(float dt);

	static void ProcessMute(float dt);

	static void RegisterCommand(Command* command);

	static Message* AddMessage(Message* message);
	static Message* AddMessageAndProcess(Message* message);
	static void RemoveMessage(Message* message);
	static void ProcessMessage(Message* message);
	static Command* FindCommand(std::string cmd);

	static void ProcessAllMessages();
private:
	static void ProcessCommandMessage(Message* message);
	static bool ProcessWeaponCommand(Message* message);
public:
	static Message* SendServerMessage(std::string text);
	static void SendServerMessage(std::vector<std::string> lines);

	//From Template_ServerSend_SendChatMessage
	static void OnTrySendChatMessage(long long clientId, std::string content);

	static void SendCommandsPage(std::vector<std::string> commands, int page);
	static bool PrintCommanSyntaxes(std::string cmd);
};