#include "list.h"
#include <vector>
#include <iostream>

template<typename LData>
class ArrayList : private List<LData> {
public:
	ArrayList() : arr(List<LData>::LIST_LEN), numOfData(0), curPosition(-1) {}
	ArrayList(const ArrayList& rhs)
		: numOfData(rhs.numOfData), curPosition(rhs.curPosition) {}
	~ArrayList() {}

	bool LInsert(const LData& data);
	bool LFirst(LData& pdata);
	bool LNext(LData& pdata);
	LData LRemove(void);
	int LCount(void);
	int LcurPostion(void);

private:
	std::vector<LData> arr;
	int numOfData;
	int curPosition;
};


template<typename LData>
bool ArrayList<LData>::LInsert(const LData& data)
{
	if (numOfData >= List<LData>::LIST_LEN) {
		std::cout << " Can't Insert Data\n";
		return false;
	}
	arr[numOfData++] = data;
	return true;
}
template<typename LData>
bool ArrayList<LData>::LFirst(LData& pdata)
{
	if (numOfData == 0) return false;

	curPosition = 0;
	pdata = arr[0];
	return true;
}
template<typename LData>
bool ArrayList<LData>::LNext(LData& pdata)
{
	if (curPosition >= numOfData - 1) return false;

	pdata = arr[++curPosition];
	return true;
}
template<typename LData>
LData ArrayList<LData>::LRemove(void)
{
	int rpos = curPosition;
	int Llen = numOfData;

	LData rdata = arr[rpos];

	for (int i = rpos; i < Llen - 1; ++i) {
		arr[i] = arr[i + 1];
	}

	curPosition--;	// -1을 하지 않으면 참조하지 않은 데이터를 가르키게 됨(원래꺼 바로 뒤에꺼)
					// 그래서 원래꺼 앞의 것을 가르키기 위해 -1을 함
	numOfData--;
	return rdata;	// LData가 포인터일시 유저가 직접 삭제하게 하기 위해 값을 돌려줌
}
template<typename LData>
int ArrayList<LData>::LCount(void) { return numOfData; }

template<typename LData>
int ArrayList<LData>::LcurPostion(void) { return curPosition; }


