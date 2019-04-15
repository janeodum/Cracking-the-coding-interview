#include <stdio.h>
#define NA -1

void sortedmerge(int A[], int B[], int n, int m)
{
	int i = n - 1;
	int j = m - 1;

	int lastindex = n + m - 1;
	while (j >= 0)
	{
		if (i >= 0 && A[i] > B[j])
		{
			A[lastindex] = A[i];
			i--;
		}
		else
		{
			A[lastindex] = B[j];
			j--;
		}
		lastindex--;
	}
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%d\n", arr[i]);
	}
}

int main()
{
	int A[] = {1 , 2, 3, 4, 5, NA, NA, NA, NA, NA};
	int B[] = {6, 7, 8, 9, 10};
	int n= 5;
	int m = 5;
	int o = m + n;
	sortedmerge(A, B, n, m);
	printArray(A, o);
}