#pragma once

#include "btree.h"
#include "InfixToPostfix.h"
#include "linkedliststack.h"
#include <string>

BTreeNode<int>* MakeExpTree(const std::string& exp)
{
	std::string convExp = exp;
	calc_fistki::ConvToRPNExp(convExp);
	LStack<BTreeNode<int>*> stack;
	for (int i = 0; i < convExp.size(); ++i)
	{
		BTreeNode<int>* pnode = makeBTreeNode(0);

		if (isdigit(convExp[i]))
		{
			pnode->setData(convExp[i] - '0');
		}
		else
		{
			pnode->MakeRightSubTree(stack.pop());
			pnode->MakeLeftSubTree(stack.pop());
			pnode->setData(convExp[i]);
		}
		stack.push(pnode);
	}

	return stack.pop();	
}

void ShowNodeData(int data)
{
	if (0 <= data && data <= 9)
		printf("%d ", data);
	else
		printf("%c ", data);
}


void ShowPrefixTypeExp(BTreeNode<int>* bt)
{
	BTreeNode<int>::PreorderTraverse(bt,ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode<int>* bt)
{
	if (bt == nullptr) return;
	if(!isdigit(bt->getData()+'0')) 
		printf("( ");

	ShowInfixTypeExp(bt->getLeftSubTree());
	ShowNodeData(bt->getData());
	ShowInfixTypeExp(bt->getRightSubTree());

	if (!isdigit(bt->getData() + '0'))
		printf(") ");
}

void ShowPostfixTypeExp(BTreeNode<int>* bt)
{
	BTreeNode<int>::PostorderTraverse(bt, ShowNodeData);
}


int EvalulateExpTree(BTreeNode<int>* bt)
{
	if (bt->getLeftSubTree() == nullptr && bt->getRightSubTree() == nullptr) return bt->getData();
	
	int op1, op2;

	op1 = EvalulateExpTree(bt->getLeftSubTree());
	op2 = EvalulateExpTree(bt->getRightSubTree());

	switch (bt->getData())
	{
	case '+':
		return op1 + op2;
	case '-':
		return op1 - op2;
	case '*':
		return op1 * op2;
	case '/':
		return op1 / op2;
	}

	return 0;
}