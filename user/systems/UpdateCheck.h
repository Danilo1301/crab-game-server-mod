#pragma once

#include "pch.h"

class UpdateCheck {
public:
	static bool HasCheckedUpdates;

	static bool Check();
};