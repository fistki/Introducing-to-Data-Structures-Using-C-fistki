#pragma once
#include <string>
#include <memory>

class Person {
public:
	Person();
	Person(size_t _ssn, const std::string& _name, const std::string& _addr);

	size_t GetSSN() const;
	std::string GetName() const;
	std::string GetAddr() const;

private:
	size_t ssn;
	std::string name;
	std::string addr;
};

// Person p�� ������ ǥ�� ����� �Լ��� ���� ����մϴ�.
void ShowPersonInfo(const Person* p);

// ������ �ڿ��� �ݵ�� delete ���־�� �Ѵ�.
Person* MakePerson(size_t ssn, const std::string& name, const std::string& addr);

// ������ �ڿ��� �ڵ����� delete �˴ϴ�. 
std::shared_ptr<Person> MakePerson_shared(size_t ssn, const std::string& name, const std::string& addr);



