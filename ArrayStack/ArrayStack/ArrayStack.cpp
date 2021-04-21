#include <cstdio>
#include "arraystack.h"

int main(void)
{
	// 스택 생성 및 초기화
	typedef AStack<int> iStack;

	iStack stack;

	// 데이터 넣기
	stack.push(1); stack.push(2);
	stack.push(3); stack.push(4);
	stack.push(5);

	// 데이터 꺼내기

	while (!stack.empty())
		printf("%d ", stack.pop());
	printf("\n");
	return 0;
}