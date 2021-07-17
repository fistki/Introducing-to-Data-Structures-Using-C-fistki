#include "Person.h"
#include "Table.h"

inline int MyHashFunc(int k)
{
	return k % 100;
}

int main(void)
{
	Table myTbl(MyHashFunc);

	auto np = MakePerson(20120003, "Lee", "Seoul");
	myTbl.insert(np->GetSSN(), np);
	np = MakePerson(20130012, "KIM", "Jeju");
	myTbl.insert(np->GetSSN(), np);
	np = MakePerson(20170049, "HAN", "Kangwon");
	myTbl.insert(np->GetSSN(), np);

	auto shared = MakePerson_shared(20122401, "ang", "gimotti");
	myTbl.insert(shared->GetSSN(), shared.get());

	shared = MakePerson_shared(20122405, "ddfaf", "adfsafas");
	myTbl.insert(shared->GetSSN(), shared.get());

	auto shared2= MakePerson_shared(20122402, "gg", "gdddd");
	myTbl.insert(shared2->GetSSN(), shared2.get());


	auto sp = myTbl.find(20120003);
	if (sp != myTbl.end())
		ShowPersonInfo(sp->val);
	
	sp = myTbl.find(20130012);
	if (sp != myTbl.end())
		ShowPersonInfo(sp->val);

	sp = myTbl.find(20170049);
	if (sp != myTbl.end())
		ShowPersonInfo(sp->val);

	auto rp = myTbl.erase(20120003);
	
	return 0;
}