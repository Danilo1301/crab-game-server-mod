#pragma once

#include "pch.h"
#include "Player.h"
#include "Message.h"
#include "Command.h"

class Chat {
private:
	static void ProcessCommand(Player* player, Message* message, Command* command);
public:
	static std::vector<Message*> m_Messages;
	static std::string m_HelpMessage;

	static Message* SendServerMessage(std::string text);
	static void SendAllMessagesInQuery();

	static void Update(float dt);

	static void ProcessRawMessage(long long clientId, std::string text);
	static void ProcessMessage(Message* message);

	static void SendHelpMessage(int page);
};