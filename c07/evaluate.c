#include <stdio.h>
#include <unistd.h>
#include "ex00/ft_strdup.c"
#include "ex01/ft_range.c"
#include "ex02/ft_ultimate_range.c"
#include "ex03/ft_strjoin.c"
#include "ex04/ft_convert_base.c"
#include "ex05/ft_split.c"

void print_int(int *arr, int size)
{
	int i = 0;
	char t;
	while(i < size)
	{
		if (arr[i] < 0)
		{
			arr[i] = -arr[i];
			write(1, "-", 1);
		}
		t = arr[i] + '0';
		write(1, &t, 1);
		i++;
	}
	write(1, "\n", 1);		
}

void print_matrix(int **matrix, int num_row, int num_col)
{
	int i, j;

  for (i = 0; i < num_row; i++) {
        for (j = 0; j < num_col; j++) {
            printf("%-3d ", matrix[i][j]); // Print with spacing
        }
        printf("\n");
  }
}

int main(void)
{
	printf("--testing ex00\n");
	char *str = "cat";
	char *dup = ft_strdup(str);
	printf("%s, %d, %d\n", dup, &str, &dup);

	printf("--testing ex01\n");
	print_int(ft_range(0, 10), 10);
	print_int(ft_range(-10, 10), 20);
	print_int(ft_range(-100, -10), 90);
//	print_int(ft_range(10, -10));
//	print_int(ft_range(0, 0));

	printf("--testing ex02\n");
	int **range;
	printf("s%d\n", ft_ultimate_range(range, 0, 10));
	print_matrix(range, 1, 10);
}
