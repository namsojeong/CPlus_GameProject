#include"Console.h"

char map[HEIGHT][WEIGHT];

int main()
{
	srand((unsigned int)time(NULL));

	// ó�� ����
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

	// �����÷���
	while (true)
	{
		OutputMap(map, &tPlayer);
		
		char cInput = _getch();

		// ����â�� �� ���ΰ�?
		if (GetAsyncKeyState(VK_ESCAPE) & 0X8000) SettingTab();

		// ��� �ݱ�
		if (cInput == 'e' || cInput == 'E')
		{
			GetObject(map, &tPlayer);
		}
		// ��� ����
		else if (cInput == 'q' || cInput == 'Q')
		{
			putObject(map, &tPlayer);
		}

		// �÷��̾� �̵�
		MovePlayer(map, &tPlayer);
	}

	return 0;
}
