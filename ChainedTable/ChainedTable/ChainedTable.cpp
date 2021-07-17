#include "ChainedTable.h"

Table::Table(HashFunc _hf)
	: tbl(MAX_TBL), hf(_hf)
{
}

Table::Table(const Table& rhs)
	: tbl(rhs.tbl), hf(rhs.hf)
{
}

Table& Table::operator=(const Table& rhs)
{
	tbl = rhs.tbl;
	hf = rhs.hf;
	return *this;
}

bool Table::insert(const Key& k, Value v)
{
	size_t HashResult = hf(k);
	auto slot_shared = std::make_shared<Slot>(k, v);
		
	// 키가 중복될 경우 insert 실패
	if (find(k) != nullptr)
		return false;
	else
	{
		tbl[HashResult].push_back(slot_shared);
		return true;
	}
}

bool Table::erase(const Key& k)
{
	size_t HashResult = hf(k);

	for (auto it = tbl[HashResult].begin(); it != tbl[HashResult].end(); ++it)
	{
		if (it->get()->key == k)
			{
			tbl[HashResult].erase(it);
			return true;
		}
	}

	return false;
}

 Value Table::find(const Key& k) const
{
	size_t HashResult = hf(k);

	for (auto it : tbl[HashResult])
	{
		if (it->key == k)
			return it->val;
	}
	return nullptr;
}

inline Table::Iterator Table::begin()
{
	return tbl.begin();
}

inline Table::Iterator Table::end()
{
	return tbl.end();
}

inline Table::Const_Iterator Table::cbegin() const
{
	return tbl.cbegin();
}

inline Table::Const_Iterator Table::cend() const
{
	return tbl.cend();
}

void ShowSlotInUse(const Table& tbl)
{
	for (auto it = tbl.cbegin(); it != tbl.cend(); ++it)
	{
		for (auto slot : *it)
			ShowPersonInfo(slot->val);
	}
}
