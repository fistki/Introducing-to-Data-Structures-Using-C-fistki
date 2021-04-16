#include <stdio.h>
#include <iostream>
class Node{
private:
public:
	int data;
	Node* next;
	Node(int _data = 0): data(_data), next(NULL) {
		printf("노드 생성 [%d]\n", data);
	}
	~Node() {
		printf("노드 삭제 [%d]\n", data);
	}
};

void printNode(Node* pNode)
{
	printf("data : %d\n", pNode->data);
}


void testNode(void)
{
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;

	Node* newNode = NULL;
	int readData;

	while (1)
	{
		printf("eneter natural number : ");
		std::cin >> readData;
		if (readData < 0)
			break;

		newNode = new Node(readData);

		if (head == NULL)
			head = newNode;
		else
			tail->next = newNode;

		tail = newNode;
	}
	printf("\n");

	printf("입력 받은 데이터의 출력\n");

	if (head == NULL)
		printf("출력할 데이터가 없음\n");
	else {
		cur = head;
		printNode(cur);

		while (cur->next != NULL)
		{
			cur = cur->next;
			printNode(cur);
		}

	}
	printf("\n");

	Node* delcur = head;
	Node* delnext = NULL;

	if (delcur == NULL) printf("삭제할 데이터가 없습니다\n");
	else {

		delnext = delcur->next;
		delete delcur;

		while (delnext != NULL)
		{
			delcur = delnext;
			delnext = delcur->next;
			delete delcur;
		}

	}



}


void testReverseNode(void)
{
	Node* head = NULL;
	Node* tail = NULL;
	Node* cur = NULL;

	Node* newNode = NULL;
	int readData;

	while (1)
	{
		printf("eneter natural number : ");
		std::cin >> readData;
		if (readData < 0)
			break;

		newNode = new Node(readData);

		if (tail == NULL)
			tail = newNode;
		else
			newNode->next = head;

		head = newNode;
	}
	printf("\n");

	printf("입력 받은 데이터의 출력\n");

	if (head == NULL)
		printf("출력할 데이터가 없음\n");
	else {
		cur = head;
		printNode(cur);

		while (cur->next != NULL)
		{
			cur = cur->next;
			printNode(cur);
		}

	}
	printf("\n");

	Node* delcur = head;
	Node* delnext = NULL;

	if (delcur == NULL) printf("삭제할 데이터가 없습니다\n");
	else {

		delnext = delcur->next;
		delete delcur;

		while (delnext != NULL)
		{
			delcur = delnext;
			delnext = delcur->next;
			delete delcur;
		}

	}



}

int main(void)
{
	testNode();
	testReverseNode();
	return 0;
}