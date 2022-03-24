#include "Notebook.h"
#include <iostream>
#include <iomanip>

size_t Notebook::getSize() const
{
    return size;
}

records Notebook::getRecord(size_t index) const
{
    return recordss[index];
}

records* Notebook::getRecords() const
{
    return recordss;
}

void Notebook::setSize(size_t size)
{
    this->size = size;
}

void Notebook::setRecord(size_t index, records record)
{
    recordss[index] = record;
}

void Notebook::setRecords(records* students)
{
    this->recordss = recordss;
}

void Notebook::Init(size_t size)
{
    setSize(size);
    setRecords(new records[size]());
}

void Notebook::Free()
{
    if (recordss != nullptr)
        delete[] recordss;
}

void Notebook::Add(records record)
{
    records* tmp = new records[size + 1]();
    for (size_t i = 0; i < size; i++)
        tmp[i] = recordss[i];
    tmp[size++] = record;

    if (recordss != nullptr)
        delete[] recordss;

    recordss = tmp;

}

void Notebook::Delete(size_t index)
{
    if (index >= 0 && index < size) 
    {
        records* tmp = new records[size - 1]();
        for (size_t i = 0, i1 = 0; i < size; i++, i1++)
        {
            if (i == index) {
                i1--;
                continue;
            }
            tmp[i1] = recordss[i];
        }
        size--;
        if (recordss != nullptr)
            delete[] recordss;
        recordss = tmp;
    }
}

void Notebook::Sort(bool descending, int choise)
{
    QuickSort(0, getSize() - 1, descending, choise);
}

void Notebook::Display() const
{
    cout << left << fixed << setprecision(2);
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << "|  №  |      Прізвище ім'я          |      Посада      | Робочі дні в тиждень |" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    for (size_t i = 0; i < size; i++)
        cout << '|'
        << setw(5) << i << '|'
        << setw(29) << recordss[i].getName() << '|'
        << setw(18) << recordss[i].getPosition() << '|'
        << setw(22)  << recordss[i].getWorkingDays() << '|' << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    cout << right << defaultfloat;
}

size_t Notebook::FindIndexByName(string name) const
{
    for (size_t i = 0; i < size; i++)
        if (getRecord(i).getName() == name)
            return i;
    return -1;
}

size_t Notebook::FindIndexByPosition(string position) const
{
    for (size_t i = 0; i < size; i++)
        if (getRecord(i).getPosition() == position)
            return i;
    return -1;
}

size_t Notebook::FindIndexByWorkingDays(int WorkingDays) const
{
    for (size_t i = 0; i < size; i++)
        if (int(getRecord(i).getWorkingDays() * 100) == int(WorkingDays * 100))
            return i;
    return -1;
}

void Notebook::QuickSort(int left, int right, bool descending, int choise)
{
    int l = left, r = right;
    records mid = recordss[(right + left) / 2];

    while (l <= r)
    {
        while (compare(recordss[l], mid, descending, choise) < 0) l++;
        while (compare(recordss[r], mid, descending, choise) > 0) r--;
        if (l <= r) {
            swap(recordss[l], recordss[r]);
            l++;
            r--;
        }
    }
    if (left < r) QuickSort(left, r, descending, choise);
    if (right > l) QuickSort(l, right, descending, choise);
}