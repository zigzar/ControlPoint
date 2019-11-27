//3
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string>
#include <fstream>
#include <ctime>
#include <chrono>


using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

ifstream fin;
ofstream fout;

string path = "data.txt";
string patharr = "array.txt";

bool isAuth = false;

string curLogin;
string curPassword;

void menu();
void menu0();
bool auth();
int ans2();
int ans3();

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
	curLogin = login;
	curPassword = pass;
	isAuth = true;
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

void getBinGroup() {
	int i = 32;
	bool r;
	r = 9893 & (1U << --i);
	cout << r << " ";
	SetConsoleTextAttribute(h, 14);
	for (--i; i >= 0; --i)
	{
		r = 9893 & (1U << i);
		if (i % 4 == 0)
		{
			cout << r << " ";
		}
		else
		{
			cout << r;
		}
	}
	cout << endl;
	SetConsoleTextAttribute(h, 15);
}
void getBinSurname() {
	string s = "Голяков";
	int i = 8;
	bool r;

	for (int txtcolor = 0, ch = 0; ch < s.length(); ch++, txtcolor++)
	{
		i = 8;
		if (txtcolor % 2 == 0) { 
			SetConsoleTextAttribute(h, 14); 
		}
		else {
			SetConsoleTextAttribute(h, 3);
		}
		for (--i; i >= 0; --i)
		{
			r = s[ch] & (1U << i);
			if (i % 4 == 0)
			{
				cout << r << " ";
			}
			else
			{
				cout << r;
			}
		}
		cout << "   ";
	}


	SetConsoleTextAttribute(h, 15);
}

void showarr(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

void random(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 100 + 1;
	}
}

void manual(int* arr, int size)
{
	cout << "Введите значения: ";
	for (int i = 0; i < size; i++)
	{
		cout << "Введите arr[" << i << "] ";
		cin >> arr[i];
	}
}

void file(int* arr, int size)
{
	ifstream fin;
	try
	{
		fin.open(patharr);
		for (int i = 0; i < size; i++)
		{
			if (fin.eof()) {
				cout << "В файле недостаточно чисел. Пожалуйста, введите больше чисел в файл и нажмите Enter" << endl;
				system("pause");
				file(arr, size);
			}
			fin >> arr[i];
		}
	}
	catch (const std::exception&)
	{
		cout << "Ошибка открытия файла" << endl;
	}
}

void fibbCheck(int* arr, int size)
{
	int count = 0;
	if (size > 15) {
		size = 15;
	}
	for (int i = 0; i < size; i++)
	{
		int f1 = 1, f2 = 1, it = 2;
		while (f2 < arr[i]) {
			int tmp = f2;
			f2 += f1;
			f1 = tmp;
		}
		if (f2 == arr[i]) count++;
	}
	if (count == 0) {
		cout << "Чисел Фибоначчи среди массива нет";
	}
	else {
		cout << "Из " << size << " элементов массива числами Фибоначчи являются " << count << " и не являются " << size - count << endl;
	}
}


