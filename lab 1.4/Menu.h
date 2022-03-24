#pragma once
#include <iostream>
#include "Notebook.h"

	char ShowSign(bool b);
	void MainMenu(Notebook& ss);
	void SearchMenu(const Notebook& ss);
	void SortMenuDescending(Notebook& ss, int _choise);
	void SortMenu(Notebook& ss);