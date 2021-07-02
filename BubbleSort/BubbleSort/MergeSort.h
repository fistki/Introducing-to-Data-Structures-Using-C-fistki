#pragma once

void MergeTwoArea(int arr[], int left, int mid, int right)
{
	int fIdx = left;
	int rIdx = mid + 1;
	
	// left가 0보다 크면 공간 낭비이지만 여유롭게 메모리 공간을 잡는다.
	int* sortArr = new int[right + 1];
	int sIdx = left;

	while (fIdx <= mid && rIdx <= right)
	{
		if (arr[fIdx] <= arr[rIdx])
			sortArr[sIdx++] = arr[fIdx++];
		else
			sortArr[sIdx++] = arr[rIdx++];
	}

	// 정렬된 부분의 왼쪽 부분이 먼저 sortArr에 다 들어간 경우
	if (fIdx > mid)
	{
		for (int i = rIdx; i <= right; ++i, ++sIdx)
		{
			sortArr[sIdx] = arr[i];
		}
	}

	// 정렬된 부분의 오른쪽 부분이 먼저 sortArr에 다 들어간 경우
	else
	{
		for (int i = fIdx; i <= mid; ++i, ++sIdx)
		{
			sortArr[sIdx] = arr[i];
		}
	}


	// 정렬되게 합쳐진 sortArr을 arr로 다시 복사

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
		// 중간 지점 계산
		mid = (left + right) / 2;

		MergeSort(arr, left, mid);
		MergeSort(arr, mid + 1, right);

		MergeTwoArea(arr, left, mid, right);
	}
}
