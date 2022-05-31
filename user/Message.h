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
	long long m_FromClient;
	std::string m_Content;
	MessageSendType m_SendType = MessageSendType::NORMAL;
	Player* m_Player = NULL;


	//
	bool m_IsCommand = false;
	std::string m_Cmd;
	std::string m_CmdArgs;
	//std::vector<std::string> m_TextParts;

	Message(long long fromClient, std::string content);
	Message(Player* player, std::string content);

	void Init();
};