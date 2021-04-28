#include "btree.h"
#include <cstdio>

void ShowIntData(int data)
{
	printf("%d ", data);
}

int main(void)
{
	BTreeNode<int> bt1(1);
	BTreeNode<int> bt2(2);
	BTreeNode<int> bt3(3);
	BTreeNode<int> bt4(4);
	BTreeNode<int> bt5(5);
	BTreeNode<int> bt6(6);

	bt1.MakeLeftSubTree(&bt2);
	bt1.MakeRightSubTree(&bt3);
	bt2.MakeLeftSubTree(&bt4);
	bt2.MakeRightSubTree(&bt5);
	bt3.MakeRightSubTree(&bt6);

	BTreeNode<int>::InorderTraverse(&bt1, ShowIntData);
	printf("\n");
	BTreeNode<int>::PreorderTraverse(&bt1, ShowIntData);
	printf("\n");
	BTreeNode<int>::PostorderTraverse(&bt1, ShowIntData);
	printf("\n");
	
	return 0;
}