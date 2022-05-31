#pragma once

#include "pch.h"

#include "Message.h"
#include "Command.h"

class Chat {
public:
	static std::vector<Message*> m_Messages;
	static std::vector<Command*> m_Commands;

	static bool m_ShowHelpMessage;
	static float m_BroadCastHelpTime;

	static void Init();
	static void Update(float dt);

	static void ProcessRawMessage(long long clientId, std::string text, bool dontSend);
	static void ProcessMessage(Message* message);
	static bool ProcessWeaponCommand(Message* message);

	static Message* SendServerMessage(std::string text);
	static void SendServerMessage(std::vector<std::string> lines);

	static void SendCommandsPage(std::vector<std::string> commands, int page);

	static void SendAllMessagesInQuery();
	static void RemoveMessage(Message* message);
	static void RemoveAllMessages();
	
	static void RegisterCommand(Command* command);
};