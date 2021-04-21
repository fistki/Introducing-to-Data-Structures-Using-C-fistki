#pragma once
#include "list.h"
#include <cstdio>
#include <iostream>
#include <exception>

template<typename LData>
class DLinkedList : private List<LData> {
public:
	DLinkedList() : head(new Node()), tail(new Node()), cur(nullptr), numOfNode(0) 	// 기본 생성자만 지원, DummyNode 자동생성
	{																				// 데이터 삽입시 제공 함수 사용해야됨
		head->next = tail;
		tail->prev = head;
	}
	~DLinkedList()
	{
		Node* delcur = head;
		Node* delnext = delcur->next;
		while (delnext != tail)
		{
			delcur = delnext;
			delnext = delcur->next;
			delete delcur;
		}
		delete head;
		delete tail;
	}

	bool LInsert(const LData& pdata);
	bool LFirst(LData& pdata);
	bool LNext(LData& pdata);
	bool LPrevious(LData& pdata);
	LData LRemove(void);
	int LCount(void);

private:
	DLinkedList(const DLinkedList&);				// 복사 금지
	DLinkedList& operator=(const DLinkedList&);	// 복사 금지

	class Node{
	private:
	public:
		LData data;
		Node* prev;
		Node* next;
		Node() : prev(nullptr), next(nullptr) {}
		Node(const LData& _data, Node* _prev = nullptr, Node* _next = nullptr)
			: data(_data), prev(_prev), next(_next) {}
		~Node() {}
	};

	Node* head;
	Node* tail;
	Node* cur;
	int numOfNode;
};

template<typename LData>
bool DLinkedList<LData>::LInsert(const LData& pdata)
{
	try
	{
		Node* newNode = new Node(pdata);
		newNode->next = tail;
		newNode->prev = tail->prev;
		newNode->next->prev = newNode;
		newNode->prev->next = newNode;
		numOfNode++;
	}
	catch (std::exception& e)
	{
		std::cout << typeid(e).name() << std::endl;
		std::cerr << e.what() << std::endl;
		return false;
	}
	return true;
}

template<typename LData>
bool DLinkedList<LData>::LFirst(LData& pdata)
{
	if (head->next == tail) return false;
	cur = head->next;
	pdata = cur->data;
	return true;
}
template<typename LData>
bool DLinkedList<LData>::LNext(LData& pdata)
{
	if (cur == nullptr || cur->next == tail) return false;
	cur = cur->next;
	pdata = cur->data;
	return true;
}
template<typename LData>
bool DLinkedList<LData>::LPrevious(LData& pdata)
{
	if (cur == nullptr || cur->prev == head) return false;
	cur = cur->prev;
	pdata = cur->data;
	return true;
}
template<typename LData>
LData DLinkedList<LData>::LRemove(void)
{
	try
	{
		Node* rNode = cur;
		LData rdata = rNode->data;
		cur->next->prev = cur->prev;
		cur->prev->next = cur->next;
		cur = cur->prev;
		delete rNode;
		numOfNode--;
		return rdata;
	}
	catch (std::exception& e)
	{
		std::cout << typeid(e).name() << std::endl;
		std::cerr << e.what() << std::endl;
		abort();
	}
}
template<typename LData>
int DLinkedList<LData>::LCount(void)
{
	return numOfNode;
}
