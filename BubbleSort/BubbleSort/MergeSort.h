#pragma once

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;
	
	// left�� 0���� ũ�� ���� ���������� �����Ӱ� �޸� ������ ��´�.
	int* sortArr = new int[right + 1];
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx++] = arr[fIdx++];
		else
			sortArr[sIdx++] = arr[rIdx++];
	}

	// ���ĵ� �κ��� ���� �κ��� ���� sortArr�� �� �� ���
	if (fIdx > mid)
	{
		for (int i = rIdx; i <= right; ++i, ++sIdx)
		{
			sortArr[sIdx] = arr[i];
		}
	}

	// ���ĵ� �κ��� ������ �κ��� ���� sortArr�� �� �� ���
	else
	{
		for (int i = fIdx; i <= mid; ++i, ++sIdx)
		{
			sortArr[sIdx] = arr[i];
		}
	}


	// ���ĵǰ� ������ sortArr�� arr�� �ٽ� ����

	for (int i = left; i <= right; ++i)
	{
		arr[i] = sortArr[i];
	}

	delete[] sortArr;
}

void MergeSort(int arr[], int left, int right)
{
	int mid;

	if (left < right)
	{
		// �߰� ���� ���
		mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeTwoArea(arr, left, mid, right);
	}
}
