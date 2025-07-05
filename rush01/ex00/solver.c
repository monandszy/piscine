/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 23:41:11 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/05 23:47:49 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	g_matrix[4][4];
int	g_top[4];
int	g_btm[4];
int	g_lft[4];
int	g_rig[4];

void	print_msg(char *msg);
int		*rev(int *arr);
int		validate_visibility(int *arr);
int		validate_row_col(int row, int col, int num);
void	print_matrix(void);
void	fill_null(void);
int		check_matrix(void);
int		brute_force(int pos);
void	solve_matrix(void);

int	check_visibilities(int *row, int *col)
{
	if (validate_visibility(col) != g_top[i])
		return (1);
	else if (validate_visibility(rev(col)) != g_btm[i])
		return (1);
	else if (validate_visibility(row) != g_lft[i])
		return (1);
	else if (validate_visibility(rev(row)) != g_rig[i])
		return (1);
	else
		return (0);
}

int	check_matrix(void)
{
	int	i;
	int	j;
	int	col[4];
	int	row[4];

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			row[j] = g_matrix[i][j];
			col[j] = g_matrix[j][i];
			j++;
		}
		return (check_visbilities(row, col));
		i++;
	}
	return (0);
}

int	brute_force(int pos)
{
	int	row;
	int	col;
	int	num;

	if (pos == 16)
		return (check_matrix());
	row = pos / 4;
	col = pos % 4;
	num = 1;
	while (num <= 4)
	{
		if (validate_row_col(row, col, num) == 0)
		{
			g_matrix[row][col] = num;
			if (brute_force(pos + 1) == 0)
				return (0);
			g_matrix[row][col] = 0;
		}
		num++;
	}
	return (1);
}

void	solve_matrix(void)
{
	brute_force(0);
	print_matrix();
}
