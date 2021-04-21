#pragma once
#include "list.h"
#include <cstdio>
#include <iostream>
#include <exception>

template<typename LData>
class CLinkedList : private List<LData> {
public:
	CLinkedList() : tail(nullptr), cur(nullptr), before(nullptr), numOfNode(0) {}	// �⺻ �����ڸ� ����
																									// ������ ���Խ� ���� �Լ� ����ؾߵ�
	~CLinkedList()
	{
		printf("����Ʈ�� ��� ��带 �����մϴ�.\n");
		if (tail != nullptr)
		{
			Node* delcur = tail;
			Node* delnext = tail->next;
			while (delnext != tail)
			{
				printf("���� ���� �ִ� ��� �� : %d\n", numOfNode--);
				delcur = delnext;
				delnext = delcur->next;
				delete delcur;
			}
			printf("���� ���� �ִ� ��� �� : %d\n", numOfNode--);
			delete tail;
		}

		printf("������ �Ϸ��Ͽ����ϴ�.\n");
		
	}
	bool LInsert(const LData& data);
	bool LInsertFront(const LData& data);
	bool LFirst(LData& pdata);
	bool LNext(LData& pdata);
	LData LRemove(void);
	int LCount(void);

private:
	CLinkedList(const CLinkedList&);				// ���� ����
	CLinkedList& operator=(const CLinkedList&);	// ���� ����

	class Node
	{
	private:
	public:
		LData data;
		Node* next;
		Node() : next(nullptr) {}
		Node(const LData& _data, Node* _next = nullptr) : data(_data), next(_next) {}
		~Node() {}
	};

	Node* tail;
	Node* cur;
	Node* before;
	int numOfNode;
};

template<typename LData>
bool CLinkedList<LData>::LInsert(const LData& pdata)
{
	bool isNonException = LInsertFront(pdata);
	tail = tail->next;
	return isNonException;
}
template<typename LData>
bool CLinkedList<LData>::LInsertFront(const LData& pdata)
{
	try
	{
		Node* newNode = new Node(pdata);
		if (tail == nullptr)
		{
			tail = newNode;
			newNode->next = newNode;
			numOfNode++;
		}
		else
		{
			newNode->next = tail->next;
			tail->next = newNode;
			numOfNode++;
		}
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
bool CLinkedList<LData>::LFirst(LData& pdata)
{
	if (tail == nullptr) return false;
	before = tail;
	cur = tail->next;
	pdata = cur->data;
	return true;
}
template<typename LData>
bool CLinkedList<LData>::LNext(LData& pdata)
{
	if (tail == nullptr || cur == nullptr ) return false;
	before = cur;
	cur = cur->next;
	pdata = cur->data;
	return true;
}
template<typename LData>
LData CLinkedList<LData>::LRemove(void)
{
	try {
		Node* rNode = cur;
		LData rdata = rNode->data;
		if (rNode == tail)
		{
			if (tail == tail->next)
				tail = nullptr;
			else
				tail = before;
		}

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
int CLinkedList<LData>::LCount(void)
{
	return numOfNode;
}