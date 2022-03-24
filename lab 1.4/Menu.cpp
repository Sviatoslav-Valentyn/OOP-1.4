#include "Menu.h"
#include "ReceivedRecords.h"

char ShowSign(bool b) 
{
	return b ? '+' : '-';
}

void SearchMenu(const Notebook& ss)
{
	int choice;
	do {
		cout << "Виберіть критерій пошуку" << endl;
		cout << "1. За прізвищем та ім'ям" << endl;
		cout << "2. За посадаю" << endl;
		cout << "3. За робочими днями в тижні" << endl;
		cout << "0. Назад" << endl;

		cout << "choice: "; cin >> choice;
		cin.get();

		switch (choice)
		{
		case 1: 
		{
			string name;
			cout << "Введіть прізвище та ім'я: ";
			getline(cin, name);
			auto i = ss.FindIndexByName(name);
			if (i == -1)
				cout << "Запис не знайдено" << endl;
			else
				cout << "[" << ss.getRecord(i).toString() << "]" << endl;
			break;
		}
		case 2: 
		{
			string position;
			cout << "Введіть посаду: ";
			getline(cin, position);
			auto i = ss.FindIndexByPosition(position);
			if (i == -1)
				cout << "Запис не знайдено" << endl;
			else
				cout << "[" << ss.getRecord(i).toString() << "]" << endl;
			break;
		}
		case 3: 
		{
			int salary;
			cout << "Введіть робочими днями в тижні: ";
			cin >> salary;
			auto i = ss.FindIndexByWorkingDays(salary);
			if (i == -1)
				cout << "Запис не знайдено" << endl;
			else
				cout << "[" << ss.getRecord(i).toString() << "]" << endl;
			break;
		}

		}
		cout << endl;
	} while (choice != 0);
}

void SortMenuDescending(Notebook& ss, int _choise) {
	int choice;
	do {
		cout << "Виберіть за спаданням/зростанням" << endl;
		cout << "1. За спаданням" << endl;
		cout << "2. За зростанням" << endl;
		cout << "0. Назад" << endl;

		cout << "choice: "; cin >> choice;
		cin.get();

		switch (choice)
		{
		case 1: {
			ss.Sort(false, _choise);
			break;
		}
		case 2: {
			ss.Sort(true, _choise);
			break;
		}

		}

		cout << endl;

		if (choice == 1 || choice == 2) break;
	} while (choice != 0);
}

void SortMenu(Notebook& ss)
{
	int choice, _choice = 0;
	bool q, w, e;
	q = w = e = false;
	do {
		cout << "Виберіть критерій сорутвання" << endl;
		cout << "1. За прізвищем та ім'ям   " << ShowSign(q) << endl;
		cout << "2. За посадою  " << ShowSign(w) << endl;
		cout << "3. За кількістю робочих днів в тиждень    " << ShowSign(e) << endl;
		cout << "4. Далі" << endl;
		cout << "0. Назад" << endl;

		cout << "choice: "; cin >> choice;
		cin.get();

		switch (choice)
		{
		case 1: {
			q = true;
			_choice = choice;
			w = e = false;
			break;
		}
		case 2: {
			w = true;
			_choice = choice;
			q = e = false;
			break;
		}
		case 3: {
			e = true;
			_choice = choice;
			q = w = false;
			break;
		}
		case 4: {
			if (_choice == 1 || _choice == 2 || _choice == 3) {
				SortMenuDescending(ss, _choice);
			}
			break;
		}

		}

		cout << endl;
		if (choice == 4) break;
	} while (choice != 0);
}

void MainMenu(Notebook& ss)
{
	cout << "Меню класу \"посада\"" << endl;
	int choice;
	do {
		cout << "1. Відобразити записну книжку" << endl;
		cout << "2. Добавити запис" << endl;
		cout << "3. Вилучити запис" << endl;
		cout << "4. Добавити певну кількість записів" << endl;
		cout << "5. Знайти" << endl;
		cout << "6. Сортувати" << endl;
		cout << "0. Вихід" << endl;


		cout << "choice: "; cin >> choice;

		switch (choice)
		{
		case 1: {
			ss.Display();
			break;
		}
		case 2: {
			records s;
			s.Read();
			ss.Add(s);
			break;
		}
		case 3: {
			size_t index;
			cin.get();
			cout << "Який запис вилучити: "; cin >> index;
			ss.Delete(index);
			break;
		}
		case 4: {
			size_t size;
			cin.get();
			cout << "Скільки записів добавити: "; cin >> size;
			for (size_t i = 0; i < size; i++) {
				ss.Add(makeRecordFromSample());

				cout << "[" << int(i / int(size - 1) * 100) << "%]" << "\b\b\b\b\b";
			}
			cout << endl;

			break;
		}
		case 5: {
			SearchMenu(ss);
			break;
		}
		case 6: {
			SortMenu(ss);
			break;
		}

		}

		cout << endl;
	} while (choice != 0);
}