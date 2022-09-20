#pragma once

#include "pch.h"

class EquipItem {
public:
	static bool Enabled;

	static void Update();
	static void Equip(long long clientId, int weaponId);
};