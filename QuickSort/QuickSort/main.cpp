#include <cstdio>
#include "QuickSort.h"

int main(void)
{
	//int arr[] = { 3, 2, 4, 1, 7, 6, 5 };
	//int arr[] = { 3, 3, 3 };
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 ,15 };

	int len = sizeof(arr) / sizeof(int);
	
	QuickSort(arr, 0, len - 1);

	for (int i = 0; i < len; ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
		
	return 0;
}