#include "ExpressionTree.h"
#include <cstdio>
#include <string>
int main(void)
{
	std::string exp = "(1+2)*7";

	BTreeNode<int>* eTree = MakeExpTree(exp);

	printf("PrefixExp : ");
	ShowPrefixTypeExp(eTree); printf("\n");

	printf("InfixExp : ");
	ShowInfixTypeExp(eTree); printf("\n");

	printf("PostfixExp : ");
	ShowPostfixTypeExp(eTree); printf("\n");
	
	printf("result : %d\n", EvalulateExpTree(eTree));
	
	
	BTreeNode<int>::deleteTree(eTree);

	return 0;
}


