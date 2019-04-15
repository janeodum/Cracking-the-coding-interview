#include <stdio.h>

int binarysearch(int arr[], int l, int r, int x)
{
	if (r >= l)
	{
		int mid;
		mid = l + (r - l)/ 2;
		if (arr[mid] == x)
		{
			return mid;
		}
		if (arr [mid] > x)
		{
			return binarysearch(arr, l, mid - 1, x);
		}
		if (arr[mid] < x)
		{
			return binarysearch(arr, mid + 1, r, x);
		}
	}
	return -1;
}

int main ()
{
	int arr[7] = {20, 40, 60, 70, 90, 100, 130};
	int n = sizeof (arr) / sizeof (arr[0]);
	printf("%d\n", binarysearch(arr, 0, n - 1, 90) );
}