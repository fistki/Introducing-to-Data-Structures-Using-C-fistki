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

	// low�� hight�� ������ �� ���� �ݺ�
	while (low <= high)
	{
		// low�� �ǹ����� ū(���Ŀ켱������ ����) ���� ã��
		while (pivot >= arr[low] && low <= right)
			low++;
		// high�� �ǹ����� ����(���Ŀ켱������ ����) ���� ã��
		while (pivot <= arr[high] && high >= left + 1)
			high--;

		// �������� �ʾ��� �� ��ȯ
		if(low <= high)
			Swap(arr, low, high);
	}

	// low�� high�� �������� ��, pivot�� high�� ��ȯ
	Swap(arr, left, high);
	
	// �Ű��� pivot�� ��ġ�� ����
	return high;
}

void QuickSort(int arr[], int left, int right)
{
	if (left <= right)	// ����� �ݺ� ����(�� left�� right�� ���� �� Ż����)
	{
		int pivot = Partition(arr, left, right); // �ѷ� ������
		QuickSort(arr, left, pivot - 1);		// ���� ������ ����
		QuickSort(arr, pivot + 1, right);		// ������ ������ ����
	}
}
