#pragma once

#include "Injector.h"
#include "Chat.h"

#include "templates_GameServer.h"
#include "templates_LobbyManager.h"
#include "templates_ServerSend.h"
#include "templates_GameManager.h"

static auto HF_ChatBox_Update = new HookFunction<void, ChatBox*, MethodInfo*>("ChatBox::Update");
static void Template_ChatBox_Update(ChatBox* a, MethodInfo* method)
{
	//std::cout << "ChatBox::Update" << " a=" << a << ", " << std::endl;

	HF_ChatBox_Update->original(a, method);

	if (Mod::IsInAnyLobby())
	{
		//std::cout << "update from chatbox" << std::endl;

		float dt = Time_get_deltaTime(NULL);
		Server::Update(dt);

		Chat::ProcessAllMessages();
	}
}

static auto HF_ChatBox_AppendMessage = new HookFunction<void, ChatBox*, uint64_t, String*, String*, MethodInfo*>("ChatBox::AppendMessage");
static void Template_ChatBox_AppendMessage(ChatBox* a, uint64_t b, String* c, String* d, MethodInfo* method)
{
	//std::cout << "ChatBox::AppendMessage" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	//if (b == 0) return;

	HF_ChatBox_AppendMessage->original(a, b, c, d, method);
}

static void Inject_Templates()
{
	Injector::Inject(HF_ChatBox_Update, ChatBox_Update, &Template_ChatBox_Update);
	Injector::Inject(HF_ChatBox_AppendMessage, ChatBox_AppendMessage, &Template_ChatBox_AppendMessage);
}