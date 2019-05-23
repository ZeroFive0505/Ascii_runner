#include "pch.h"
#include "core.h"


int Screen[HEIGHT][WIDTH+OBS_SIZE+OBS_SIZE];
int Buffer[HEIGHT][WIDTH+OBS_SIZE+OBS_SIZE];

void GotoXY(int x, int y)
{
	COORD new_pos = { x*2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), new_pos);
}

void Set_buffer()
{

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
			Buffer[i][j] = EMPTY;
	}

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = OBS_SIZE; j < WIDTH-OBS_SIZE; j++)
		{
			if (i == 0 || j == OBS_SIZE)
				Buffer[i][j] = VISIBLE_WALL;
			else if (i == HEIGHT - 1 || j == WIDTH-OBS_SIZE-1)
				Buffer[i][j] = VISIBLE_WALL;
		}
	}

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH + OBS_SIZE + OBS_SIZE; j++)
		{
			if ((i == 0 || j == 0) && Buffer[i][j] != VISIBLE_WALL)
				Buffer[i][j] = REAL_WALL;
			else if ((i == HEIGHT - 1) && Buffer[i][j] != VISIBLE_WALL)
				Buffer[i][j] = REAL_WALL;
		}
	}
}


void DrawWorld()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			if ((i == 0 || j == OBS_SIZE) && Buffer[i][j] == EMPTY)
				Buffer[i][j] = VISIBLE_WALL;
			if ((i == HEIGHT - 1 || j == WIDTH - OBS_SIZE - 1) && Buffer[i][j] == EMPTY)
				Buffer[i][j] = VISIBLE_WALL;

			if (Buffer[i][j] != Screen[i][j])
			{
				Screen[i][j] = Buffer[i][j];

				switch (Screen[i][j])
				{
				case PLAYER:
					GotoXY(j, i);
					printf("¡à");
					break;
				case EMPTY:
					GotoXY(j, i);
					printf(" ");
					break;
				case VISIBLE_WALL:
					GotoXY(j, i);
					printf("¢Ì");
					break;
				case OBSTACLE:
					if (j < WIDTH - OBS_SIZE-1 && j > OBS_SIZE)
					{
						GotoXY(j, i);
						printf("¡Ý");
					}
					break;
				}
			}
		}
	}
}

void Intro()
{
	GotoXY(18, 10);
	printf("WELCOME To ASCII RUNNER!\n");
	GotoXY(18, 11);
	printf("Press Any keys to continue\n");
	PlaySound(TEXT(BGM_PATH), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	while (_kbhit())
		_getch();
	_getch();
	system("cls");
	Set_screen();
	Set_buffer();
}


void Set_screen()
{
	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			Screen[i][j] = 1000;
		}
	}
}

void RemoveCursor()
{
	CONSOLE_CURSOR_INFO info = { 0, };
	info.dwSize = 1;
	info.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void RemoveBar()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
}

void ConsoleSize()
{
	system("mode con cols=100 lines=40");
}