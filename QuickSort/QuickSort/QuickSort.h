#pragma once

void Swap(int arr[], int idx1, int idx2)
{
	int temp = arr[idx1];
	arr[idx1] = arr[idx2];
	arr[idx2] = temp;
}

int SelectMiddleDataIndex(int arr[], int left, int mid, int right)
{
	int tempArr[3] = { left, mid, right };
	
	if (arr[tempArr[0]] > arr[tempArr[1]])
		Swap(tempArr, 0, 1);
	if (arr[tempArr[1]] > arr[tempArr[2]])
		Swap(tempArr, 1, 2);
	if (arr[tempArr[0]] > arr[tempArr[1]])
		Swap(tempArr, 0, 1);

	return tempArr[1];
}

int Partition(int arr[], int left, int right)
{
	int pIdx = SelectMiddleDataIndex(arr, left, (left+right)/2, right);
	//int pIdx = left;
	int pivot = arr[pIdx];

	int low = left + 1;
	int high = right;

	Swap(arr, pIdx, left);

	printf("pivot(arr[%d]) : %d\n", pIdx, pivot);

	// low와 hight가 교차할 때 까지 반복
	while (low <= high)
	{
		// low는 피벗보다 큰(정렬우선순위가 낮은) 값을 찾음
		while (pivot >= arr[low] && low <= right)
			low++;
		// high는 피벗보다 작은(정렬우선순위가 높은) 값을 찾음
		while (pivot <= arr[high] && high >= left + 1)
			high--;

		// 교차되지 않았을 시 교환
		if(low <= high)
			Swap(arr, low, high);
	}

	// low와 high가 교차했을 때, pivot과 high를 교환
	Swap(arr, left, high);
	
	// 옮겨진 pivot의 위치를 리턴
	return high;
}

void QuickSort(int arr[], int left, int right)
{
	if (left <= right)	// 재귀의 반복 조건(즉 left와 right가 교차 시 탈출함)
	{
		int pivot = Partition(arr, left, right); // 둘로 나누고
		QuickSort(arr, left, pivot - 1);		// 왼쪽 영역을 정렬
		QuickSort(arr, pivot + 1, right);		// 오른쪽 영역을 정렬
	}
}
