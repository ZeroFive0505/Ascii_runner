#include "pch.h"
#include "core.h"

int Obstacles[TYPES][OBS_SIZE][OBS_SIZE] = 
{
	{
		0,0,1,0,
		0,0,1,1,
		0,0,1,1,
		0,0,1,1
	},

	{
		1,1,0,0,
		0,1,0,0,
		0,1,1,1,
		0,1,1,1
	},

	{
		0,0,0,0,
		0,0,0,0,
		0,1,1,1,
		0,1,1,1
	},

	{
		1,0,0,0,
		1,0,0,0,
		1,0,0,0,
		1,1,1,1
	},

	{
		0,1,1,0,
		0,1,1,0,
		0,1,1,0,
		0,1,1,0
	}
};
bool new_obsFlag = true;
int type;
int obs_x_pos;
int obs_y_pos;

void Create_obs()
{
	type = rand() % TYPES;
	obs_x_pos = (WIDTH + OBS_SIZE)- 1;
	obs_y_pos = HEIGHT - OBS_SIZE - 1;
	for (int i = 0; i < OBS_SIZE; i++)
	{
		for (int j = 0; j < OBS_SIZE; j++)
		{
			if (Obstacles[type][i][j] == 1)
				Buffer[obs_y_pos + i][obs_x_pos + j] = OBSTACLE;
		}
	}
	new_obsFlag = false;
}