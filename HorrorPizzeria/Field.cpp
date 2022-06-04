#include "Field.h"

// Title 출력
void PrintTitle()
{
	gotoxy(0, 0);
	wcout << L"    __  ______ _____   ______" << endl;
	wcout << L"   /  |/  /   /__  /  / ____/" << endl;
	wcout << L"  /  |/  /   /__  /  / ____/ " << endl;
	wcout << L" / /  / / ___ |/ /__/ /___   " << endl;
	wcout << L"/_/  /_/_/  |_/____/_____/    " << endl;
	cout << endl;
}

// Fail 띄우기
void PrintHorror(PPLAYER pPlayer)
{
	pPlayer->isScary = true;
	system("cls");
	cout<<"	 . _＿＿＿_＿	"<<endl;
	cout<<"	 ／ 　     　　＼　"<<endl;
	cout<<"	 ／    _ノ  　ヽ_＼	"<<endl;
	cout<<"	／   　（●）（●）＼	"<<endl;	
	cout<<"	|　  ///（_人_）///| 여기 이걸 왜 넣어...		"<<endl;
	cout<<"	＼   　　 　　    ／	"<<endl;
	cout<<"	／　 　　 　    　＼	"<<endl;

	Sleep(3000);
	pPlayer->isScary = false;
}

// 0:플레이어 1:벽 2:길 3:빵 반죽 4:토마토소스 5:치즈

// Map 세팅
void SetMap(char map[HEIGHT][WEIGHT])
{
	strcpy_s(map[0], "1111111111111111111111111111111111111111111111111");
	strcpy_s(map[1], "1222222222222122222222222222122222222222222222221");
	strcpy_s(map[2], "1222222222222112222222222222122222222222222222221");
	strcpy_s(map[3], "1222222222222312222222222222122222222222222222221");
	strcpy_s(map[4], "1222222222222112222222222222122222222222222222221");
	strcpy_s(map[5], "1222222222222112222222222222122222222222222222221");
	strcpy_s(map[6], "1222222222222412222222222222122222222222222222221");
	strcpy_s(map[7], "1222222222222112222222222222122222222222222222221");
	strcpy_s(map[8], "1222222222222112222222222222122222222222222222221");
	strcpy_s(map[9], "1222222222222512222222222222122222222222222222221");
	strcpy_s(map[10], "1222222222222112222222222222122222222222222222221");
	strcpy_s(map[11], "1222222221111222222222222222122222222222222222221");
	strcpy_s(map[12], "1222222222222222222222222222122222222222222222221");
	strcpy_s(map[13], "1222222222222222222222222222122222222222222222221");
	strcpy_s(map[14], "1222222222222222222222222222122222222222222222221");
	strcpy_s(map[15], "1222222222222222222222222222122222222222222222221");
	strcpy_s(map[16], "1222222222222222222222222222122222222222222222221");
	strcpy_s(map[17], "1222222222222222222222222222122222222222222222221");
	strcpy_s(map[18], "1222222222222222222222222222122222222222222222221");
	strcpy_s(map[19], "1222222222222222222222222222122222222222222222221");
	strcpy_s(map[20], "1222222222222222222222222222122222222222222222221");
	strcpy_s(map[21], "1222222222222222222222222222122222222222222222221");
	strcpy_s(map[22], "1222222222222222222222222222122222222222222222221");
	strcpy_s(map[23], "1222222222222222222222222222122222222222222222221");
	strcpy_s(map[24], "1222222222222222222222222222122222222222222222221");
	strcpy_s(map[25], "1222222222222222222222222222122222222222222222221");
	strcpy_s(map[26], "1222222222222222222222222222122222222222222222221");
	strcpy_s(map[27], "1222222222222222222222222222122222222222222222221");
	strcpy_s(map[28], "1222222222222222222222222222122222222222222222221");
	strcpy_s(map[29], "1111111111111111111111111111111111111111111111111");
}

