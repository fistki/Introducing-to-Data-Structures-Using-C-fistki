#include <cstdio>
#include "InterpolSearch.h"

void print(int idx)
{
	if (idx == -1)
		printf("InterpolSearch failed\n");
	else
		printf("Target index : %d\n", idx);
}

int main(void)
{
	int arr[] = { 1, 3, 5, 7, 9 };
	int idx;

	int len = sizeof(arr) / sizeof(int);

	idx = ISearch(arr, 0, len - 1, 7);
	print(idx);

	idx = ISearch(arr, 0, len - 1, 4);
	print(idx);

	return 0;
}