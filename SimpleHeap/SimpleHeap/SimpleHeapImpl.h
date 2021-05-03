#pragma once
#include <vector>

typedef char HData;
typedef	int Priority;

inline int GetParentIDX(int idx) { return idx / 2; }
inline int GetLChildIDX(int idx) { return idx * 2; }
inline int GetRChildIDX(int idx) { return idx * 2 + 1; }

struct HeapElem {
	HeapElem() : pr(0), data() {}
	HeapElem(Priority _pr, const HData& _data) : pr(_pr), data(_data) {}
	HeapElem(const HeapElem& rhs) : pr(rhs.pr), data(rhs.data) {}
	HeapElem& operator=(const HeapElem& rhs)
	{
		pr = rhs.pr;
		data = rhs.data;
		return *this;
	}
	Priority pr;
	HData data;
};

class HeapImpl {
public:
	enum { HEAP_LEN = 100 };
	HeapImpl() : numOfData(0), heapArr(HEAP_LEN) { heapArr.push_back(HeapElem()); }
	bool HIsEmpty() const;	// ���� ������� Ȯ��
	void HInsert(Priority _pr, const HData& _data);	// ���� ������ �߰�
	HData HDelete();	// �켱������ ���� ���� ������ ����
private:
	int numOfData;
	std::vector<HeapElem> heapArr;
	int GetHiPriChildIDX(int idx) const;	// �� ���� �ڽ� ��� �� ���� �켱������ �ڽ� ��� �ε��� �� ��ȯ
};
int HeapImpl::GetHiPriChildIDX(int idx) const
{
	if (GetLChildIDX(idx) > numOfData)	// �ڽ��� ���� ��
		return 0;
	else if (GetLChildIDX(idx) == numOfData)	// �ڽ��� ������ ����� ��
		return numOfData;
	else
	{
		if (heapArr[GetLChildIDX(idx)].pr > heapArr[GetRChildIDX(idx)].pr)	// �ڽ��� �� �� ���� ��, �켱������ ���� �ڽ��� �ε��� ��ȯ
			return GetRChildIDX(idx);
		else
			return GetLChildIDX(idx);
	}
}
bool HeapImpl::HIsEmpty() const
{
	if (numOfData == 0) return true;
	else return false;
}
void HeapImpl::HInsert(Priority _pr, const HData& _data)
{
	int idx = numOfData + 1;
	while (idx != 1)
	{
		if (_pr < heapArr[GetParentIDX(idx)].pr)
		{
			heapArr[idx] = heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}
	heapArr[idx] = HeapElem(_pr,_data);
	numOfData++;

}
HData HeapImpl::HDelete()
{
	HData retData = heapArr[1].data;
	HeapElem lastElem(heapArr[numOfData]);

	int pIdx = 1;
	int cIdx = 0;

	while (cIdx = GetHiPriChildIDX(pIdx))	// �ڽ� ��尡 ���� �� ���� �ݺ��Ѵ�.
	{
		if (lastElem.pr <= heapArr[(cIdx)].pr)	// �� �ڸ��� ã���� �ݺ����� �����.
			break;
		heapArr[pIdx] = heapArr[cIdx];	// ��ġ�� �ٲ��ش�.
		pIdx = cIdx;
	}

	heapArr[pIdx] = lastElem;		// ã�� �ڸ��� ������ ��带 �ִ´�.
	numOfData--;					// ������ ������ 1 �����Ͽ���.

	return retData;

}