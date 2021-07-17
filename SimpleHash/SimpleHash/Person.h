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

// Person p의 정보를 표준 입출력 함수를 통해 출력합니다.
void ShowPersonInfo(const Person* p);

// 생성한 자원은 반드시 delete 해주어야 한다.
Person* MakePerson(size_t ssn, const std::string& name, const std::string& addr);

// 생성한 자원은 자동으로 delete 됩니다. 
std::shared_ptr<Person> MakePerson_shared(size_t ssn, const std::string& name, const std::string& addr);



