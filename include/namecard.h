#pragma once
#include <string>
#include <iostream>
#include <memory>
class NameCard {
private:
	enum { NAME_LEN = 30, PHONE_LEN = 30 };
	std::string name;
	std::string phone;
public:
	NameCard() {}
	NameCard(const std::string& _name, const std::string& _phone): name(_name), phone(_phone) {}
	NameCard(const NameCard& rhs): name(rhs.name), phone(rhs.phone) {}
	NameCard& operator=(const NameCard& rhs)
	{
		name = rhs.name;
		phone = rhs.phone;
		return *this;
	}
	~NameCard() {}

	void changePhoneNum(const std::string& _phone);

	const std::string& getName(void) const;
	const std::string& getPhone(void) const;


};


void NameCard::changePhoneNum(const std::string& _phone)
{
	phone = _phone;
}

const std::string& NameCard::getName(void) const
{
	return name;
}
const std::string& NameCard::getPhone(void) const
{
	return phone;
}

NameCard* makeNameCard(const std::string& _name, const std::string& _phone)
{
	return new NameCard(_name, _phone);
}
bool isNameEqual(const NameCard& lhs, const NameCard& rhs)
{
	if (lhs.getName() == rhs.getName()) return true;
	else return false;
}

void showCardInfo(const NameCard& _NameCard)
{
	std::cout << "Name:[" << _NameCard.getName() << "] Phone:[" << _NameCard.getPhone() << "]\n";
}