#include "Table.h"

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

std::pair<Table::Iterator, ESlotStatus> Table::insert(const Key& k, Value v)
{
	size_t HashResult = hf(k);

	tbl[HashResult].key = k;
	tbl[HashResult].val = v;
	tbl[HashResult].status = ESlotStatus::INUSE;
	
	return std::pair<Table::Iterator, ESlotStatus>(tbl.begin() + HashResult, ESlotStatus::INUSE);
}

Table::Iterator Table::erase(const Key& k)
{
	size_t HashResult = hf(k);
	
	if (tbl[HashResult].status != ESlotStatus::INUSE)
	{
		return tbl.end();
	}
	else
	{
		tbl[HashResult].status = ESlotStatus::DELETED;
		return tbl.erase(tbl.begin() + HashResult);
	}
}

Table::Iterator Table::find(const Key& k)
{
	size_t HashResult = hf(k);

	if (tbl[HashResult].status != ESlotStatus::INUSE)
		return tbl.end();
	else
		return tbl.begin() + HashResult;
}

Table::Const_Iterator Table::find(const Key& k) const
{
	size_t HashResult = hf(k);

	if (tbl[HashResult].status != ESlotStatus::INUSE)
		return tbl.end();
	else
		return tbl.begin() + HashResult;
}

inline Table::Iterator Table::begin()
{
	return tbl.begin();
}

Table::Iterator Table::end()
{
	return tbl.end();
}

inline Table::Const_Iterator Table::cbegin()
{
	return tbl.cbegin();
}

inline Table::Const_Iterator Table::cend()
{
	return tbl.cend();
}
