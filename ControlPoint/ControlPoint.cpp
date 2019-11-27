//3
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <fstream>


using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

ifstream fin;
ofstream fout;

string path = "data.txt";

bool isAuth = false;

string curLogin;
string curPassword;

void menu();
void menu0();
bool auth();

void readFromFile(string& nameCheck, string& passCheck)
{
	ifstream fin;
	try
	{
		fin.open(path);
		getline(fin, nameCheck);
		getline(fin, passCheck);
	}
	catch (const std::exception&)
	{
		cout << "Ошибка открытия файла" << endl;
	}
}
void writeToFile(string name, string pass)
{
	ofstream fout;
	try
	{
		fout.open(path);
		fout << name << endl << pass;
		curLogin = name;
		curPassword = pass;
	}
	catch (const std::exception&)
	{
		cout << "Ошибка открытия файла" << endl;
	}
}
void reg()
{
	cout << "Регистрация: " << endl;
	cout << "Введите Логин" << endl;
	string login;
	cin >> login;
	cout << "Введите пароль" << endl;
	string pass;
	cin >> pass;
	writeToFile(login, pass);
}
bool check(string name, string pass)
{
	string nameCheck, passCheck;
	readFromFile(nameCheck, passCheck);
	curLogin = nameCheck;
	curPassword = nameCheck;
	if (name != nameCheck)
	{
		cout << "Такого пользователя не существует" << endl;
		auth();
		return false;
	}
	if (pass != passCheck)
	{
		cout << "Пароль введён невено" << endl;
		auth();
		return false;
	}
	if (name == nameCheck && pass == passCheck)
	{
		cout << "Вы успешно авторизовались" << endl;
		Sleep(1000);
		return true;
	}

}
bool auth()
{
	string name, pass;

	cout << "Авторизация (ESC для выхода): " << endl;
	cout << "Введите логин" << endl;

	while (true) {
		auto code = _getch();
		if (code == 13)
		{
			cout << endl;
			break;
		}

		if (code == 27)
		{
			menu0();
			break;
		}

		if (code == 224)
			_getch(),
			code = 8;

		if (code == 8)
		{
			cout << "\b \b";
			if (!name.empty())
				name.pop_back();
		}
		else
		{
			const auto ch = static_cast<char>(code);
			name += ch;
			cout << ch;
		}
	}

	cout << "Введите пароль" << endl;

	while (true) {
		auto code = _getch();
		if (code == 13)
		{
			cout << endl;
			break;
		}

		if (code == 27)
		{
			menu0();
			break;
		}

		if (code == 224)
			_getch(),
			code = 8;

		if (code == 8)
		{
			cout << "\b \b";
			if (!pass.empty())
				pass.pop_back();
		}
		else
		{
			const auto ch = static_cast<char>(code);
			pass += ch;
			cout << "*";
		}
	}

	return check(name, pass);
}

void flag1() {
	ifstream fin;
	try
	{
		fin.open("flag1.txt");
		string curString;
		cout << "Флаг России:" << endl << endl;
		for (int i = 0; i < 9; i++)
		{
			getline(fin, curString);
			if (i == 0) SetConsoleTextAttribute(h, 15);
			if (i == 3) SetConsoleTextAttribute(h, 9);
			if (i == 6) SetConsoleTextAttribute(h, 4);
			cout << curString << endl;
		}
		cout << endl << endl;
		Sleep(1000);
		SetConsoleTextAttribute(h, 15);
	}
	catch (const std::exception&)
	{
		cout << "Ошибка открытия файла" << endl;
	}
}

