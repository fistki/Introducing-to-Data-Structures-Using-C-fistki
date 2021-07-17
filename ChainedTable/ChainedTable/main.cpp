#include "ChainedTable.h"
#include "Person.h"

int hf(int k)
{
	return k % 100;
}

int main(void)
{
	Table myTbl(hf);
	Person* np;

	np = MakePerson(900254, "Lee", "Seoul");
	myTbl.insert(np->GetSSN(), np);

	np = MakePerson(900139, "Kim", "Jeju");
	myTbl.insert(np->GetSSN(), np);

	np = MakePerson(900827, "Han", "Busan");
	myTbl.insert(np->GetSSN(), np);

	Person* sp;
	
	sp = myTbl.find(900254);
	if (sp != nullptr)
	{
		ShowPersonInfo(sp);
	}

	sp = myTbl.find(900139);
	if (sp != nullptr)
	{
		ShowPersonInfo(sp);
	}

	sp = myTbl.find(900827);
	if (sp != nullptr)
	{
		ShowPersonInfo(sp);
	}

	myTbl.erase(900254);

	printf("\n\n");
	ShowSlotInUse(myTbl);
	return 0;
}