// Map 출력
void OutputMap(char map[HEIGHT][WEIGHT],PPLAYER pPlayer)
{
	if (pPlayer->isScary) return;
	gotoxy(0, 0);
	SetColor(BLACK, BCOLOR);

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WEIGHT; j++)
		{
				// 플레이어 출력
				if (pPlayer->tPos.x == j && pPlayer->tPos.y == i)
				{
					SetColor(BLUE, BCOLOR);

					if (pPlayer->tDir.isUp == 1) {
						cout << "↑";
					}
					else if (pPlayer->tDir.isDown == 1) {
						cout << "↓";
					}
					else if (pPlayer->tDir.isLeft == 1) {
						cout << "←";
					}
					else if (pPlayer->tDir.isRight == 1) {
						cout << "→";
					}
					continue;
				}

				// 바구니 출력
				if (pPlayer->tPos.x - 1 == j && pPlayer->tPos.y == i)
				{
					if (pPlayer->isHave)
					{
						if (pPlayer->tIng.bFlour)
						{
							SetColor(BROWN, BCOLOR);
							cout << "●";
						}
						else if (pPlayer->tIng.bTomato)
						{
							SetColor(RED, BCOLOR);
							cout << "●";
						}
						else if (pPlayer->tIng.bCheese)
						{
							SetColor(GREEN, BCOLOR);
							cout << "※";
						}
					}
					else
					{
						SetColor(BLACK, BCOLOR);
						cout << "□";
					}
					continue;
				}

				// 맵 + 재료 출력
				switch (map[i][j])
				{
				case '1':
					SetColor(BLACK, BCOLOR);
					cout << "■";
					break;
				case '2':
					cout << "  ";
					break;
				case '3':
					SetColor(BROWN, BCOLOR);
					cout << "●";
					break;
				case '4':
					SetColor(RED, BCOLOR);
					cout << "●";
					break;
				case '5':
					SetColor(GREEN, BCOLOR);
					cout << "※";
					break;
				default:
					break;
				}
		}
		cout << endl;
	}

	// 키 설명
	{
		gotoxy(0, 31);
		wcout << "■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■" << endl;
		wcout << "■									■" << endl;
		wcout << "■									■" << endl;
		wcout << "■				방향키 : 움직이기			■" << endl;
		wcout << "■				E : 들기				■" << endl;
		wcout << "■				Q : 놓기				■" << endl;
		wcout << "■				ESC : 설정창				■" << endl;
		wcout << "■									■" << endl;
		wcout << "■									■" << endl;
		wcout << "■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■" << endl;
	}
	
}

// 플레이어 이동
void MovePlayer(char map[HEIGHT][WEIGHT], PPLAYER pPlayer)
{
	if (GetAsyncKeyState(VK_UP) & 0X8000)
	{
		DirChange('U', pPlayer);
		MoveUp(map, pPlayer);
		Sleep(90);
	}
	else if (GetAsyncKeyState(VK_DOWN) & 0X8000)
	{
		DirChange('D', pPlayer);
		MoveDown(map, pPlayer);
		Sleep(90);
	}
	else if (GetAsyncKeyState(VK_LEFT) & 0X8000)
	{
		DirChange('L', pPlayer);
		MoveLeft(map, pPlayer);
		Sleep(90);
	}
	else if (GetAsyncKeyState(VK_RIGHT) & 0X8000)
	{
		DirChange('R', pPlayer);
		MoveRight(map, pPlayer);
		Sleep(90);
	}
}
void MoveUp(char map[HEIGHT][WEIGHT], PPLAYER pPlayer)
{
	if (map[pPlayer->tPos.y - 1][pPlayer->tPos.x] != '2') return;
	if (pPlayer->tPos.y > 1)
	{
		--pPlayer->tPos.y;
	}
}
void MoveDown(char map[HEIGHT][WEIGHT], PPLAYER pPlayer)
{
	if (map[pPlayer->tPos.y + 1][pPlayer->tPos.x] != '2') return;
	if (pPlayer->tPos.y + 1 < HEIGHT)
	{
		++pPlayer->tPos.y;
	}
}
void MoveLeft(char map[HEIGHT][WEIGHT], PPLAYER pPlayer)
{
	if (map[pPlayer->tPos.y][pPlayer->tPos.x - 2] != '2') return;
	if (pPlayer->tPos.x > 2)
	{
		--pPlayer->tPos.x;
	}
}
void MoveRight(char map[HEIGHT][WEIGHT], PPLAYER pPlayer)
{
	if (map[pPlayer->tPos.y][pPlayer->tPos.x + 1] != '2') return;
	if (pPlayer->tPos.x < WEIGHT - 4 && pPlayer->tPos.x + 1 != '1')
	{
		++pPlayer->tPos.x;
	}
}

