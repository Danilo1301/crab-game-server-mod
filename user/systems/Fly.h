#pragma once

#include "pch.h"

#include "Player.h"

class Fly {
public:
	static void Update(float dt);
	static void OnPunch(Player* player);
};