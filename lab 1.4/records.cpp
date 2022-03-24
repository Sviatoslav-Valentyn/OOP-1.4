#include "records.h"
#include <iostream>
#include <sstream>

string records::getName() const
{
    return name;
}

string records::getPosition() const
{
    return position;
}

int records::getWorkingDays() const
{
    return WorkingDays;
}

void records::setName(string name)
{
    this->name = name;
}

void records::setPosition(string position)
{
    this->position = position;
}

void records::setWorkingDays(int WorkingDays)
{
    this->WorkingDays = WorkingDays;
}

string records::toString() const
{
    stringstream ss;
    ss << "Прізвище ім'я: " << name << ", Посада: " << position << ", Робочі дні в тиждень: " << WorkingDays;
    return ss.str();
}

bool records::Init(string name, string position, int WorkingDays)
{
    setName(name);
    setPosition(position);
    setWorkingDays(WorkingDays);

    return this->WorkingDays > 0 && this->WorkingDays <= 7;
}

void records::Read()
{
    string name, position;
    int WorkingDays;

    cin.get();
    do {
        cout << "Введіть прізвище та ім'я: ";
        getline(cin, name);

        cout << "Введіть  посаду: ";
        getline(cin, position);

        cout << "Введіть кількість робочих днів в тиждень: ";
        cin >> WorkingDays;

    } while (!Init(name, position, WorkingDays));
}

void records::Display() const
{
    cout << toString() << endl;
}

int compare(const records& s1, const records& s2, bool descending, int choice)
{
    if (choice == 1) 
    {
        if (s1.getName() < s2.getName()) return descending ? -1 : 1;
        if (s1.getName() > s2.getName()) return descending ? 1 : -1;
    }
    if (choice == 2) 
    {
        if (s1.getPosition() < s2.getPosition()) return descending ? -1 : 1;
        if (s1.getPosition() > s2.getPosition()) return descending ? 1 : -1;
    }
    if (choice == 3) 
    {
        if (s1.getWorkingDays() < s2.getWorkingDays()) return descending ? -1 : 1;
        if (s1.getWorkingDays() > s2.getWorkingDays()) return descending ? 1 : -1;
    }
    return 0;
}