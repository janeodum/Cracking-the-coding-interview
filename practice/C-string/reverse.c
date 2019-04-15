#include <unistd.h>
#include <stdio.h>


static void ft_swap(char *a, char *b)
{
	char temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

char *strrev(char *str)
{
	char *begin;
	char *end;

	begin = str;
	end = str;

	while (*end != '\0')
	{
		end++;
	}
	end--;

	while (begin < end)
	{
		ft_swap(begin, end);
		begin++;
		end--;
	}
	return (str);
}
int main (void)
{
	char str[5] = "abcd";
	printf("%s\n",strrev(str));
}
