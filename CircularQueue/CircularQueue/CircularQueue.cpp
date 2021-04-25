#include <iostream>
#include <cstdio>
#include "circularqueue.h"
int main(void)
{
	// Queue의 생성 및 초기화
	CQueue<int> queue;

	// 데이터 넣기
	queue.enqueue(1); queue.enqueue(2);
	queue.enqueue(3); queue.enqueue(4);
	queue.enqueue(5);

	// 데이터 꺼내기
	while (!queue.empty())
		printf("%d ", queue.dequeue());

	return 0;
}