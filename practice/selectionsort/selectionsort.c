#include <stdio.h>

 void ft_swap (int *a, int *b)
 {
 	int temp = *a;
 	*a = *b;
 	*b = temp;
 }

 void selectionsort(int arr[], int n)
 {
 	int i, mid, j;

 	for(i = 0; i < n-1; i++)
 	{
 		mid = i;
 		for ( j = i + 1; j < n; j++)
 		{
 			if (arr[j] < arr[mid])
 			{
 				mid = j;
 			}
 		}
 		ft_swap(&arr[mid], &arr[i]);

 	} 

 }

void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

 int main ()
 {
 	int arr[] = {64, 25, 12, 22, 11};
 	int n = sizeof (arr) / sizeof (arr[0]);
 	selectionsort(arr, n);
 	printArray(arr, n);

 }