#include <stdio.h>
#include <unistd.h>
#include "ex00/ft_strdup.c"
#include "ex01/ft_range.c"
#include "ex02/ft_ultimate_range.c"
#include "ex03/ft_strjoin.c"
#include "ex05/ft_split.c"

void print_int(int *arr, int size)
{
	int i = 0;
	while(i < size)
	{
		printf("%d", arr[i]);
		i++;
	}
	printf("\n");
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
	printf("%s, %lu, %lu\n", dup, sizeof(str), sizeof(dup));

	printf("--testing ex01\n");
	print_int(ft_range(0, 10), 10);
	print_int(ft_range(-10, 10), 20);
	print_int(ft_range(-100, -10), 90);
//	print_int(ft_range(10, -10));
//	print_int(ft_range(0, 0));

	printf("--testing ex02\n");
	int *range;
	printf("s[%d]\n", ft_ultimate_range(&range, 0, 5));
	print_int(range, 5);

	int *range2;
	printf("s[%d]\n", ft_ultimate_range(&range2, 0, 0));
	printf("%p\n", range); // triggers seg fault

	int *range3;
	printf("s[%d]\n", ft_ultimate_range(&range3, -5, 5));
	print_int(range3, 10);


	printf("---testing ex03\n");
	char *strs[] = {"cat", "in", "a", "cup"};
	printf("%s\n", ft_strjoin(4, strs, " ,,,,"));
	free(ft_strjoin(-5, strs, " "));

/*	printf("---testing ex05---\n");
	char **split = ft_split("||||cat1||cat2||||cat3||||cat4||", "||");
    printf("[%s]\n", split[0]);
    printf("[%s]\n", split[1]);
    printf("[%s]\n", split[2]);
    printf("[%s]\n", split[3]);
    printf("[%s]\n", split[4]);
	char **split1 = ft_split("||||cat1||cat2||||cat3||||cat4||", "");
    printf("[%s]\n", split1[0]);
    printf("[%s]\n", split1[1]);
    printf("[%s]\n", split1[2]); */
}
