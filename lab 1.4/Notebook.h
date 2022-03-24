#pragma once
#include "records.h"

class Notebook
{
	size_t size = 0;
	records* recordss = nullptr;
public:
	size_t getSize() const;
	records getRecord(size_t index) const;
	records* getRecords() const;
	void setRecords(records* recordss);
	void setRecord(size_t index, records record);
	void setSize(size_t size);
	void Add(records record);
	void Delete(size_t index);
	void Init(size_t size);
	void Free();
	void Display() const;
	void Sort(bool descending, int choice);

	size_t FindIndexByName(string name) const;
	size_t FindIndexByPosition(string position) const;
	size_t FindIndexByWorkingDays(int WorkingDays) const;
private:
	void QuickSort(int left, int right, bool descending, int choice);
};