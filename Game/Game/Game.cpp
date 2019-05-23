
#include "pch.h"
#include "core.h"

int main()
{
	srand((unsigned)time(NULL));
	ConsoleSize();
	RemoveBar();
	RemoveCursor();
	Set_buffer();
	Set_screen();
	DrawWorld();
	Intro();
	Set_player();
	DrawWorld();
	Print_score();
	Create_obs();

	while (1)
	{

		for (int i = 0; i < 5; i++)
		{
			KeyInput();
		}

		if (!WallAndObs(-1, 0))
			ObsMove(-1, 0);
			
		DrawWorld();
		Sleep(150);
		if (new_obsFlag)
		{
			Print_score();
			Create_obs();
		}
			
	}
	return 0;
}