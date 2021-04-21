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
	{
		printf("스택 리스트의 모든 노드를 삭제합니다.\n");
		printf("삭제를 완료하였습니다.\n");

	}
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