#include <stdio.h>
#include <unistd.h>
#include <string.h>


char *replace(char *str)
{
	int j = 0;
	char t = t[3 * strlen(str)];
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i]!= ' ')
		{
			t[j++] = str[i];
		}
		else
		{
			t[j] = '%';
			t[j + 1] = '2';
			t[j + 2] = '0';
			j = j + 3;
		}
	}
	t[j] = '\0';
	return (str);

}

int main ()
{
	char s[20] = "jane is a developer";
	printf("%s\n", replace(s) );
}