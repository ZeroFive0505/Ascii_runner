#include "pch.h"
#include "core.h"

int score;

bool WallAndObs(int x, int y)
{
	for (int i = 0; i < OBS_SIZE; i++)
	{
		for (int j = 0; j < OBS_SIZE; j++)
		{
			if (Obstacles[type][i][j] == 1 && Buffer[obs_y_pos + i + y][obs_x_pos + j + x] == REAL_WALL)
			{
				Destroy();
				new_obsFlag = true;
				return true;
			}
				
		}
	}

	return false;
}

bool PlayerAndWall(int x, int y)
{
	for (int i = 0; i < PLAYER_SIZE; i++)
	{
		for (int j = 0; j < PLAYER_SIZE; j++)
		{
			if (Player[i][j] == 1 && Buffer[player_y_pos + i + y][player_x_pos + j + x] == VISIBLE_WALL)
				return true;
		}
	}
	return false;
}

bool PlayerAndObs(int x, int y)
{
	for (int i = 0; i < PLAYER_SIZE; i++)
	{
		for (int j = 0; j < PLAYER_SIZE; j++)
		{
			if (Player[i][j] == 1 && Buffer[player_y_pos + i + y][player_x_pos + j + x] == OBSTACLE)
				return true;
		}
	}

	return false;
}

void Destroy()
{
	for (int i = 0; i < OBS_SIZE; i++)
	{
		for (int j = 0; j < OBS_SIZE; j++)
		{
			if(Obstacles[type][i][j] == 1)
				Buffer[obs_y_pos + i][obs_x_pos + j] = EMPTY;
		}
	}
	score += 100;
}