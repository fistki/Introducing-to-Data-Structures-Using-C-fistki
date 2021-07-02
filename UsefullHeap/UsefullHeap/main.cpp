#include <cstdio>
#include "UsefullHeap.h"

int DataPriority(char ch1, char ch2)
{
	return ch2 - ch1;
}


int main(void)
{
	Heap<char> heap(DataPriority);

	heap.insert('A');
	heap.insert('B');
	heap.insert('C');
	printf("%c\n", heap.erase());
	
	heap.insert('A');
	heap.insert('B');
	heap.insert('C');
	printf("%c\n", heap.erase());

	while (!heap.empty())
	{
		printf("%c\n", heap.erase());
	}

	return 0;
}