#include <cstdio>
#include "RadixSort.h"

int main(void)
{
	int arr[] = { 13, 212, 14, 7141, 10987, 6, 15 };
	int len = sizeof(arr) / sizeof(int);

	RadixSort(arr, len, 5);

	for (int num : arr)
	{
		printf("%d ", num);
	}
	printf("\n");

	return 0;
}