#include <stdio.h>

void rotate(int arr[], int d, int n)
{
	int temp,temp2, i, j;
	j = 0;
	i = 0;
	while(i < d){
		temp = arr[i];
		i++;
	}

	
	while (j < d && d < n)
	{
		arr[j] = arr[d];
		j++;
		d++;
	}
	arr[n - 1] = temp;

}

void printarray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d\n", arr[i]);
	}
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7};
	int d = 2;
	int n = sizeof (arr) / sizeof(arr[0]);
	rotate(arr, d, n);
	printarray(arr, n);
}