#include "pch-il2cpp.h"
#include "Whitelist.h"

#include "Mod.h"

std::vector<long long> Whitelist::PlayerIds;

bool Whitelist::Enabled = false;

bool Whitelist::HasId(long long id)
{
	return std::find(PlayerIds.begin(), PlayerIds.end(), id) != PlayerIds.end();
}

void Whitelist::AddId(long long id)
{
	if (HasId(id)) return;

	PlayerIds.push_back(id);
}

void Whitelist::RemoveId(long long id)
{
	if (!HasId(id)) return;

	PlayerIds.erase(std::find(PlayerIds.begin(), PlayerIds.end(), id));
}

bool Whitelist::CanIdJoin(long long id)
{
	if (!Enabled) return true;
	
	std::cout << "[Server] Testing whitelist " << id << std::endl;

	if (Mod::GetMySteamId() == id)
	{
		std::cout << "[Server] Lobby owner, ignoring" << std::endl;
		return true;
	}

	if (HasId(id)) return true;

	std::cout << "[Server] Player " << id << " is not on whitelist" << std::endl;

	return false;
}

void Whitelist::SaveToFile()
{
	//PAREI
}

void Whitelist::LoadFromFile()
{

}