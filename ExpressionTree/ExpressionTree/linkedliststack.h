#pragma once
#include "stack.h"
#include <iostream>
#include <memory>
template<typename Data>
class LStack : private Stack<Data> {
public:
	LStack() : head(nullptr) {}
	~LStack()
	{	
		Node* delcur = head;
		Node* delnext = head;

		while (delnext != nullptr)
		{
			delcur = delnext;
			delnext = delcur->next;
			delete delcur;
		}
	}
	bool empty(void) const
	{
		if (head == nullptr) return true;
		else return false;
	}
	void push(const Data& data)
	{
		Node* newNode = new Node(data, head);
		head = newNode;
	}
	Data pop(void)
	{
		if (empty()) abort();

		Node* popNode = head;
		Data rtnData(head->data);

		head = head->next;
		delete popNode;
		return rtnData;		
	}
	Data peek(void)
	{	
		if (empty()) abort();
		return head->data;
	}
	const Data& peek(void) const
	{
		if (empty()) abort();
		return head->data;
	}

private:
	LStack(const LStack& rhs);				// 복사 금지
	LStack& operator=(const LStack& rhs);	// 복사 금지
	class Node
	{
	private:
	public:
		Data data;
		Node* next;
		Node() : next(nullptr) {}
		Node(const Data& _data, Node* _next = nullptr) : data(_data), next(_next) {}
		~Node() {}
	};

	Node* head;
	
};