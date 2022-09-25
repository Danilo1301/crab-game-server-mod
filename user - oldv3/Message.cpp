#include "pch-il2cpp.h"
#include "Message.h"

Message::Message(long long fromClient, std::string content)
{
	m_FromClient = fromClient;
	m_Content = content;
	Init();
}

Message::Message(Player* player, std::string content)
{
	m_Player = player;
	m_FromClient = player->m_ClientId;
	m_Content = content;
	Init();
}

void Message::Init()
{
	if (m_Content.rfind("!", 0) != 0) return;
	m_IsCommand = true;

	int i = (int)m_Content.find(" ");

	m_Cmd = m_Content.substr(1, i - 1);
	if(i != -1) m_CmdArgs = m_Content.substr(i + 1);

	//std::cout << "CMD=" << m_Cmd << "|" << std::endl;
	//std::cout << "CMDARGS=" << m_CmdArgs << "|" << std::endl;
}