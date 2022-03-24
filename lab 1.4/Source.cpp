#include <iostream>
#include <iomanip>
#include <Windows.h>
#include "Notebook.h"
#include "Menu.h"
using namespace std;

records makeRecord(string name, string group, int WorkingDays)
{
	records s;
	if (!s.Init(name, group, WorkingDays))
		s = records();
	return s;
}

int main()
{
	srand(time(0));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Notebook ss;
	MainMenu(ss);
	ss.Free();
	return 0;
}