#include "Game.h"

// 설정창
void SettingTab()
{
	// 설정창 출력
	{
	system("cls");
	gotoxy(0, 0);
	wcout << "■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■" << endl;
	wcout << "■									■" << endl;
	wcout << "■									■" << endl;
	wcout << "■				1 : 돌아가기				■" << endl;
	wcout << "■				2 : 게임 종료				■" << endl;
	wcout << "■									■" << endl;
	wcout << "■									■" << endl;
	wcout << "■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■□■" << endl;
	}

	// 설정 받기
	{
		char cInput = _getch();
		switch (cInput)
		{
		case '1': //돌아가기
		{
			break;
		}
		case '2': //게임종료
		{
			cout << "게임 종료" << endl;
			exit(0);
			break;
		}
		}
	}
	
}
