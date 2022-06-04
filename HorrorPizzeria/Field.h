#pragma once
#include"Console.h"

const int HEIGHT = 30;
const int WEIGHT = 51;

// 위치
typedef struct _pos
{
public:
	int x, y;
}POS, * PPOS;

// 방향
typedef struct _dir
{
	int isUp;
	int isDown;
	int isLeft;
	int isRight;
}DIR, *PDIR;

// 재료
typedef struct _ingredient
{
	bool bFlour;
	bool bTomato;
	bool bCheese;
	char holdState;
}ING, * PING;

// 플레이어
typedef struct _player
{
	_pos tPos;
	_dir tDir;
	_ingredient tIng;
	bool isHave;
bool isScary;
}PLAYER, *PPLAYER;


// 플레이어 움직임
void MovePlayer(char map[HEIGHT][WEIGHT],PPLAYER pPlayer);
void MoveUp(char map[HEIGHT][WEIGHT], PPLAYER pPlayer);
void MoveDown(char map[HEIGHT][WEIGHT], PPLAYER pPlayer);
void MoveLeft(char map[HEIGHT][WEIGHT], PPLAYER pPlayer);
void MoveRight(char map[HEIGHT][WEIGHT], PPLAYER pPlayer);

// 플레이어
void DirChange(char dir, PPLAYER pPlayer);
char GetDir(PPLAYER pPlayer);

// 재료 담기
void GetObject(char map[HEIGHT][WEIGHT], PPLAYER pPlayer);
// 재료 BOOL값 
void ItemHold(char item, PPLAYER pPlayer);
// 재료 내려놓기
void putObject(char map[HEIGHT][WEIGHT], PPLAYER pPlayer);

// Title 출력
void PrintTitle();

// Fail 띄우기
void PrintHorror(PPLAYER pPlayer);

// Map 저장
void SetMap(char map[HEIGHT][WEIGHT]);
// Map 출력
void OutputMap(char map[HEIGHT][WEIGHT], PPLAYER pPlayer);

