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
	bool HIsEmpty() const;	// 힙이 비었는지 확인
	void HInsert(const HData& _data);	// 힙에 데이터 추가
	HData HDelete();	// 우선순위가 가장 높은 데이터 삭제
private:
	int numOfData;
	std::vector<HData> heapArr;
	PriorityComp comp;
	int GetHiPriChildIDX(int idx) const;	// 두 개의 자식 노드 중 높은 우선순위의 자식 노드 인덱스 값 반환
};
int HeapImpl::GetHiPriChildIDX(int idx) const
{
	if (GetLChildIDX(idx) > numOfData)	// 자식이 없을 때
		return 0;
	else if (GetLChildIDX(idx) == numOfData)	// 자식이 마지막 노드일 때
		return numOfData;
	else
	{
		if (comp(heapArr[GetLChildIDX(idx)], heapArr[GetRChildIDX(idx)]) < 0)	// 자식이 둘 다 있을 때, 우선순위가 높은 자식의 인덱스 반환
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

	while (cIdx = GetHiPriChildIDX(pIdx))	// 자식 노드가 없을 때 까지 반복한다.
	{
		if (comp(lastElem, heapArr[cIdx]))	// 제 자리를 찾으면 반복문을 멈춘다.
			break;
		heapArr[pIdx] = heapArr[cIdx];	// 위치를 바꿔준다.
		pIdx = cIdx;
	}

	heapArr[pIdx] = lastElem;		// 찾은 자리에 마지막 노드를 넣는다.
	numOfData--;					// 데이터 개수가 1 감소하였다.

	return retData;

}