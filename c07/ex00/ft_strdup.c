
#include <stdlib.h>

char *ft_strdup(char *src)
{
	int l1;
	int i;
	char* new;

	l1 = 0;
	while(src[l1])
		l1++;
	new = (char *) malloc((l1 + 1) * (1));
	i = 0;
	while (src[i])
	{
		new[i] = src[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}	
