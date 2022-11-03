#pragma once

class AutoStart {
public:
	static bool Enabled;
	static float Time;
	static float TimeUntilAutoStart;
	static int MinPlayers;

	static void Update(float dt);
	static void OnMapLoad(int map, int mode);
	static void OnMapStart();
	static void SetEnabled(bool enabled);
	static void StartCooldown();
	static void StopCooldown();
	static int GetActivePlayersCount();
};