#pragma once

#include "pch.h"

#include "Message.h"
#include "Command.h"

class Chat {
public:
	static std::vector<Message*> m_Messages;
	static std::vector<Command*> m_Commands;

	static void Init();
	static void Update(float dt);

	static void RegisterCommand(Command* command);

	static void ProcessRawMessage(long long id, std::string content);
	static void ProcessMessage(Message* message);
	static void ProcessCommandMessage(Message* message);

	static void SendAllMessagesInQuery();

	static void RemoveMessage(Message* message);


	static Message* SendServerMessage(std::string text);
	static void SendServerMessage(std::vector<std::string> lines);
};