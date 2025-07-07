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

	char *ex03s4="0000123";
	i = ft_atoi(ex03s4);
	printf("%d", i);
	printf("\n");

	printf("testing ex04\n");
	ft_putnbr_base(127, "01");
	printf("\n");
	ft_putnbr_base(-128, "01");
	printf("\n");
	ft_putnbr_base(64, "abcd");
	printf("\n");
	ft_putnbr_base(300, "0123456789ABCDEF");
	printf("\n");
	ft_putnbr_base(300, "abccde");
	printf("\n");


	printf("testing ex05\n");
	printf("%d\n", ft_atoi_base("101101", "01"));
	printf("%d\n", ft_atoi_base(" -10wd", "01"));
	printf("%d\n", ft_atoi_base(" --bb", "ab"));
	printf("%d\n", ft_atoi_base(" -0000122", "01"));
	printf("%d\n", ft_atoi_base("1000001", "01"));
	printf("%d\n", ft_atoi_base("0a", "0123456789abcdef"));
	printf("%d\n", ft_atoi_base("11111111111111111111111111", "01"));

}
