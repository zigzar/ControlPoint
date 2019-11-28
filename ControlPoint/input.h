int inputCheck() {
	setlocale(0, "");
	while (true) {
		int input;
		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << endl << "Ошибка ввода. Пожалуйста, попробуйте ввести число арабскими цифрами в естесственном виде: ";
		}
		else {
			cin.ignore(cin.rdbuf()->in_avail());
			return input;
		}
	}
}