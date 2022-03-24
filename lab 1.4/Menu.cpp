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
		cout << "������� ������� ������" << endl;
		cout << "1. �� �������� �� ��'��" << endl;
		cout << "2. �� �������" << endl;
		cout << "3. �� �������� ����� � ����" << endl;
		cout << "0. �����" << endl;

		cout << "choice: "; cin >> choice;
		cin.get();

		switch (choice)
		{
		case 1: 
		{
			string name;
			cout << "������ ������� �� ��'�: ";
			getline(cin, name);
			auto i = ss.FindIndexByName(name);
			if (i == -1)
				cout << "����� �� ��������" << endl;
			else
				cout << "[" << ss.getRecord(i).toString() << "]" << endl;
			break;
		}
		case 2: 
		{
			string position;
			cout << "������ ������: ";
			getline(cin, position);
			auto i = ss.FindIndexByPosition(position);
			if (i == -1)
				cout << "����� �� ��������" << endl;
			else
				cout << "[" << ss.getRecord(i).toString() << "]" << endl;
			break;
		}
		case 3: 
		{
			int salary;
			cout << "������ �������� ����� � ����: ";
			cin >> salary;
			auto i = ss.FindIndexByWorkingDays(salary);
			if (i == -1)
				cout << "����� �� ��������" << endl;
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
		cout << "������� �� ���������/����������" << endl;
		cout << "1. �� ���������" << endl;
		cout << "2. �� ����������" << endl;
		cout << "0. �����" << endl;

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
		cout << "������� ������� ����������" << endl;
		cout << "1. �� �������� �� ��'��   " << ShowSign(q) << endl;
		cout << "2. �� �������  " << ShowSign(w) << endl;
		cout << "3. �� ������� ������� ��� � �������    " << ShowSign(e) << endl;
		cout << "4. ���" << endl;
		cout << "0. �����" << endl;

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
	cout << "���� ����� \"������\"" << endl;
	int choice;
	do {
		cout << "1. ³��������� ������� ������" << endl;
		cout << "2. �������� �����" << endl;
		cout << "3. �������� �����" << endl;
		cout << "4. �������� ����� ������� ������" << endl;
		cout << "5. ������" << endl;
		cout << "6. ���������" << endl;
		cout << "0. �����" << endl;


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
			cout << "���� ����� ��������: "; cin >> index;
			ss.Delete(index);
			break;
		}
		case 4: {
			size_t size;
			cin.get();
			cout << "������ ������ ��������: "; cin >> size;
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