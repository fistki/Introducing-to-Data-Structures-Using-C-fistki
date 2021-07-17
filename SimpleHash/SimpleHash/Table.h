#pragma once
#include <vector>
#include <iterator>
#include <utility>
#include <functional>
#include "Slot.h"

class Table {
public:
	enum { MAX_TBL = 100 };
	using HashFunc = std::function<size_t(const Key&)>;
	using Iterator = std::vector<Slot>::iterator;
	using Const_Iterator = std::vector<Slot>::const_iterator;

	Table(HashFunc _hf = nullptr);
	Table(const Table& rhs);
	Table& operator=(const Table& rhs);

	std::pair<Iterator, ESlotStatus> insert(const Key& k, Value v);
	Iterator erase(const Key& k);

	Iterator find(const Key& k);
	Const_Iterator find(const Key& k) const;

	Iterator begin();
	Iterator end();

	Const_Iterator cbegin();
	Const_Iterator cend();

private:
	std::vector<Slot> tbl;
	HashFunc hf;
};

