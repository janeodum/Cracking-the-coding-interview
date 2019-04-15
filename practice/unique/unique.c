#include <stdio.h>
#include <unistd.h>
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
 bool uniquechar(char str[])
{
    int i;
    int j;
    
    for (i = 0; i < ft_strlen(str); i++)
    {
	for (j = i + 1; j < ft_strlen(str); j++)
    {
	    
   	    if (str[i]== str[j])
    	{
            return false;
        }
	}
    }
    return true;
}

int main()
{
    char s[20] = "qwertyuiopasdfghjkl";
    printf("%b\n", uniquechar(s));
    return (0);
}
