#include "ex01/ft_boolean.h"
#include "ex02/ft_abs.h"
#include "ex03/ft_point.h"
#include <unistd.h>
#include <stdio.h>

void ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

t_bool  ft_is_even(int nbr)
{
	return ((EVEN(nbr)) ? TRUE : FALSE);
}

void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int main(int argc, char **argv)
{
	(void)argv;
	if (ft_is_even(argc - 1) == TRUE)
    	ft_putstr(EVEN_MSG);
	else
    	ft_putstr(ODD_MSG);

	printf("%d\n", ABS(-1));
	printf("%d\n", ABS(1));

	t_point point;

	set_point(&point);
	printf("%d\n", point.x);
	printf("%d\n", point.y);

	return (SUCCESS);
}
