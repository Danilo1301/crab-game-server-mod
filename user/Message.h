#pragma once

#include "pch.h"
#include "Player.h"

enum class MessageSendType {
	NORMAL,
	FORCE_SEND,
	FORCE_HIDE,
	FORCE_PRIVATE
};

class Message {
public:
	long long FromClientId;
	std::string Content;
	MessageSendType SendType = MessageSendType::NORMAL;
	Player* FromPlayer = NULL;

	bool IsCommand = false;
	std::string Cmd;
	std::string CmdArgs;

	Message(long long fromClient, std::string content);
	Message(Player* player, std::string content);

private:
	void Init();
};