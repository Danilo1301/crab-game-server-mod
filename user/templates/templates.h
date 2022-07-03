#pragma once

#include "pch-il2cpp.h"
#include "pch.h"
#include "../Event.h"
#include "../Injector.h"

/*
static HookFunction<void, ChatBox*, MethodInfo*>* WTF;

static TemplateEvent<void, ChatBox*, uint64_t, String*, String*, MethodInfo*>* Event_ChatBox_AppendMessage;
*/

/*
static HookFunction<void, ChatBox*, MethodInfo*>* HF_ChatBox_Update;

static void Template_ChatBox_Update(ChatBox* a, MethodInfo* method)
{
	std::cout << "ChatBox::Update" << " a=" << a << ", " << std::endl;

	HF_ChatBox_Update->original(a, method);
}
*/


/*

static HookFunction<void, ChatBox*, MethodInfo*>* HF_ChatBox_Update;

static void Template_ChatBox_Update(ChatBox* a, MethodInfo* method);
*/