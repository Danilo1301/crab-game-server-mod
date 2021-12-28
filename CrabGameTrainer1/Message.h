#pragma once

#include "pch.h"

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

	Message(long long fromClient, std::string content) {
		m_FromClient = fromClient;
		m_Content = content;
	}
};