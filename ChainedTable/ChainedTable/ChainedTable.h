#pragma once
#include <iterator>
#include <functional>
#include <vector>
#include <memory>
#include <list>
#include "Slot.h"


class Table {
public:
	enum { MAX_TBL = 100 };
	using HashFunc = std::function<Key(const Key&)>;
	using Iterator = std::vector<std::list<std::shared_ptr<Slot>>>::iterator;
	using Const_Iterator = std::vector<std::list<std::shared_ptr<Slot>>>::const_iterator;

	Table(HashFunc _hf);
	Table(const Table& rhs);
	Table& operator=(const Table& rhs);

	bool insert(const Key& k, Value v);
	bool erase(const Key& k);

	Value find(const Key& k) const;

	Iterator begin();
	Iterator end();

	Const_Iterator cbegin() const;
	Const_Iterator cend() const;

private:
	std::vector<std::list<std::shared_ptr<Slot>>> tbl;
	HashFunc hf;
};

void ShowSlotInUse(const Table& tbl);