#include "records.h"
#include <string>

string name[20]
{
	"????????? ????","?????? ???????","????? ?????","????? ??????","????? ??????","???????? ?????","????? ??????","????? ????","?????? ?????",	"?????????? ??????",
	"?????? ?????","?????? ??????","????? ?????????","??????? ?????","?????????? ????","?????????? ?????","??? ?????","????? ?????","?????? ??????","???????? ????????"
};

string position[8]
{
	"????????", "???????????", "??????????", "????????????", "?????????", "?????", "????????", "???????"
};

records makeRecordFromSample()
{
	records s;
	s.setName(name[rand() % 20]);
	s.setPosition(position[rand() % 8]);
	int r = 1 + rand() % 7;
	s.setWorkingDays(round(r * 100.0) / 100.0);
	return s;
}
