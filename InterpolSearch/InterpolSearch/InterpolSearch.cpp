#include "InterpolSearch.h"
#include <cstdio>
int ISearch(int arr[], int low, int high, int target)
{

    if (low > high)
        return -1;
    /*if (arr[low] > target || arr[high] < target)
        return - 1;*/

    int s = ((double)target - arr[low]) / ((double)arr[high] - arr[low]) * ((double)high - low) + low;

    printf("low : %d, high : %d, s : %d\n", low, high, s);

    if (arr[s] == target)
        return s;
    else if (arr[s] > target)
        return ISearch(arr, low, s - 1, target);
    else
        return ISearch(arr, s + 1, high, target);
}
