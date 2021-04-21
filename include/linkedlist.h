#pragma once
#include "list.h"
#include <cstdio>
#include <iostream>
#include <exception>

template<typename LData>
class LinkedList : private List<LData> {
public:
	LinkedList(): head(new Node()), cur(nullptr), before(nullptr), fcomp(nullptr), numOfNode(0) {}	// 기본 생성자만 지원
																								// 데이터 삽입시 제공 함수 사용해야됨

	~LinkedList()
	{
		Node* delcur = head;
		Node* delnext = head->next;
		while (delnext != nullptr)
		{
			delcur = delnext;
			delnext = delcur->next;
			delete delcur;
		}
		delete head;
	}
	bool LInsert(const LData& pdata);
	bool LFirst(LData& pdata);	
	bool LNext(LData& pdata); 	
	LData LRemove(void);		
	int LCount(void);
	void setSortRule(bool (*_pfcomp)(LData d1, LData d2));

private:
	LinkedList(const LinkedList&);				// 복사 금지
	LinkedList& operator=(const LinkedList&);	// 복사 금지

	void FInsert(const LData& data);			// 내부 구현용 함수
	void SInsert(const LData& data);			// 내부 구현용 함수

	class Node
	{
	private:
	public:
		LData data;
		Node* next;
		Node(): next(nullptr) {}
		Node(const LData& _data, Node* _next = nullptr): data(_data), next(_next){}
		~Node() {}
	};

	Node* head;
	Node* cur;
	Node* before;
	bool (*fcomp)(LData d1, LData d2);
	int numOfNode;
};
template<typename LData>
bool LinkedList<LData>::LInsert(const LData& pdata)
{
	try
	{
		if (fcomp == nullptr) this->FInsert(pdata);
		else this->SInsert(pdata);
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
void LinkedList<LData>::FInsert(const LData& pdata)
{
	Node* newNode = new Node(pdata);
	newNode->next = head->next;
	head->next = newNode;
	numOfNode++;
}
template<typename LData>
void LinkedList<LData>::SInsert(const LData& pdata)
{
	Node* newNode = new Node(pdata);
	Node* pred = head;

	while (pred->next != nullptr && fcomp(pdata, pred->next->data) == true)	// fcomp가 true 반환시
		pred = pred->next;													// 다음 위치로 넘어간다.
	
	newNode->next = pred->next;
	pred->next = newNode;
	numOfNode++;

}
template<typename LData>
bool LinkedList<LData>::LFirst(LData& pdata)
{
	if (head->next == nullptr) return false;
	before = head;
	cur = head->next;
	pdata = cur->data;
	return true;
}
template<typename LData>
bool LinkedList<LData>::LNext(LData& pdata)
{
	if (cur == nullptr || cur->next == nullptr) return false;
	before = cur;
	cur = cur->next;
	pdata = cur->data;
	return true;
}
template<typename LData>
LData LinkedList<LData>::LRemove(void)
{
	try
	{
		Node* rNode = cur;
		LData rdata = rNode->data;

		before->next = cur->next;
		cur = before;

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
int LinkedList<LData>::LCount(void)
{
	return numOfNode;
}
template<typename LData>
void LinkedList<LData>::setSortRule(bool (*_pfcomp)(LData d1, LData d2))
{
	fcomp = _pfcomp;
}




