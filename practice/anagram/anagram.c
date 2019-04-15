#include <stdio.h>
#include <stdbool.h>

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

int  checkanagram(char *str1, char *str2)
{
	int str1count[256] = { 0 };
	int str2count[256] = { 0 };
	int ctr;

	if (ft_strlen(str1) != ft_strlen(str2))
	{
		return (0);
	}
	//count frequency of characters in str1

	for (ctr = 0; str1[ctr] != '\0'; ctr++)
	{
		str1count[str1[ctr]]++;
	}
	//count frequency of characters in str2 

	for (ctr = 0; str2[ctr] != '\0'; ctr++)
	{
		str2count[str2[ctr]]++;
	}
	//compare character counts of both strings 

	for (ctr = 0; ctr < 256; ctr++)
	{
		if (str1count[ctr] != str2count[ctr])
		{
			return (0);
		}

	}
	return (1);

}

int main ()
{
	char *s1 = "spare";
	char *s2 = "janet" ;
	printf("%d\n", checkanagram(s1, s2));
}