// 방향 바꾸기
void DirChange(char dir, PPLAYER pPlayer)
{
	pPlayer->tDir.isLeft = 0;
	pPlayer->tDir.isUp = 0;
	pPlayer->tDir.isDown = 0;
	pPlayer->tDir.isRight = 0;
	if (dir == 'L')
	{
		pPlayer->tDir.isLeft = 1;
	}
	else if (dir == 'R')
	{
		pPlayer->tDir.isRight = 1;
	}
	else if (dir == 'U')
	{
		pPlayer->tDir.isUp = 1;
	}
	else if (dir == 'D')
	{
		pPlayer->tDir.isDown = 1;
	}

}
// 방향 가져오기
char GetDir(PPLAYER pPlayer)
{
	if (pPlayer->tDir.isUp == 1)
		return 'U';
	else if (pPlayer->tDir.isDown == 1)
		return 'D';
	else if (pPlayer->tDir.isLeft == 1)
		return 'L';
	else if (pPlayer->tDir.isRight == 1)
		return 'R';
}

// 재료 Bool값 바꾸기
void ItemHold(char item, PPLAYER pPlayer)
{
	pPlayer->isHave = true;

	switch (item)
	{
	case '3':
	{
		pPlayer->tIng.bFlour = true;
		break;
	}
	case '4':
	{
		pPlayer->tIng.bTomato = true;
		break;
	}

	case '5':
	{
		pPlayer->tIng.bCheese = true;
		break;
	}
	default:
		break;
	}
}
// 재료 담기
void GetObject(char map[HEIGHT][WEIGHT], PPLAYER pPlayer)
{
	if (pPlayer->isHave) return;

	if (GetDir(pPlayer) == 'U')
	{
		if (map[pPlayer->tPos.y - 1][pPlayer->tPos.x] == '2' || map[pPlayer->tPos.y - 1][pPlayer->tPos.x] == '1')return;
		ItemHold(map[pPlayer->tPos.y - 1][pPlayer->tPos.x], pPlayer);
	}
	else if (GetDir(pPlayer) == 'D')
	{
		if (map[pPlayer->tPos.y + 1][pPlayer->tPos.x] == '2' || map[pPlayer->tPos.y + 1][pPlayer->tPos.x] == '1')return;
		ItemHold(map[pPlayer->tPos.y + 1][pPlayer->tPos.x], pPlayer);
	}
	else if (GetDir(pPlayer) == 'L')
	{
		if (map[pPlayer->tPos.y][pPlayer->tPos.x - 1] == '2' || map[pPlayer->tPos.y][pPlayer->tPos.x - 1] == '1')return;
		ItemHold(map[pPlayer->tPos.y][pPlayer->tPos.x - 1], pPlayer);
	}
	else if (GetDir(pPlayer) == 'R')
	{
		if (map[pPlayer->tPos.y][pPlayer->tPos.x + 1] == '2' || map[pPlayer->tPos.y][pPlayer->tPos.x + 1] == '1')return;
		ItemHold(map[pPlayer->tPos.y][pPlayer->tPos.x + 1], pPlayer);
	}
}
// 재료 내려놓기
void putObject(char map[HEIGHT][WEIGHT], PPLAYER pPlayer)
{
	if (!pPlayer->isHave) return;
	PrintHorror(pPlayer);

	if (pPlayer->tIng.bFlour)
	{
		pPlayer->tIng.bFlour = false;
		map[pPlayer->tPos.y][pPlayer->tPos.x - 1] = '3';
	}
	else if (pPlayer->tIng.bTomato)
	{
		pPlayer->tIng.bTomato = false;
		map[pPlayer->tPos.y][pPlayer->tPos.x - 1] = '4';

	}
	else if (pPlayer->tIng.bCheese)
	{
		pPlayer->tIng.bCheese = false;
		map[pPlayer->tPos.y][pPlayer->tPos.x - 1] = '5';
	}

	pPlayer->isHave = false;
}