#include "Game.h"

// ����â
void SettingTab()
{
	// ����â ���
	{
	system("cls");
	gotoxy(0, 0);
	wcout << "��������������������������������������" << endl;
	wcout << "��									��" << endl;
	wcout << "��									��" << endl;
	wcout << "��				1 : ���ư���				��" << endl;
	wcout << "��				2 : ���� ����				��" << endl;
	wcout << "��									��" << endl;
	wcout << "��									��" << endl;
	wcout << "��������������������������������������" << endl;
	}

	// ���� �ޱ�
	{
		char cInput = _getch();
		switch (cInput)
		{
		case '1': //���ư���
		{
			break;
		}
		case '2': //��������
		{
			cout << "���� ����" << endl;
			exit(0);
			break;
		}
		}
	}
	
}
