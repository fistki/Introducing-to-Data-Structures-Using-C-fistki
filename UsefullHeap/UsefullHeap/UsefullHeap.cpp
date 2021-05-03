#include <cstdio>
#include "UsefullHeap.h"

int DataPriority(char ch1, char ch2)
{
	return ch2 - ch1;
}


int main(void)
{
	Heap heap(DataPriority);

	heap.HInsert('A');
	heap.HInsert('B');
	heap.HInsert('C');
	printf("%c \n", heap.HDelete());

	heap.HInsert('A');
	heap.HInsert('B');
	heap.HInsert('C');
	printf("%c \n", heap.HDelete());

	while (!heap.HIsEmpty())
		printf("%c \n", heap.HDelete());
	return 0;
}