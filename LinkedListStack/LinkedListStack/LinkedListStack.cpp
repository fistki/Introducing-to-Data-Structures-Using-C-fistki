#include <cstdio>
#include "linkedliststack.h"
#include "clinkedliststack.h"
int main(void)
{
	// 스택 생성 및 초기화
	typedef LStack<int> iStack;

	iStack* pstack = new iStack;
	
	// 데이터 넣기
	pstack->push(1); pstack->push(2);
	pstack->push(3); pstack->push(4);
	pstack->push(5);

	
	// 데이터 꺼내기
	while (!pstack->empty())
		printf("%d ", pstack->pop());
	printf("\n");

	// 스택 삭제

	delete pstack;


	// 스택 생성 및 초기화
	typedef CLStack<int> iCLStack;

	iCLStack* clpstack = new iCLStack;

	// 데이터 넣기
	clpstack->push(1); clpstack->push(2);
	clpstack->push(3); clpstack->push(4);
	clpstack->push(5);

	// 데이터 꺼내기
	while (!clpstack->empty())
		printf("%d ", clpstack->pop());
	
	printf("\n");

	// 스택 삭제

	delete clpstack;

	return 0;
}