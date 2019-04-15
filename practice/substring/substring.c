#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int isSubstring(char s1[], char s2[])
{
	if (strstr(s1, s2) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
char* concat(const char *s1, const char *s2)
{
    char *result = malloc(strlen(s1) + strlen(s2) + 1); // +1 for the null-terminator
    // in real code you would check for errors in malloc here
    if (result == NULL)
    {
    	return 0;
    }
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
int isRotate(char s1[], char s2[])
{
	if (strlen(s1) != strlen(s2))
	{
		return false;
	}
	return isSubstring(concat(s1, s1), s2);
}

int main ()
{
	char s1[12] = "waterbottle";
	char s2[12] = "erbottlewat";
	printf("%d\n", isRotate(s1, s2) );
}