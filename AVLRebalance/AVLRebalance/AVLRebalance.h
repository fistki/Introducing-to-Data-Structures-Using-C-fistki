#pragma once

#include "BTreeNode.h"

template<typename Data>
using Node = BTreeNode<Data>;

template<typename Data>
Node<Data>* Rebalanace();

template<typename Data>
Node<Data>* RotateLL(Node<Data>* bst);

template<typename Data>
Node<Data>* RotateRR(Node<Data>* bst);

template<typename Data>
Node<Data>* RotateLR(Node<Data>* bst);

template<typename Data>
Node<Data>* RotateRL(Node<Data>* bst);

template<typename Data>
int GetHeight(Node<Data>* bst);

template<typename Data>
int GetHeightDifference(Node<Data>* bst);

template<typename Data>
Node<Data>* Rebalanace(Node<Data>** pRoot)
{
	int hDiff = GetHeight(*pRoot);

	// 균형 인수가 +2 이상이면 LL상태 또는 LR 상태이다.
	// 왼쪽 서브 트리 방향으로 높이가 2 이상 크다면
	if (hDiff > 1)
	{
		if (GetHeightDifference((*pRoot)->GetLeftSubTree()) > 0)
			*pRoot = RotateLL(*pRoot);
		else
			*pRoot = RotateLR(*pRoot);
	}
	if (hDiff < -1)
	{
		if (GetHeightDifference((*pRoot)->GetRightSubTree()) < 0)
			*pRoot = RotateRR(*pRoot);
		else
			*pRoot = RotateRL(*pRoot);
	}
	return *pRoot;
}

template<typename Data>
Node<Data>* RotateLL(Node<Data>* bst)
{
	Node<Data>* ParentNode = bst;
	Node<Data>* ChildNode = bst->GetLeftSubTree();

	ParentNode->ChangeLeftSubTree(ChildNode->GetRightSubTree());
	ChildNode->ChangeRightSubTree(ParentNode);

	return ChildNode;
}

template<typename Data>
Node<Data>* RotateRR(Node<Data>* bst)
{
	Node<Data>* ParentNode = bst;
	Node<Data>* ChildNode = bst->GetRightSubTree();

	ParentNode->ChangeRightSubTree(ChildNode->GetLeftSubTree());
	ChildNode->ChangeLeftSubTree(ParentNode);

	return ChildNode;
}

template<typename Data>
Node<Data>* RotateLR(Node<Data>* bst)
{
	Node<Data>* ParentNode = bst;
	Node<Data>* ChildNode = bst->GetLeftSubTree();
	
	ParentNode->ChangeLeftSubTree(RotateRR(ChildNode));
	return RotateLL(ParentNode);
}

template<typename Data>
Node<Data>* RotateRL(Node<Data>* bst)
{
	Node<Data>* ParentNode = bst;
	Node<Data>* ChildNode = bst->GetRightSubTree();

	ParentNode->ChangeRightSubTree(RotateLL(ChildNode));
	return RotateRR(ParentNode);
}

template<typename Data>
int GetHeight(Node<Data>* bst)
{
	if (bst == nullptr)
		return 0;

	int leftH;
	int rightH;

	leftH = GetHeight(bst->GetLeftSubTree());
	rightH = GetHeight(bst->GetRightSubTree());

	if (leftH > rightH)
		return leftH + 1;
	else
		return rightH + 1;

}

template<typename Data>
int GetHeightDifference(Node<Data>* bst)
{
	if (bst == nullptr)
		return 0;
	// left sub tree height
	int lsh = GetHeight(bst->GetLeftSubTree());
	// right sub tree height
	int rsh; = GetHeight(bst->GetRightSubTree());
	
	return lsh - rsh;
}
