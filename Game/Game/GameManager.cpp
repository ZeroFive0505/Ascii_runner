#include "pch.h"
#include "core.h"


void GameOver()
{
	int ch = 0;
	for (int i = 1; i < HEIGHT - 1; i++)
	{
		for (int j = OBS_SIZE+1; j < WIDTH - 1; j++)
		{
			Buffer[i][j] = EMPTY;
		}
	}

	DrawWorld();

	GotoXY(18, 10);
	printf("Game Over\n");
	GotoXY(18, 11);
	printf("Press Any keys to continue\n");
	GotoXY(18, 12);
	printf("Press Q to quit the game\n");
	while (_kbhit())
		_getch();
	ch = _getch();
	if (ch == 'q')
		exit(EXIT_SUCCESS);
	else
		Re_try();
}

void Print_score()
{
	GotoXY(8, 3);
	printf("Your Score : %d \n", score);
}

void Re_try()
{
	system("cls");
	Set_buffer();
	Set_screen();
	DrawWorld();
	Reset_score();
	Set_player();
	DrawWorld();
	Print_score();
	Create_obs();
}

void Reset_score()
{
	score = 0;
}