#include "pch-il2cpp.h"
#include "AutoStart.h"

#include "Chat.h"
#include "Server.h"
#include "Mod.h"

bool AutoStart::Enabled = false;
float AutoStart::Time = 5.0f;
float AutoStart::TimeUntilAutoStart = 0;
int AutoStart::MinPlayers = 2;

bool _starting = false;

void AutoStart::Update(float dt)
{
	if (!Server::IsAtLobby())
		return;

	if (!Enabled)
		return;

	if (GetActivePlayersCount() < MinPlayers)
	{
		if (TimeUntilAutoStart > 0 || _starting)
		{
			std::cout << "[AutoStart] Not enough players anymore" << std::endl;
			StopCooldown();
		}
		
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
	std::cout << "[AutoStart] StartCooldown" << std::endl;

	TimeUntilAutoStart = Time;

	if (GetActivePlayersCount() < MinPlayers)
	{
		StopCooldown();
		Chat::SendServerMessage("[auto-start] need more players to start game");
		return;
	}

	Chat::SendServerMessage("[auto-start] starting game in " + std::to_string((int)TimeUntilAutoStart) + " seconds");
}

void AutoStart::StopCooldown()
{
	std::cout << "[AutoStart] StopCooldown" << std::endl;

	TimeUntilAutoStart = 0.0f;
	_starting = false;
}

int AutoStart::GetActivePlayersCount()
{
	int count = 0;

	auto activePlayers = (*GameManager__TypeInfo)->static_fields->Instance->fields.activePlayers;
	for (size_t i = 0; i < activePlayers->fields.count; i++)
	{
		long long key = activePlayers->fields.entries->vector[i].key;

		if (!Server::HasPlayer(key)) continue;

		if (Server::GetPlayer(key)->IsOnline) count++;
	}

	return count;
}