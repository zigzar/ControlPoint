//3

#include <stdio.h>
#include <conio.h>
#include <iostream>

using namespace std;

int choice1;

void cls() {
	system("cls");
}

void menu1() {
	_getch();
	char ch;
	int choice = 0;
	int options = 3;
	string Disp[3][2];
	Disp[0][0] = "-";
	Disp[1][0] = " ";
	Disp[2][0] = " ";
	Disp[0][1] = "Вход в систему";
	Disp[1][1] = "Регистрация в системе";
	Disp[2][1] = "Выход из программы";
	cls();
	for (int i = 0; i < options - 1; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << Disp[i][j];
		}
		cout << endl;
	}
	do {
		ch = _getch();
		switch (ch)
		{
		case 72: //Вверх
			++choice;
			for (int i = 0; i < options - 1; i++)
			{
				Disp[i][0] = " ";
			}
			Disp[choice%options][0] = "-";
			cls();
			for (int i = 0; i < options - 1; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					cout << Disp[i][j];
				}
				cout << endl;
			}
			break;
		case 119: //w
			++choice;
			for (int i = 0; i < options - 1; i++)
			{
				Disp[i][0] = " ";
			}
			Disp[choice % options][0] = "-";
			cls();
			for (int i = 0; i < options - 1; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					cout << Disp[i][j];
				}
				cout << endl;
			}
			break;
		case 80: //Вниз
			--choice;
			for (int i = 0; i < options - 1; i++)
			{
				Disp[i][0] = " ";
			}
			Disp[choice % options][0] = "-";
			cls();
			for (int i = 0; i < options - 1; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					cout << Disp[i][j];
				}
				cout << endl;
			}
			break;
		case 115: //s
			--choice;
			for (int i = 0; i < options - 1; i++)
			{
				Disp[i][0] = " ";
			}
			Disp[choice % options][0] = "-";
			cls();
			for (int i = 0; i < options - 1; i++)
			{
				for (int j = 0; j < 2; j++)
				{
					cout << Disp[i][j];
				}
				cout << endl;
			}
			break;
		}
	} while (ch != 13); //enter
}



int main()
{
	menu1();

	return 0;
}