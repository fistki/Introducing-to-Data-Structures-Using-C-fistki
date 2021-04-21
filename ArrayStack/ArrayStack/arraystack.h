#pragma once
#include "stack.h"
#include <memory>
template<typename Data>
class AStack : private Stack<Data> {
public:
	AStack() : stackArr(new Data[STACK_LEN]), top(-1) {}
	~AStack()
	{
		delete[] stackArr;
	}
	bool empty(void) const
	{
		if (top == -1) return true;
		else return false;
	}
	void push(const Data& data)
	{
		top++;
		stackArr[top] = data;
	}
	Data pop(void)
	{
		if (empty()) abort();
		return stackArr[top--];
	}
	Data peek(void) const
	{
		return stackArr[top];
	}
private:
	AStack(const AStack& rhs);				// 복사 금지
	AStack& operator=(const AStack& rhs);	// 복사 금지
	enum { STACK_LEN = 100 };	
	Data* stackArr;
	int top;

	
};