#pragma once

#include "templates_LobbyManager.h"
#include "templates_ServerSend.h"
#include "templates_GameServer.h"
#include "templates_GameManager.h"
#include "templates_GameModeFallingPlatforms.h"
#include "templates_test_GameMode_Init.h"
#include "templates_GameModeBlockDrop.h"

auto HF_ChatBox_Update = new HookFunction<void, ChatBox*, MethodInfo*>("ChatBox::Update");
void Template_ChatBox_Update(ChatBox* a, MethodInfo* method)
{
	//std::cout << "ChatBox::Update" << " a=" << a << ", " << std::endl;

	HF_ChatBox_Update->original(a, method);

	Chat::SendAllMessagesInQuery();
}

auto HF_ChatBox_AppendMessage = new HookFunction<void, ChatBox*, uint64_t, String*, String*, MethodInfo*>("ChatBox::AppendMessage");
void Template_ChatBox_AppendMessage(ChatBox* a, uint64_t b, String* c, String* d, MethodInfo* method)
{
	//std::cout << "ChatBox::AppendMessage" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	if (b == 0) return;

	HF_ChatBox_AppendMessage->original(a, b, c, d, method);
}




