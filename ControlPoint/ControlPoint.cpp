//3
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <fstream>


using namespace std;

ifstream fin;
ofstream fout;

string path = "data.txt";
bool authorization();

void menu();
//void auth();
void reg();


void readFromFile(string& nameCheck, string& passCheck)
{
	ifstream fin;
	try
	{
		fin.open(path);
		cout << "Read is succsessful!" << endl << endl;
		getline(fin, nameCheck);
		getline(fin, passCheck);
	}
	catch (const std::exception&)
	{
		cout << "Ошибка открытия файла" << endl;
	}
}
bool check(string name, string pass)
{
	string nameCheck, passCheck;
	readFromFile(nameCheck, passCheck);
	if (name != nameCheck)
	{
		cout << "Такого пользователя не сушествует" << endl;
		authorization();
		return false;
	}
	else if (pass != passCheck)
	{
		cout << "Пароль введён невено" << endl;
		authorization();
		return false;
	}
	else
	{
		cout << "Вы успешно авторизовались" << endl;
		return true;
	}

}

bool auth()
{
	string name, pass;

	cout << "Авторизация: " << endl;
	cout << "Введите логин" << endl;
	cin >> name;
	cout << "Введите пароль" << endl;

	for (;;) {
		auto code = _getch();
		if (code == 13)
		{
			cout << endl;
			break;  // если энтер
		}

		if (code == 224)
			_getch(),
			code = 8;

		if (code == 8)
		{
			std::cout << "\b \b";
			if (!pass.empty())
				pass.pop_back();
		}
		else
		{
			const auto ch = static_cast<char>(code);
			pass += ch;
			std::cout << "*";
		}
	}

	return check(name, pass);
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
		auth();
		break;
	case 2:
		menu();
		break;
	}
	}

}
void menu1() {}
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
		menu3();
		break;
	case 4:
		exit(0);
	}
}

int main() {
	setlocale(LC_ALL, "russian");
	menu();
}

void writeToFile(string name, string pass)
{
	ofstream fout;
	try
	{
		fout.open(path);
		fout << name << endl << pass;
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