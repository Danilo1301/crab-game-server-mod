#pragma once

#include "pch-il2cpp.h"
#include "pch.h"
#include "../Event.h"
#include "../Injector.h"

/*

static auto HF_ChatBox_AppendMessage = new HookFunction<void, ChatBox*, uint64_t, String*, String*, MethodInfo*>("ChatBox::AppendMessage");
static auto HFEvent_ChatBox_AppendMessage = new HookFunctionEvent<void, ChatBox*, uint64_t, String*, String*, MethodInfo*>("ChatBox::AppendMessage");
static void Template_ChatBox_AppendMessage(ChatBox* a, uint64_t b, String* c, String* d, MethodInfo* method)
{
	std::cout << "ChatBox::AppendMessage" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	if (HFEvent_ChatBox_AppendMessage->RunBefore(a, b, c, d, method) == false) return;

	HF_ChatBox_AppendMessage->original(a, b, c, d, method);
}
*/

/*

static HookFunction<void, ChatBox*, MethodInfo*>* HF_ChatBox_Update = new HookFunction<void, ChatBox*, MethodInfo*>("ChatBox::Update");
static HookFunctionEvent<void, ChatBox*, MethodInfo*>* HF_Event_ChatBox_Update = new HookFunctionEvent<void, ChatBox*, MethodInfo*>("ChatBox::Update");
static void Template_ChatBox_Update(ChatBox * a, MethodInfo * method)
{
	std::cout << "ChatBox::Update" << " a=" << a << ", " << std::endl;

	if(HF_Event_ChatBox_Update->RunBefore() == false) return;

	HF_ChatBox_Update->original(a, method);

	HF_Event_ChatBox_Update->RunAfter();
}
*/

static void Inject_Templates()
{
	//Injector::Inject(HF_ChatBox_AppendMessage, ChatBox_AppendMessage, &Template_ChatBox_AppendMessage);
}



/*
auto HF_ChatBox_Update = new HookFunction<void, ChatBox*, MethodInfo*>("ChatBox::Update");
void Template_ChatBox_Update(ChatBox* a, MethodInfo* method)
{
	//std::cout << "ChatBox::Update" << " a=" << a << ", " << std::endl;

	HF_ChatBox_Update->original(a, method);

	//Chat::SendAllMessagesInQuery();
}

auto HF_ChatBox_AppendMessage = new HookFunction<void, ChatBox*, uint64_t, String*, String*, MethodInfo*>("ChatBox::AppendMessage");
void Template_ChatBox_AppendMessage(ChatBox* a, uint64_t b, String* c, String* d, MethodInfo* method)
{
	//std::cout << "ChatBox::AppendMessage" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;

	if (b == 0) return;

	HF_ChatBox_AppendMessage->original(a, b, c, d, method);
}

void Inject_Templates()
{
	Injector::Inject(HF_ChatBox_Update, ChatBox_Update, &Template_ChatBox_Update);
	Injector::Inject(HF_ChatBox_AppendMessage, ChatBox_AppendMessage, &Template_ChatBox_AppendMessage);
}
*/












/*
* auto HF_ChatBox_AppendMessage = new HookFunction<void, ChatBox*, uint64_t, String*, String*, MethodInfo*>("ChatBox::AppendMessage");
void Template_ChatBox_AppendMessage(ChatBox* a, uint64_t b, String* c, String* d, MethodInfo* method)
{
	std::cout << "ChatBox::AppendMessage" << " a=" << a << ", " << " b=" << b << ", " << " c=" << c << ", " << " d=" << d << ", " << std::endl;



	HF_ChatBox_AppendMessage->original(a, b, c, d, method);
}

*/

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