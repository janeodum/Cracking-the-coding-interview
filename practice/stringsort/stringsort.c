#include <stdio.h>
#include <string.h>
#define MAX_LEN 100

void stringsort(char arr[][MAX_LEN], int n)
{
	int i, j, mid;
	char midstr[MAX_LEN];

	for (i = 0; i < n - 1; i++)
	{
		mid = i;
		strcpy(midstr, arr[i]);
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(midstr, arr[j]) > 0)
			{
				strcpy(midstr, arr[j]);
				mid = j;
			}
		}
		if (mid != i)
		{
			char temp[MAX_LEN];
			strcpy(temp, arr[i]);
			strcpy(arr[i], arr[mid]);
			strcpy (arr[mid], temp);
		}
	}
}

void printArray(char arr[][MAX_LEN], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%s ", arr[i]); 
    printf("\n"); 
} 

int main ()
{
	char arr[][MAX_LEN] = {"paper", "true" ,"soap", "floppy", "flower"};
	int n = sizeof(arr) / sizeof(arr[0]);
	stringsort(arr, n);
	printArray(arr, n);
}