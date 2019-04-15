#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct word
{
	char * str;
	int index;
};

struct DuppArray
{
	int size;
	struct word * array;
};

struct DuppArray * createDupp(char* str[], int size)
{
	struct DuppArray * dupArray = (struct DuppArray *)malloc(sizeof(struct DuppArray));
	dupArray->size = size;
	dupArray->array = (struct word *)malloc(dupArray->size * sizeof(struct word));

	int i;
	for(i = 0; i < size; ++i)
	{
		dupArray->array[i].index = i;
		dupArray->array[i].str = (char *)malloc(strlen(str[i]) + 1);
		strcpy(dupArray->array[i].str, str[i]);
	}
	return dupArray;
}

int comparchar(const void *a, const void *b)
{
	return *(char *)a - *(char *)b;
}

int comparstr(const void *a, const void *b)
{
	struct word * a1 = (struct word *)a;
	struct word * b2 = (struct word *)b;
	return strcmp(a1->str ,b2->str);
} 

void printanagramtogether(char* wordarr[], int size)
{
	struct DuppArray * dupArray = createDupp(wordarr, size);

	int i;
	for (i = 0; i < size; ++i)
	{
		qsort(dupArray->array[i].str, strlen(dupArray->array[i].str), sizeof(char), comparchar);
	}
	qsort(dupArray->array, size, sizeof(dupArray->array[0]), comparstr);
	for(i = 0; i < size; ++i)
	{
		printf("%s\n", wordarr[dupArray->array[i].index]);
	}

}

int main() 
{ 
    char* wordArr[] = { "cat", "dog", "tac", "god", "act" }; 
    int size = sizeof(wordArr) / sizeof(wordArr[0]); 
    printanagramtogether(wordArr, size); 
    return 0; 
} 