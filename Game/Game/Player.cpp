#include "pch.h"
#include "core.h"

int Player[PLAYER_SIZE][PLAYER_SIZE] = 
{
	0,0,0,0,
	0,1,1,0,
	0,1,1,0,
	0,1,1,0
};

int player_x_pos;
int player_y_pos;
bool jump = false;
int jump_time = 0;

void KeyInput()
{
	int key;
	if (_kbhit())
	{
		key = _getch();
		if (key == 224)
		{
			key = _getch();
			switch (key)
			{
			case UP:
				if (PlayerAndWall(0, 1))
					jump = true;
				break;
			case LEFT:
				if (!PlayerAndWall(-1, 0))
				{
					if (PlayerAndObs(-1, 0))
						GameOver();
					Move_player(-1, 0);
				}
				break;
			case RIGHT:
				if (!PlayerAndWall(1, 0))
				{
					if (PlayerAndObs(1, 0))
						GameOver();
					Move_player(1, 0);
				}
				break;
			/*case DOWN:
				if (!PlayerAndWall(0, 1))
					Move_player(0, 1);
				break;*/
			}
		}
	}
	if (!jump)
		gravity();
	else
		do_jump();
}

void Set_player()
{
	player_x_pos = 5;
	player_y_pos = 5;

	for (int i = 0; i < PLAYER_SIZE; i++)
	{
		for (int j = 0; j < PLAYER_SIZE; j++)
		{
			if (Player[i][j] == 1)
				Buffer[player_y_pos + i][player_x_pos + j] = PLAYER;
		}
	}
}


void gravity()
{
	if (!PlayerAndWall(0, 1))
	{
		if (PlayerAndObs(0, 1))
			GameOver();
		Move_player(0, 1);
	}
}


void Move_player(int x, int y)
{
	for (int i = 0; i < PLAYER_SIZE; i++)
	{
		for (int j = 0; j < PLAYER_SIZE; j++)
		{
			if (Player[i][j] == 1)
				Buffer[player_y_pos + i][player_x_pos + j] = EMPTY;
		}
	}

	for (int i = 0; i < PLAYER_SIZE; i++)
	{
		for (int j = 0; j < PLAYER_SIZE; j++)
		{
			if (Player[i][j] == 1)
				Buffer[player_y_pos + i + y][player_x_pos + j + x] = PLAYER;
		}
	}
	player_x_pos = player_x_pos + x;
	player_y_pos = player_y_pos + y;


}

void do_jump()
{
	if (!PlayerAndWall(0, -1))
	{
		if (PlayerAndObs(0, -1))
			GameOver();
		Move_player(0, -1);
		jump_time++;
	}
	
	if (jump_time == JUMP_TIME)
	{
		jump = false;
		jump_time = 0;
	}
}

