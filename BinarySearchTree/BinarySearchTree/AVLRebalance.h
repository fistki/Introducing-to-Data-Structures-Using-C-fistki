#pragma once

#include "BTreeNode.h"

template<typename Data>
using Node = BTreeNode<Data>;

template<typename Data>
Node<Data>* Rebalance(Node<Data>** pRoot);

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
Node<Data>* Rebalance(Node<Data>* Root)
{
	if (Root == nullptr) {
		return nullptr;
	}

	Root->ChangeLeftSubTree(Rebalance(Root->GetLeftSubTree()));
	Root->ChangeRightSubTree(Rebalance(Root->GetRightSubTree()));
	
	int heightDiff = GetHeightDifference(Root);

	if (-1 <= heightDiff && heightDiff <= 1) {
		return Root;
	}

	if (heightDiff > 1) {
		Root = ((GetHeightDifference(Root->GetLeftSubTree()) > 0)) ? RotateLL(Root) : RotateLR(Root);
		return Root;
	}

	Root = (GetHeightDifference(Root->GetRightSubTree()) < 0) ? RotateRR(Root) : RotateRL(Root);
	return Root;
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

	int leftH = GetHeight(bst->GetLeftSubTree());
	int rightH = GetHeight(bst->GetRightSubTree());

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
	int rsh = GetHeight(bst->GetRightSubTree());
	
	return lsh - rsh;
}
