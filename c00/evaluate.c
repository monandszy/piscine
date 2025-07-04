#include <unistd.h>
#include <stdio.h>
#include "ex00/ft_putchar.c"
#include "ex01/ft_print_alphabet.c"
#include "ex02/ft_print_reverse_alphabet.c"
#include "ex03/ft_print_numbers.c"
#include "ex04/ft_is_negative.c"
#include "ex05/ft_print_comb.c"
#include "ex06/ft_print_comb2.c"
#include "ex07/ft_putnbr.c"
#include "ex08/ft_print_combn.c"

int	main(void)
{
	printf("\n---testing ex00, with char 'c'---\n");
	char c = 'c';
	ft_putchar(c);

	printf("\n---testing ex01---\n");
	ft_print_alphabet();

	printf("\n---testing ex02---\n");
	ft_print_reverse_alphabet();

	printf("\n---testing ex03---\n");
	ft_print_numbers();

	printf("\n---testing ex04, order: 1, -1, null--- \n");
	int p = 1;
	int n = -1;
	int nl;
	ft_is_negative(p);
	ft_is_negative(n);
	ft_is_negative(nl);

	printf("\n---testing ex05---\n");
	ft_print_comb();

	printf("\n---testing ex06---\n");
	ft_print_comb2();

	printf("\n---testing ex07---\n");
	int test1 = 2147483647;
	int test2 = -2147483647;
	ft_putnbr(test1);
	printf("\n");
	ft_putnbr(test2);
	printf("\n");
	ft_putnbr(0);
	printf("\n");
	ft_putnbr(100100100);
	printf("\n");
	ft_putnbr(2147483648);
	printf("\n");
	ft_putnbr(-2147483648);
	printf("\n");
	ft_putnbr(00000000000);

	printf("---testing ex08--- \n");
	ft_print_combn(2);
	printf("\n");
	ft_print_combn(3);
	printf("\n");
	ft_print_combn(0);
	printf("\n");
	ft_print_combn(9);
}

