#include "RadixSort.h"
#include <queue>
#include <vector>

void RadixSort(int arr[], int num, int maxLen)
{
	using namespace std;
	vector<queue<int>> buckets(BUCKET_NUM);

	int divfac = 1;
	int radix;

	// ���� �� �������� ���̸�ŭ �ݺ�
	for (int pos = 0; pos < maxLen; ++pos)
	{
		// ���Ĵ���� ����ŭ �ݺ�
		for (int di = 0; di < num; ++di)
		{
			// n��° �ڸ��� ���� ����
			radix = arr[di] / divfac % 10;
			
			// ������ ���ڸ� �ٰŷ� ��Ŷ�� ������ ����
			buckets[radix].push(arr[di]);
		}

		// ��Ŷ ����ŭ �ݺ�
		for (int bi = 0, di = 0; bi < BUCKET_NUM; ++bi)
		{
			// ��Ŷ�� ���ڿ� �� ������� �� ������ �ٽ� arr�� ����
			while (!buckets[bi].empty())
			{
				arr[di++] = buckets[bi].front();
				buckets[bi].pop();
			}	
		}

		// N��° �ڸ��� ���� ������ ���� �������� ����
		divfac *= 10;
	}
}
