#include <stdio.h>

int search(int arr[], int x, int n)
{
	int i;

	for (i = 0; i < n; i++)
	{
		if (arr[i] == x)
		{
			return (i);
		}
	}
	return (-1);

}

int main ()
{
	int arr[7] = { 20, 40 , 89, 56, 45, 67, 84};
	int x = 56;
	printf("%d\n", search(arr, x, 7));
}