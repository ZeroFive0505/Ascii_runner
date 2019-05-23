#include "pch.h"
#include "core.h"

void ObsMove(int x, int y)
{

	for (int i = 0; i < OBS_SIZE; i++)
	{
		for (int j = 0; j < OBS_SIZE; j++)
		{
			if (Obstacles[type][i][j] == 1)
				Buffer[obs_y_pos + i][obs_x_pos + j] = EMPTY;
		}
	}

	for (int i = 0; i < OBS_SIZE; i++)
	{
		for (int j = 0; j < OBS_SIZE; j++)
		{
			if (Obstacles[type][i][j] == 1)
			{
				if (Buffer[obs_y_pos + i + y][obs_x_pos + j + x] == PLAYER)
					GameOver();
				Buffer[obs_y_pos + i + y][obs_x_pos + j + x] = OBSTACLE;
			}
		}
	}

	obs_x_pos = obs_x_pos + x;
	obs_y_pos = obs_y_pos + y;
}