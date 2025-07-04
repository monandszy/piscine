#include <stdio.h>
#include <unistd.h>
#include "ex00/ft_ft.c"
#include "ex01/ft_ultimate_ft.c"
#include "ex02/ft_swap.c"
#include "ex03/ft_div_mod.c"
#include "ex04/ft_ultimate_div_mod.c"
#include "ex05/ft_putstr.c"
#include "ex06/ft_strlen.c"
#include "ex07/ft_rev_int_tab.c"
#include "ex08/ft_sort_int_tab.c"

void print_array(int *arr, int size)
{
	int i = 0;

	while (i < size)
	{
		printf("%d", arr[i]);
		i++;
	}
}

int main(void)
{
	printf("---testing ex00, shold print 42---\n");	
	int tmp = 3;
	int * a;
	a = &tmp;
	ft_ft(a);
	printf("%d", *a);
	
	printf("\n---testing ex01, should print 42---\n");
	tmp = 3;
	int *b1 = &tmp;
	int **b2 = &b1;
	int ***b3 = &b2;
	int ****b4 = &b3;
	int *****b5 = &b4;
	int ******b6 = &b5;
	int *******b7 = &b6;
	int ********b8 = &b7;
	int *********b9 = &b8;
	ft_ultimate_ft(b9);
	printf("%d", *********b9);

	printf("\n---testing ex02, should print 1 and 2---\n");
	int i = 2;
	int j = 1;
	int *ip = &i;
	int *jp = &j;
	ft_swap(ip, jp);
	printf("%d, %d", *ip, *jp);

	printf("\n---testing ex03, should print 2 and 3---\n");
	int z = 0;
	i = 13;
	j = 5;
	*ip = i;
	*jp = j;
	ft_div_mod(i, j, ip, jp);
	printf("%d, %d", *ip, *jp);

	printf("\n---testing ex04, should display 2, 3---\n");
	i = 13;
	j = 5;
	*ip = i;
	*jp = j;
	ft_ultimate_div_mod(ip, jp);
	printf("%d, %d", *ip, *jp);

	printf("\n---testing ex05, expected output, catnip---\n");
	ft_putstr("catnip");

	printf("\n---testing ex06, expected output, 6---\n");
	int len = ft_strlen("catnip");
	printf("%d", len);

	printf("\n---testing ex07, expected output, 54321 and 654321---\n");
	int a1[] = {1, 2, 3, 4, 5};
	int a2[] = {1, 2, 3, 4, 5, 6};
	ft_rev_int_tab(a1, 5);
	print_array(a1, 5);
	printf("\n");
	ft_rev_int_tab(a2, 6);
	print_array(a2, 6);

	printf("\n---testing ex08, expected output 0123456789---\n");
	int a3[] = {9,8,7,6,5,4,3,2,1,0};
	ft_sort_int_tab(a3, 10);
	print_array(a3, 10);
}
