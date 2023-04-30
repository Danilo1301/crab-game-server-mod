#pragma once

#include "pch.h"

enum WEAPON {
	NONE = -1,
	AK,
	GLOCK,
	REVOLVER,
	DUAL,
	BAT,
	BOMB,
	KATANA,
	KNIFE,
	PIPE,
	SNOWBALL,
	STICK,
	MILK,
	PIZZA,
	GRENADE
};

struct Weapon {
	std::string name;
	int id;
};

static std::vector<Weapon> WeaponList = {
	//{ "None", WEAPON::NONE },
	{ "Ak", WEAPON::AK },
	{ "Glock", WEAPON::GLOCK },
	{ "Revolver", WEAPON::REVOLVER },
	{ "Dual", WEAPON::DUAL },
	{ "Bat", WEAPON::BAT },
	{ "Bomb", WEAPON::BOMB },
	{ "Katana", WEAPON::KATANA },
	{ "Knife", WEAPON::KNIFE },
	{ "Pipe", WEAPON::PIPE },
	{ "Snowball", WEAPON::SNOWBALL },
	{ "Stick", WEAPON::STICK },
	{ "Milk", WEAPON::MILK },
	{ "Pizza", WEAPON::PIZZA },
	{ "Grenade", WEAPON::GRENADE }
};

static Weapon* GetWeaponById(int weaponId)
{
	for (auto& weapon : WeaponList)
	{
		if (weaponId == weapon.id) return &weapon;
	}
	return NULL;
}


static bool WeaponIdExists(int weaponId)
{
	return GetWeaponById(weaponId) != NULL;
}