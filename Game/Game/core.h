#pragma once
#include <stdio.h>
#include <Windows.h>
#include <stdbool.h>
#include <mmsystem.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#pragma comment(lib, "winmm.lib")

#define BGM_PATH "C:\\Users\\Admin\\source\\Ascii_runner\\4-11 - Athletic BGM.wav"

#define WIDTH 50
#define HEIGHT 24
#define OBS_SIZE 4
#define TYPES 5
#define LEFT 75
#define RIGHT 77
#define DOWN 80
#define UP 72
#define JUMP_TIME 12

#define PLAYER_SIZE 4

extern bool new_obsFlag;
extern bool jump;
extern int type;
extern int obs_x_pos;
extern int obs_y_pos;
extern int player_x_pos;
extern int player_y_pos;
extern int score;
extern int Buffer[HEIGHT][WIDTH+OBS_SIZE+OBS_SIZE];
extern int Screen[HEIGHT][WIDTH+OBS_SIZE+OBS_SIZE];
extern int Obstacles[TYPES][OBS_SIZE][OBS_SIZE];
extern int Player[PLAYER_SIZE][PLAYER_SIZE];

enum { PLAYER = 1, EMPTY, VISIBLE_WALL, REAL_WALL, OBSTACLE };


//Drawer.cpp
void GotoXY(int, int);
void Set_buffer();
void DrawWorld();
void Intro();
void Set_screen();
void RemoveCursor();
void RemoveBar();
void ConsoleSize();


//Obstacle_maker.cpp
void Create_obs();


//Obstacle_mover.cpp
void ObsMove(int, int);

//Player.Cpp
void Set_player();
void KeyInput();
void gravity();
void Move_player(int, int);
void do_jump();

//CollisionDetect.cpp
bool WallAndObs(int, int);
bool PlayerAndWall(int, int);
bool PlayerAndObs(int, int);
void Destroy();


//GameManager.cpp
void GameOver();
void Print_score();
void Re_try();
void Reset_score();