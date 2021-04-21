#pragma once
#include "stack.h"
#include "clinkedlist.h"
#include <iostream>
#include <memory>
template<typename Data>
class CLStack : private Stack<Data> {
public:
	CLStack() : clistStack(new CLinkedList<Data>()) {}
	~CLStack()
	{}
	bool empty(void) const
	{
		if (clistStack->LCount() == 0) return true;
		else return false;
	}
	void push(const Data& data)
	{
		clistStack->LInsertFront(data);
	}
	Data pop(void)
	{
		if (empty()) abort();
		Data temp;
		clistStack->LFirst(temp);
		return clistStack->LRemove();
	}
	Data peek(void)
	{
		Data tempData;
		return clistStack->LFirst(tempData);
		return tempData;
	}
private:
	CLStack(const CLStack& rhs);				// 복사 금지
	CLStack& operator=(const CLStack& rhs);	// 복사 금지



	std::shared_ptr<CLinkedList<Data>> clistStack;
};