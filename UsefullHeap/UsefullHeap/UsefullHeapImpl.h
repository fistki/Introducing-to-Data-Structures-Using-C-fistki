#pragma once
#include <vector>

typedef char HData;
typedef	int Priority;
typedef int (*PriorityComp)(char d1, char d2);

inline int GetParentIDX(int idx) { return idx / 2; }
inline int GetLChildIDX(int idx) { return idx * 2; }
inline int GetRChildIDX(int idx) { return idx * 2 + 1; }


class HeapImpl {
public:
	enum { HEAP_LEN = 100 };
	HeapImpl(PriorityComp _comp) : numOfData(0), heapArr(HEAP_LEN), comp(_comp) { heapArr.push_back(HData()); }
	bool HIsEmpty() const;	// ���� ������� Ȯ��
	void HInsert(const HData& _data);	// ���� ������ �߰�
	HData HDelete();	// �켱������ ���� ���� ������ ����
private:
	int numOfData;
	std::vector<HData> heapArr;
	PriorityComp comp;
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
		if (comp(heapArr[GetLChildIDX(idx)], heapArr[GetRChildIDX(idx)]) < 0)	// �ڽ��� �� �� ���� ��, �켱������ ���� �ڽ��� �ε��� ��ȯ
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
void HeapImpl::HInsert(const HData& _data)
{
	int idx = numOfData + 1;
	while (idx != 1)
	{
		if (comp(_data, heapArr[GetParentIDX(idx)]))
		{
			heapArr[idx] = heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}
		else
			break;
	}
	heapArr[idx] = HData(_data);
	numOfData++;

}
HData HeapImpl::HDelete()
{
	HData retData = heapArr[1];
	HData lastElem(heapArr[numOfData]);

	int pIdx = 1;
	int cIdx = 0;

	while (cIdx = GetHiPriChildIDX(pIdx))	// �ڽ� ��尡 ���� �� ���� �ݺ��Ѵ�.
	{
		if (comp(lastElem, heapArr[cIdx]))	// �� �ڸ��� ã���� �ݺ����� �����.
			break;
		heapArr[pIdx] = heapArr[cIdx];	// ��ġ�� �ٲ��ش�.
		pIdx = cIdx;
	}

	heapArr[pIdx] = lastElem;		// ã�� �ڸ��� ������ ��带 �ִ´�.
	numOfData--;					// ������ ������ 1 �����Ͽ���.

	return retData;

}