void bs(int* arr, int size)
{
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}
void shs(int* arr, int size)
{
	int left = 0, right = size - 1;
	int flag = 1;

	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				flag = 1;
			}
		}
		right--;
		for (int i = right; i > left; i--)
		{
			if (arr[i - 1] > arr[i])
			{
				swap(arr[i], arr[i - 1]);
				flag = 1;
			}
		}
		left++;
	}
}
void cs(int* arr, int size)
{
	int gap = size;
	bool flag = true;

	while (gap != 1 || flag == true) {
		gap = (gap * 10) / 13;
		if (gap < 1)
			gap = 1;
		flag = false;

		for (int i = 0; i < size - gap; i++) {
			if (arr[i] > arr[i + gap]) {
				swap(arr[i], arr[i + gap]);
				flag = true;
			}
		}
	}
}
void is(int* arr, int size)
{
	int key;
	for (int i = 1; i < size; i++)
	{
		key = arr[i];
		int j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}
void qs(int* arr, int size)
{
	int i = 0;
	int j = size - 1;

	int mid = arr[size / 2];

	do {
		while (arr[i] < mid) {
			i++;
		}
		while (arr[j] > mid) {
			j--;
		}
		if (i <= j) {
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);

	if (j > 0) {
		qs(arr, j + 1);
	}
	if (i < size) {
		qs(&arr[i], size - i);
	}
}

void menu2()
{
	int size;
	cout << "Введите размерность массива" << endl;
	cin >> size;
	int* arr = new int[size];

	int answer = ans2();

	switch (answer)
	{
	case 0:
		random(arr, size);
		break;
	case 1:
		manual(arr, size);
		break;
	case 2:
		file(arr, size);
		break;
	default:
		break;
	}

	cout << "Ваш массив: ";
	showarr(arr, size);
	cout << endl;
	system("pause");

	answer = ans3();

	auto timerStart = chrono::high_resolution_clock::now();
	switch (answer)
	{
	case 0:
		bs(arr, size);
		break;
	case 1:
		shs(arr, size);
		break;
	case 2:
		cs(arr, size);
		break;
	case 3:
		is(arr, size);
		break;
	case 4:
		qs(arr, size);
		break;
	default:
		break;
	}
	auto timerEnd = chrono::high_resolution_clock::now();
	chrono::duration<double, nano>;
	double timerDur = (timerEnd - timerStart).count();
	cout.setf(ios::fixed);
	cout << endl << "Время работы сортировки: " << timerDur / 1000000 << " сек" << endl;

	cout << "Отсортированный массив: ";
	showarr(arr, size);
	cout << endl << endl;
	fibbCheck(arr, size);

	cout << "ESC для выхода в главное меню...";
	char code = _getch();
	while (!(code == 27)) {
		code = _getch();
	}
	menu();

	delete[] arr;
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
	int choice = 0;
	int options = 4;
	int ch;
	while (true) {
		system("cls");
		choice = (choice + options) % options;

		cout << "Вы не вошли в систему. Вы можете продолжить в качестве анонима или войти/зарегистрироваться." << endl 
			<< "____________________________________________________________________________________________" << endl << endl;
		if (choice == 0) cout << "-> Регистрация в системе" << endl;
		else  cout << "   Регистрация в системе" << endl;

		if (choice == 1) cout << "-> Авторизация в системе" << endl;
		else  cout << "   Авторизация в системе" << endl;

		if (choice == 2) cout << "-> Продолжить без авторизации" << endl;
		else  cout << "   Продолжить без авторизации" << endl;

		if (choice == 3) cout << "-> Назад" << endl;
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
int ans3() {
	int choice = 0;
	int options = 5;
	int ch;
	while (true) {
		system("cls");
		cout << "Какой сортировкой вы хотите отсортировать массив? (ESC для выхода в главное меню)" << endl << endl;
		choice = (choice + options) % options;
		if (choice == 0) cout << "-> Bubble" << endl;
		else  cout << "   Bubble" << endl;

		if (choice == 1) cout << "-> Shaker" << endl;
		else  cout << "   Shaker" << endl;

		if (choice == 2) cout << "-> Comb" << endl;
		else  cout << "   Comb" << endl;

		if (choice == 3) cout << "-> Insert" << endl;
		else  cout << "   Insert" << endl;

		if (choice == 4) cout << "-> Quick" << endl;
		else  cout << "   Quick" << endl;

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
		if (ch == 27) menu();
		if (ch == 13) break;
	}
	system("cls");
	return choice;
}
int ans2() {
	int choice = 0;
	int options = 3;
	int ch;
	while (true) {
		system("cls");
		cout << "Как вы хотите запонить массив? (ESC для выхода в главное меню)" << endl << endl;
		choice = (choice + options) % options;
		if (choice == 0) cout << "-> Случайно" << endl;
		else  cout << "   Случайно" << endl;

		if (choice == 1) cout << "-> Вручную" << endl;
		else  cout << "   Вручную" << endl;

		if (choice == 2) cout << "-> Прочитать из файла" << endl;
		else  cout << "   Прочитать из файла" << endl;

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
		if (ch == 27) menu();
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
		isAuth = auth();
		break;
	}
	menu();
	}

}
void menu1() {
	if (isAuth) {
		cout << "Приветствую тебя, " << curLogin << ". На улице такая вьюга. Присаживайся у очага, здесь тебе всегда рады." << endl;
		cout << "Эту программу написал студент группы 9893, Максим Голяков. Кстати, в памяти моего компьютера номер мой группы выглядит как:" << endl;
		getBinGroup();
		cout << "А фамилия как:" << endl;
		getBinSurname();
		cout << endl;
		cout << "ESC для выхода в главное меню...";
		char code = _getch();
		while (!(code == 27)) {
			code = _getch();
		}
	}
	else {
		int answer = ans1();
		switch (answer)
		{
		case 0:
			reg();
			break;
		case 1:
			isAuth = auth();
			break;
		case 2:
			cout << "Приветствую тебя, пользователь N. На улице такая вьюга. Присаживайся у очага, здесь тебе всегда рады." << endl;
			cout << "Эту программу написал студент группы 9893, Максим Голяков. Кстати, в памяти моего компьютера номер мой группы выглядит как:" << endl;
			getBinGroup();
			cout << "А фамилия как:" << endl;
			getBinSurname();
			cout << endl;
			cout << "ESC для выхода в главное меню...";
			char code = _getch();
			while (!(code == 27)) {
				code = _getch();
			}
			break;
		}
	}
	menu();
}

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
		if (isAuth)
		{
			menu2();
		}
		else {
			cout << endl << "Вы не авторизованы. Пожалуйста, выполните вход в систему или зарегистрируйтесь!";
			Sleep(2000);
			menu0();
		}
		break;
	case 3:
		if (isAuth)
		{
			flag1();
			flag2();
			menu();
		}
		else {
			cout << endl << "Вы не авторизованы. Пожалуйста, выполните вход в систему или зарегистрируйтесь!";
			Sleep(2000);
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

