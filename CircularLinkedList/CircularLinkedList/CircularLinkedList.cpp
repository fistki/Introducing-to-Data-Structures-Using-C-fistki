#include "clinkedlist.h"
#include <cstdio>
#include <iostream>

int main(void)
{
	// 원형 연결 리스트 생성 및 초기화
	typedef CLinkedList<int> CList;
	CList list;
	int data = 0, nodeNum = 0;

	// 리스트에 5개의 데이터 저장
	list.LInsert(3);
	list.LInsert(4);
	list.LInsert(5);
	list.LInsertFront(2);
	list.LInsertFront(1);

	// 리스트에 저장된 데이터를 연속 3회 출력
	printf("현재 데이터의 수 : %d\n", list.LCount());
	if (list.LFirst(data))
	{
		printf("[%d] ", data);
		for (int i = 0; i < list.LCount()*3 - 1; ++i)
		{
			list.LNext(data);
			printf("[%d] ", data);
		}
		
	}
	printf("\n\n");

	// 2의 배수를 찾아서 모두 삭제
	nodeNum = list.LCount();

	if (nodeNum != 0)
	{
		list.LFirst(data);
		if (data % 2 == 0)
			list.LRemove();

		for (int i = 0; i < nodeNum - 1; ++i)
		{
			list.LNext(data);
			if (data % 2 == 0)
				list.LRemove();
		}
	}
	printf("\n\n");

	// 전체 데이터 1회 출력
	printf("현재 데이터의 수 : %d\n", list.LCount());
	if (list.LFirst(data))
	{
		printf("[%d] ", data);
		for (int i = 0; i < list.LCount()- 1; ++i)
		{
			list.LNext(data);
			printf("[%d] ", data);
		}
	}
	printf("\n\n");

	return 0;
}