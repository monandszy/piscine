#include <stdlib.h>

// int has size of 4
int	*ft_range(int min, int max)
{
	int *arr;
	int i;
	int size;

  if (min >= max)
    return (NULL);
	size = -min + max;
	if (size < 0)
		size = -size;
	arr = (int *) malloc(size * 4);
	
	i = 0;
	while (i < size)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}
