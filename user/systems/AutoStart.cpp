#include "pch-il2cpp.h"
#include "AutoStart.h"

#include "Chat.h"
#include "Server.h"
#include "Mod.h"

bool AutoStart::Enabled = false;
float AutoStart::Time = 5.0f;
float AutoStart::TimeUntilAutoStart = 0;

bool _starting = false;

void AutoStart::Update(float dt)
{
	if (!Server::IsAtLobby())
		return;

	if (!Enabled)
		return;

	if (GetActivePlayersCount() <= 1)
	{
		TimeUntilAutoStart = 0;
		return;
	}

	if (_starting)
		return;

	if (TimeUntilAutoStart == 0)
		StartCooldown();

	if (TimeUntilAutoStart <= 0)
		return;

	TimeUntilAutoStart -= dt;

	if (TimeUntilAutoStart <= 0)
	{
		_starting = true;
		Mod::SetAllPlayersReady();
		Chat::SendServerMessage("starting game in 3 seconds");
	}
}

void AutoStart::OnMapLoad(int map, int mode)
{
}

void AutoStart::OnMapStart()
{
	_starting = false;

	if (Enabled && Server::IsAtLobby())
	{
		StartCooldown();
	}
}

void AutoStart::SetEnabled(bool enabled)
{
	Enabled = enabled;
	TimeUntilAutoStart = 0;

	if (Enabled && Server::IsAtLobby())
	{
		StartCooldown();
	}
}

void AutoStart::StartCooldown()
{
	TimeUntilAutoStart = Time;

	if (GetActivePlayersCount() >= 2)
	{
		Chat::SendServerMessage("starting game in " + std::to_string(TimeUntilAutoStart) + " seconds");
	}
	else
	{
		Chat::SendServerMessage("need more players to start game");
	}
}

int AutoStart::GetActivePlayersCount()
{
	auto activePlayers = (*GameManager__TypeInfo)->static_fields->Instance->fields.activePlayers;
	return activePlayers->fields.count;
}