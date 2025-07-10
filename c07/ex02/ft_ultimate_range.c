#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int size;

	if (min >= max)
  	{
    		range = NULL;
    		return (0);
  	}
	size = -min + max;
	if (size < 0)
		size = -size; 
	range = (int **) malloc(size * sizeof(int *));
	
	i = 0;
	while (i < size)
	{
		range[i] = (int *) malloc(10 * sizeof(int));
		range[i][0] = 1;
    range[i][1] = 1;
		min++;
		i++;
	}
	return (size);
}
