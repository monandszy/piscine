#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "ex03/ft_atoi.c"
#include "ex04/ft_putnbr_base.c"
#include "ex05/ft_atoi_base.c"

int	main(void)
{
	printf("testing ex03\n");
	char *ex03s1="--123abc123";
	int i = ft_atoi(ex03s1);
	printf("%d", i);
	printf("\n");
//	i = atoi(ex03s1);
//	printf("%d", i);

//	printf("\n");
	char *ex03s2="   ----++-++----123abc123";
	i = ft_atoi(ex03s2);
	printf("%d", i);
	printf("\n");
//	i = atoi(ex03s2);
//	printf("%d", i);

//	printf("\n");
	char *ex03s3="   ----++-++----abc123";
	i = ft_atoi(ex03s3);
	printf("%d", i);
	printf("\n");
//	i = atoi(ex03s3);
//	printf("%d", i);

	printf("testing ex04\n");
	ft_putnbr_base(127, "01");
	printf("\n");
	ft_putnbr_base(128, "01");
	printf("\n");
	ft_putnbr_base(64, "01");
	printf("\n");
	ft_putnbr_base(300, "01");
	printf("\n");
}
