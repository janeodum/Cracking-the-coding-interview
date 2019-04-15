#include <stdio.h>

int findpivot(int arr[], int l, int r)
{
	int pi;
	int mid = l + r/ 2;

	if ((arr[mid] > arr[mid + 1] )&& (arr[mid] > arr[mid - 1]))
	{
		return mid;
	}
	if ((arr[mid] < arr[mid + 1] )&& (arr[mid] > arr[mid - 1]))
	{
		return mid + 1;
	}
	return findpivot(arr, mid + 1, r);
}

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

int  pivotbinarysearch(int arr[], int n, int x)
{
	
	int pivot = findpivot(arr, 0, n - 1);
	if (pivot == -1)
	{
		return binarysearch(arr, 0, n-1, x);
	}
	if (arr[pivot] > x)
	{
		return binarysearch(arr, pivot + 1, n - 1, x);
	}
	if (arr[pivot] == x)
	{
		return pivot;
	}
	return binarysearch(arr, 0, pivot - 1, x);
		
}


int main() 
{ 
   // Let us search 3 in below array 
   int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}; 
   int n = sizeof(arr)/sizeof(arr[0]); 
   int key = 3;
   printf("%d\n", pivotbinarysearch(arr, n, key));
    
} 