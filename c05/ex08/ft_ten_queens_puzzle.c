/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:32:37 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/09 15:19:39 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_matrix[10][10];
int	g_counter;

void	matrix_counter(void)
{
	int		i;
	int		j;
	char	tmp;

	g_counter++;
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			if (g_matrix[j][i] == '*')
			{
				tmp = j + '0';
				write(1, &tmp, 1);
			}
			j++;
		}
		i++;
	}
	write(1, "\n", 1);
}

int	is_valid(int mtrow, int mtcol, int ptrow, int ptcol)
{
	if ((mtrow >= 0 && ptcol < 10 && g_matrix[mtrow][ptcol] == '*')
	|| (mtrow >= 0 && mtcol >= 0 && g_matrix[mtrow][mtcol] == '*')
	|| (ptrow < 10 && mtcol >= 0 && g_matrix[ptrow][mtcol] == '*')
	|| (ptrow < 10 && ptcol < 10 && g_matrix[ptrow][ptcol] == '*'))
		return (1);
	else
		return (0);
}

int	validate_position(int row, int col)
{
	int	i;
	int	mtrow;
	int	mtcol;
	int	ptrow;
	int	ptcol;

	i = 0;
	mtrow = row;
	mtcol = col;
	ptrow = row;
	ptcol = col;
	while (i < 10)
	{
		mtrow--;
		mtcol--;
		ptrow++;
		ptcol++;
		if ((g_matrix[row][i] == '*' || g_matrix[i][col] == '*')
		|| (is_valid(mtrow, mtcol, ptrow, ptcol == 1)))
			return (1);
		i++;
	}
	return (0);
}

int	nest(int col)
{
	int	row;

	row = 0;
	if (col == 10)
	{
		matrix_counter();
		return (1);
	}
	while (row < 10)
	{
		if (validate_position(row, col) == 0)
		{
			g_matrix[row][col] = '*';
			nest(col + 1);
			g_matrix[row][col] = '.';
		}
		row++;
	}
	return (1);
}

int	ft_ten_queens_puzzle(void)
{
	nest(0);
	return (g_counter);
}
