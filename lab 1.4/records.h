#pragma once
#include <string>
using namespace std;

class records
{
	string name;
	string position;
	int WorkingDays;
public:
	string getName() const;
	string getPosition() const;
	int getWorkingDays() const;
	void setName(string name);
	void setPosition(string position);
	void setWorkingDays(int WorkingDays);
	string toString() const;
	bool Init(string name, string position, int WorkingDays);
	void Read();
	void Display() const;
};
int compare(const records& s1, const records& s2, bool descending, int choice);