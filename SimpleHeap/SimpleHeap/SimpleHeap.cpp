#include <cstdio>
#include "SimpleHeap.h"

int main(void)
{
	Heap heap;
	
	heap.HInsert('A', 1);
	heap.HInsert('B', 2);
	heap.HInsert('C', 3);
	printf("%c \n", heap.HDelete());

	heap.HInsert('A', 1);
	heap.HInsert('B', 2);
	heap.HInsert('C', 3);
	printf("%c \n", heap.HDelete());
		
	while(!heap.HIsEmpty())
		printf("%c \n", heap.HDelete());
	return 0;
}