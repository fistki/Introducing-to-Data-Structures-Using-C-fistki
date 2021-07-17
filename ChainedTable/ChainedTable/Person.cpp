#include "Person.h"

Person::Person()
	: ssn(0), name(), addr()
{
}

Person::Person(size_t _ssn, const std::string& _name, const std::string& _addr)
	: ssn(_ssn), name(_name), addr(_addr)
{
}

inline size_t Person::GetSSN() const
{
	return ssn;
}

inline std::string Person::GetName() const
{
	return name;
}

inline std::string Person::GetAddr() const
{
	return addr;
}

inline void Person::SetSSN(size_t _ssn)
{
	ssn = _ssn;
}

inline void Person::SetName(const std::string& _name)
{
	name = _name;
}

inline void Person::SetAddr(const std::string& _addr)
{
	addr = _addr;
}

void ShowPersonInfo(const Person* p)
{
	printf("주민등록 번호 : %d\n", p->GetSSN());
	printf("이름 : %s\n", p->GetName().c_str());
	printf("주소 : %s\n", p->GetAddr().c_str());
}

Person* MakePerson(size_t ssn, const std::string& name, const std::string& addr)
{
	return new Person(ssn, name, addr);
}

std::shared_ptr<Person> MakePerson_shared(size_t ssn, const std::string& name, const std::string& addr)
{
	std::shared_ptr<Person> person(new Person(ssn, name, addr));
	return person;
}
