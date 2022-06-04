#pragma once
#include"Console.h"

const int HEIGHT = 30;
const int WEIGHT = 51;

// ��ġ
typedef struct _pos
{
public:
	int x, y;
}POS, * PPOS;

// ����
typedef struct _dir
{
	int isUp;
	int isDown;
	int isLeft;
	int isRight;
}DIR, *PDIR;

// ���
typedef struct _ingredient
{
	bool bFlour;
	bool bTomato;
	bool bCheese;
	char holdState;
}ING, * PING;

// �÷��̾�
typedef struct _player
{
	_pos tPos;
	_dir tDir;
	_ingredient tIng;
	bool isHave;
bool isScary;
}PLAYER, *PPLAYER;


// �÷��̾� ������
void MovePlayer(char map[HEIGHT][WEIGHT],PPLAYER pPlayer);
void MoveUp(char map[HEIGHT][WEIGHT], PPLAYER pPlayer);
void MoveDown(char map[HEIGHT][WEIGHT], PPLAYER pPlayer);
void MoveLeft(char map[HEIGHT][WEIGHT], PPLAYER pPlayer);
void MoveRight(char map[HEIGHT][WEIGHT], PPLAYER pPlayer);

// �÷��̾�
void DirChange(char dir, PPLAYER pPlayer);
char GetDir(PPLAYER pPlayer);

// ��� ���
void GetObject(char map[HEIGHT][WEIGHT], PPLAYER pPlayer);
// ��� BOOL�� 
void ItemHold(char item, PPLAYER pPlayer);
// ��� ��������
void putObject(char map[HEIGHT][WEIGHT], PPLAYER pPlayer);

// Title ���
void PrintTitle();

// Fail ����
void PrintHorror(PPLAYER pPlayer);

// Map ����
void SetMap(char map[HEIGHT][WEIGHT]);
// Map ���
void OutputMap(char map[HEIGHT][WEIGHT], PPLAYER pPlayer);

