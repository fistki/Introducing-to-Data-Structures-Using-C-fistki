#include <cstdio>
#include "deque.h"

int main(void)
{
	// Queue의 생성 및 초기화
	Deque<int> queue;

	// 데이터 넣기
	queue.push_front(3);
	queue.push_front(2);
	queue.push_front(1);

	queue.push_back(4);
	queue.push_back(5);
	queue.push_back(6);

	// 데이터 꺼내기
	while (!queue.empty())
		printf("%d ", queue.pop_back());

	return 0;
}