void flag2() {
	ifstream fin;
	try
	{
		fin.open("flag2.txt");
		string curString;
		cout << "Флаг Вьетнама:" << endl << endl;
		for (int i = 0; i < 22; i++)
		{
			getline(fin, curString);
			for (int j = 0; j < 68; j++)
			{
				if (curString[j] == 37) SetConsoleTextAttribute(h, 4);
				if (curString[j] == 42) SetConsoleTextAttribute(h, 6);
				cout << curString[j];
			}
			cout << endl;
		}

		SetConsoleTextAttribute(h, 15);
		cout << endl;
		cout << "ESC для выхода в главное меню...";
		char code = _getch();
		while (!(code == 27)) {
			code = _getch();
		}

	}
	catch (const std::exception&)
	{
		cout << "Ошибка открытия файла" << endl;
	}
}

int ans() {
	int choice = 0;
	int options = 5;
	int ch;
	while (true) {
		system("cls");
		choice = (choice + options) % options;
		if (choice == 0) cout << "-> Вход / Регистрация" << endl;
		else  cout << "   Вход / Регистрация" << endl;

		if (choice == 1) cout << "-> Приветствие" << endl;
		else  cout << "   Приветствие" << endl;

		if (choice == 2) cout << "-> Массивы" << endl;
		else  cout << "   Массивы" << endl;

		if (choice == 3) cout << "-> Флаг" << endl;
		else  cout << "   Флаг" << endl;

		if (choice == 4) cout << "-> Выход" << endl;
		else  cout << "   Выход" << endl;

		ch = _getch();
		if (ch == 224)
		{
			ch = _getch();
			if (ch == 80) choice++;
			if (ch == 72) choice--;
		}
		if (ch == 119)
		{
			choice--;
		}
		if (ch == 115)
		{
			choice++;
		}
		if (ch == 13) break;
	}
	system("cls");
	return choice;
}
int ans0() {
	int choice = 0;
	int options = 3;
	int ch;
	while(true) {
		system("cls");
		choice = (choice + options) % options;
		if (choice == 0) cout << "-> Регистрация в системе" << endl;
		else  cout << "   Регистрация в системе" << endl;

		if (choice == 1) cout << "-> Авторизация в системе" << endl;
		else  cout << "   Авторизация в системе" << endl;

		if (choice == 2) cout << "-> Назад" << endl;
		else  cout << "   Назад" << endl;

		ch = _getch();
		if (ch == 224)
		{
			ch = _getch();
			if (ch == 80) choice++;
			if (ch == 72) choice--;
		}
		if (ch == 119)
		{
			choice--;
		}
		if (ch == 115)
		{
			choice++;
		}
		if (ch == 13) break;
	}
	system("cls");
	return choice;
}
int ans1() {
	return 0;
}

void menu0() {
	while (true)
	{
	int answer = ans0();
	switch (answer)
	{
	case 0:
		reg();
		break;
	case 1:
		isAuth = auth();
		menu();
		break;
	case 2:
		menu();
		break;
	}
	}

}
void menu1() {
	if (isAuth) {}
	int answer = ans1();
	switch (answer)
	{
	case 0:
		menu0();
		break;
	case 1:
		menu1();
		break;
	case 2:
		//menu2();
		break;
	case 3:
		if (isAuth)
		{
			flag1();
			flag2();
			menu();
		}
		else {
			cout << "Вы не авторизованы. Пожалуйста, выполните вход в систему или зарегистрируйтесь!";
			Sleep(1500);
			menu0();
		}
		break;
	case 4:
		exit(0);
	}
}
void menu2() {}
void menu3() {}
void menu() {
	int answer = ans();
	switch (answer)
	{
	case 0:
		menu0();
		break;
	case 1:
		menu1();
		break;
	case 2:
		menu2();
		break;
	case 3:
		if (isAuth)
		{
			flag1();
			flag2();
			menu();
		}
		else {
			cout << "Вы не авторизованы. Пожалуйста, выполните вход в систему или зарегистрируйтесь!";
			Sleep(1500);
			menu0();
		}
		break;
	case 4:
		exit(0);
	}
}

int main() {
	setlocale(LC_ALL, "russian");
	menu();
}

