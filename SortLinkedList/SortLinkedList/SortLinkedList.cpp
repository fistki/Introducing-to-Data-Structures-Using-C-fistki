#include <iostream>
#include <cstdio>
#include "linkedlist.h"

bool WhoIsPrecede(int d1, int d2)
{
	return d1 > d2;
}


int main(void)
{
	// 리스트 생성 및 초기화
	typedef LinkedList<int> iList;
	iList list;

	// 정렬 기준 등록
	list.setSortRule(WhoIsPrecede);

	// 5개의 데이터 저장
	list.LInsert(11); list.LInsert(11);
	list.LInsert(22); list.LInsert(22);
	list.LInsert(33);

	// 저장된 데이터 전체 출력
	int data;
	printf("현재 데이터의 수 : %d\n", list.LCount());

	if (list.LFirst(data))
	{
		printf("[%d] ", data);
		while (list.LNext(data))
		{
			printf("[%d] ", data);
		}
	}
	printf("\n\n");

	// 숫자 22를 검색해서 삭제
	int findIntVal = 0;
	printf("삭제할 숫자를 입력해주세요 : ");
	std::cin >> findIntVal;

	if (list.LFirst(data))
	{
		if (data == findIntVal)
			list.LRemove();

		while (list.LNext(data))
		{
			if (data == findIntVal)
				list.LRemove();
		}
	}
	printf("\n\n");

	// 삭제 후 남아 있는 데이터 출력
	printf("현재 데이터의 수 : %d\n", list.LCount());

	if (list.LFirst(data))
	{
		printf("[%d] ", data);
		while (list.LNext(data))
		{
			printf("[%d] ", data);
		}
	}
	printf("\n\n");

	return 0;
}