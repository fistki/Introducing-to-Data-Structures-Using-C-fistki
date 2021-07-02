#include <cstdio>
#include <iostream>
#include "BinarySearchTree.h"

void VerifyInsertAndSearch(void);
void VerifyDelete(void);
void VerifyBalance(void);
void print(int data);
int main(void)
{
	printf("===== VerifyInsertAndSearch =====");
	printf("\n");
	VerifyInsertAndSearch();
	printf("\n");

	printf("===== VerifyDelete =====");
	printf("\n");
	VerifyDelete();
	printf("\n");

	printf("===== VerifyBalance =====");
	printf("\n");
	VerifyBalance();
	printf("\n");

	return 0;
}

void VerifyInsertAndSearch(void)
{
	BinarySearchTree<int> bst;
	Node<int>* sNode;

	bst.insert(9);
	bst.insert(1);
	bst.insert(6);
	bst.insert(2);
	bst.insert(8);
	bst.insert(3);
	bst.insert(5);

	sNode = bst.search(1);
	if (sNode == nullptr)
		printf("탐색 실패\n");
	else
		printf("탐색에 성공한 키의 값 : %d\n", sNode->GetData());

	sNode = bst.search(4);
	if (sNode == nullptr)
		printf("탐색 실패\n");
	else
		printf("탐색에 성공한 키의 값 : %d\n", sNode->GetData());

	sNode = bst.search(6);
	if (sNode == nullptr)
		printf("탐색 실패\n");
	else
		printf("탐색에 성공한 키의 값 : %d\n", sNode->GetData());

	sNode = bst.search(7);
	if (sNode == nullptr)
		printf("탐색 실패\n");
	else
		printf("탐색에 성공한 키의 값 : %d\n", sNode->GetData());
}

void VerifyDelete(void)
{
	BinarySearchTree<int> bst;
	Node<int>* sNode;

	bst.insert(5); bst.insert(8);
	bst.insert(1); bst.insert(6);
	bst.insert(4); bst.insert(9);
	bst.insert(3); bst.insert(2);
	bst.insert(7);

	ShowAllBSTNode<int>(&bst, print);
	printf("\n");
	bst.erase(3);
	
	ShowAllBSTNode<int>(&bst, print);
	printf("\n");
	bst.erase(8);
	
	ShowAllBSTNode<int>(&bst, print);
	printf("\n");
	bst.erase(1);
	
	ShowAllBSTNode<int>(&bst, print);
	printf("\n");
	bst.erase(6);
	
	ShowAllBSTNode<int>(&bst, print);
	printf("\n");
}

void VerifyBalance(void)
{
	Node<int>* CurrentLeftNode;
	Node<int>* CurrentRightNode;
	BinarySearchTree<int> bst;

	bst.insert_AVL(1);
	bst.insert_AVL(2); 
	bst.insert_AVL(3);
	bst.insert_AVL(4); 
	bst.insert_AVL(5);
	bst.insert_AVL(6);
	bst.insert_AVL(7); 
	bst.insert_AVL(8); 
	bst.insert_AVL(9);

	ShowAllBSTNode<int>(&bst, print);
}

void print(int data)
{
	printf("%d ", data);
}
