#include"Console.h"

char map[HEIGHT][WEIGHT];

int main()
{
	srand((unsigned int)time(NULL));

	// 처음 리셋
	POS tStartPos = { 2, 2 };
	PLAYER tPlayer;
	tPlayer.tPos.x = tStartPos.x;
	tPlayer.tPos.y = tStartPos.y;
	tPlayer.isHave = false;
	tPlayer.tIng.bCheese = false;
	tPlayer.tIng.bTomato = false;
	tPlayer.tIng.bFlour = false;
	tPlayer.isScary = false;

	DirChange('R', &tPlayer);
	SetMap(map);

	// 게임플레이
	while (true)
	{
		OutputMap(map, &tPlayer);
		
		char cInput = _getch();

		// 설정창을 열 것인가?
		if (GetAsyncKeyState(VK_ESCAPE) & 0X8000) SettingTab();

		// 재료 줍기
		if (cInput == 'e' || cInput == 'E')
		{
			GetObject(map, &tPlayer);
		}
		// 재료 놓기
		else if (cInput == 'q' || cInput == 'Q')
		{
			putObject(map, &tPlayer);
		}

		// 플레이어 이동
		MovePlayer(map, &tPlayer);
	}

	return 0;
}
