#include <cstdio>
#include "MergeSort.h"

int main(void)
{
	int arr[7] = { 3, 2, 4, 1, 7, 6, 5 };
	
	MergeSort(arr, 0, sizeof(arr) / sizeof(int) - 1);

	for (int num : arr)
	{
		printf("%d ", num);
	}
	printf("\n");
	return 0;
}
