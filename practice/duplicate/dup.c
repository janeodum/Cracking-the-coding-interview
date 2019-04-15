#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *s)
{
	int i;
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char  *removeduplicate(char *str)
{
	int j, tail;

	tail = 1;
	if (!str || !*str)
	{
		return 0;
	}
	else
	{
		for (int i = 0; i < ft_strlen(str); i++)
		{
			for ( j = 0; j < tail; j++)
			{
				if (str[i] == str[j])
				{
					break;
				}
			}
			if (j == tail)
			{
				str[tail] = str[i];
				tail++;
			}
		}
		str[tail]= '\0';
	}
	return str;
}

int main ()
{
	char s[13] = "aaaabbbb";
	printf("%s\n",removeduplicate(s) );
}