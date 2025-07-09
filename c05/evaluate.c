#include <stdio.h>
#include "ex00/ft_iterative_factorial.c"
#include "ex01/ft_recursive_factorial.c"
#include "ex02/ft_iterative_power.c"
#include "ex03/ft_recursive_power.c"
#include "ex04/ft_fibonacci.c"
#include "ex05/ft_sqrt.c"
#include "ex06/ft_is_prime.c"
#include "ex07/ft_find_next_prime.c"
#include "ex08/ft_ten_queens_puzzle.c"

int	main(void)
{
	printf("---testing ex00\n");
	printf("%d|", ft_iterative_factorial(0));
	printf("%d|", ft_iterative_factorial(3));
	printf("%d|", ft_iterative_factorial(5));
	printf("%d|", ft_iterative_factorial(9));

	printf("\n---testing ex01\n");
	printf("%d|", ft_recursive_factorial(0));
	printf("%d|", ft_recursive_factorial(3));
	printf("%d|", ft_recursive_factorial(5));
	printf("%d|", ft_recursive_factorial(9));

	printf("\n---testing ex02\n");
	printf("%d|", ft_iterative_power(0, 0));
	printf("%d|", ft_iterative_power(100, 0));
	printf("%d|", ft_iterative_power(2, 1));
	printf("%d|", ft_iterative_power(2, 2));
	printf("%d|", ft_iterative_power(2, 4));
	printf("%d|", ft_iterative_power(100, 10));
	printf("%d|", ft_iterative_power(16, 3));

	printf("\n---testing ex03\n");
	printf("%d|", ft_recursive_power(0, 0));
	printf("%d|", ft_recursive_power(100, 0));
	printf("%d|", ft_recursive_power(2, 1));
	printf("%d|", ft_recursive_power(2, 2));
	printf("%d|", ft_recursive_power(2, 4));
	printf("%d|", ft_recursive_power(100, 10));
	printf("%d|", ft_recursive_power(16, 3));

	printf("\n---testing ex04\n");
	printf("%d|", ft_fibonacci(0));
	printf("%d|", ft_fibonacci(1));
	printf("%d|", ft_fibonacci(2));
	printf("%d|", ft_fibonacci(3));
	printf("%d|", ft_fibonacci(4));
	printf("%d|", ft_fibonacci(5));
	printf("%d|", ft_fibonacci(6));
	printf("%d|", ft_fibonacci(7));

	printf("\n---testing ex05\n");
	printf("%d|", ft_sqrt(0));
	printf("%d|", ft_sqrt(1));
	printf("%d|", ft_sqrt(2));
	printf("%d|", ft_sqrt(4));
	printf("%d|", ft_sqrt(9));
	printf("%d|", ft_sqrt(10));

	printf("\n---testing ex06\n");
	printf("%d|", ft_is_prime(0));
	printf("%d|", ft_is_prime(1));
	printf("%d|", ft_is_prime(2));
	printf("%d|", ft_is_prime(6));
	printf("%d|", ft_is_prime(41));


	printf("\n---testing ex07\n");
	printf("%d|", ft_find_next_prime(0));
	printf("%d|", ft_find_next_prime(1));
	printf("%d|", ft_find_next_prime(2));
	printf("%d|", ft_find_next_prime(7));
	printf("%d|", ft_find_next_prime(8));
	printf("%d|", ft_find_next_prime(1200));

	printf("\n---testing ex08\n");
	printf("%d|", ft_ten_queens_puzzle(0));
	return (0);
}
