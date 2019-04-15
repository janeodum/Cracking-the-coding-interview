#include <stdio.h>

void merge (int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
	{
		L[n1] = arr[l + i];
	}
	for (j = 0; j < n2; j++)
	{
		R[n2] = arr[m + 1 + j];
	}

	i = 0;
	j = 0;
	k = 1;

	while (i < n1 && j < n2)
	{
		if (L[i] < R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 

}


void mergesort(int arr[], int l, int r, )
{
	if (l < r)
	{
		int mid = l - (r - l)/ 2;

		mergesort(arr, l, mid);
		mergesort(arr, mid+1, r);
		merge(arr, l, mid, r);
	}
}

void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 