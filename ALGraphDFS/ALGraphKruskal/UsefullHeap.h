#pragma once
#include <vector>
#include <functional>

template<typename HData>
class Heap {
public:
	enum { HEAP_LEN = 100 };
	typedef std::function<int(HData, HData)> PriorityComp;

public:
	explicit Heap(PriorityComp pc);
	explicit Heap(const Heap& rhs);

	void insert(const HData& data);
	HData erase();
	bool empty() const;

	int GetHighPriorityChildIndex(int idx) const;

private:
	int numOfData;
	std::vector<HData> heapArr;
	PriorityComp comp;

};

inline int GetParentIndex(int idx)
{
	return idx / 2;
}

inline int GetLChildIndex(int idx)
{
	return idx * 2;
}

inline int GetRChildIndex(int idx)
{
	return idx * 2 + 1;
}

template<typename HData>
Heap<HData>::Heap(PriorityComp pc)
	: numOfData(0), heapArr(HEAP_LEN), comp(pc)
{
}

template<typename HData>
Heap<HData>::Heap(const Heap& rhs)
	: numOfData(rhs.numOfData), heapArr(rhs.heapArr), comp(rhs.comp)
{
}

template<typename HData>
void Heap<HData>::insert(const HData& data)
{
	int idx = numOfData + 1;
	while (idx != 1)
	{
		if (comp(data, heapArr[GetParentIndex(idx)]) > 0)
		{
			heapArr[idx] = heapArr[GetParentIndex(idx)];
			idx = GetParentIndex(idx);
		}
		else
		{
			break;
		}
	}

	heapArr[idx] = data;
	numOfData++;
}

template<typename HData>
HData Heap<HData>::erase()
{
	HData retData = heapArr[1];
	HData lastElem = heapArr[numOfData];
	int parentIdx = 1;
	int childIdx;

	while (childIdx = GetHighPriorityChildIndex(parentIdx))
	{
		if (comp(lastElem, heapArr[childIdx]) >= 0)
		{
			break;
		}
		heapArr[parentIdx] = heapArr[childIdx];
		parentIdx = childIdx;
	}

	heapArr[parentIdx] = lastElem;
	numOfData--;

	return retData;
}

template<typename HData>
inline bool Heap<HData>::empty() const
{
	return numOfData == 0;
}

template<typename HData>
int Heap<HData>::GetHighPriorityChildIndex(int idx) const
{
	if (GetLChildIndex(idx) > numOfData)
		return 0;
	else if (GetLChildIndex(idx) == numOfData)
		return GetLChildIndex(idx);
	else
	{
		if (comp(heapArr[GetLChildIndex(idx)], heapArr[GetRChildIndex(idx)]) < 0)
			return GetRChildIndex(idx);
		else
			return GetLChildIndex(idx);
	}
}
