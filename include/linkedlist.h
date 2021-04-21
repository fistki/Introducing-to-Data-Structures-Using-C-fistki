#pragma once
#include "list.h"
#include <cstdio>
#include <iostream>
#include <exception>

template<typename LData>
class LinkedList : private List<LData> {
public:
	LinkedList(): head(new Node()), cur(nullptr), before(nullptr), fcomp(nullptr), numOfNode(0) {}	// �⺻ �����ڸ� ����
																								// ������ ���Խ� ���� �Լ� ����ؾߵ�

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
	LinkedList(const LinkedList&);				// ���� ����
	LinkedList& operator=(const LinkedList&);	// ���� ����

	void FInsert(const LData& data);			// ���� ������ �Լ�
	void SInsert(const LData& data);			// ���� ������ �Լ�

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

	while (pred->next != nullptr && fcomp(pdata, pred->next->data) == true)	// fcomp�� true ��ȯ��
		pred = pred->next;													// ���� ��ġ�� �Ѿ��.
	
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




