#include "RadixSort.h"
#include <queue>
#include <vector>

void RadixSort(int arr[], int num, int maxLen)
{
	using namespace std;
	vector<queue<int>> buckets(BUCKET_NUM);

	int divfac = 1;
	int radix;

	// 가장 긴 데이터의 길이만큼 반복
	for (int pos = 0; pos < maxLen; ++pos)
	{
		// 정렬대상의 수만큼 반복
		for (int di = 0; di < num; ++di)
		{
			// n번째 자리의 숫자 추출
			radix = arr[di] / divfac % 10;
			
			// 추출한 숫자를 근거로 버킷에 데이터 저장
			buckets[radix].push(arr[di]);
		}

		// 버킷 수만큼 반복
		for (int bi = 0, di = 0; bi < BUCKET_NUM; ++bi)
		{
			// 버킷에 저자왼 것 순서대로 다 꺼내서 다시 arr에 저장
			while (!buckets[bi].empty())
			{
				arr[di++] = buckets[bi].front();
				buckets[bi].pop();
			}	
		}

		// N번째 자리의 숫자 추출을 위한 피제수의 증가
		divfac *= 10;
	}
}
