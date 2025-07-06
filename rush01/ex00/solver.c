/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 23:41:11 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/06 20:54:48 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_matrix[4][4];
int	g_top[4];
int	g_btm[4];
int	g_lft[4];
int	g_rig[4];

void	print_msg(void);
int		*rev(int *arr);
int		validate_visibility(int *arr);
int		validate_row_col(int row, int col, int num);
void	print_matrix(void);
int		check_matrix(void);
int		brute_force(int pos);
void	solve_matrix(void);

int	check_visibilities(int i, int *row, int *col)
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

// extracts row and column for a given i from the matrix
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
		if (check_visibilities(i, row, col) == 1)
			return (1);
		i++;
	}
	return (0);
}

// pos is from 0 to 15. If position is 16 the whole matrix is filled;
// if check matrix returns 1, then
// validate_row_col checks if the incrementing number can be put in the matrix,
// checks if it is not present in the current row and column.
// BF(0) -> BF(1) ... BF(15) -> BF(16)
// BF(16) return 1; -> BF(15)
// pos + 1 is not the same as pos++
// if no 4 numbers are valid goes to the previous position (return 1)
// if a number passes goes deeper to the next position (BF(next_position)
int	brute_force(int pos)
{
	int	row;
	int	col;
	int	input_num;
	int	returned;
	int	next_pos;

	if (pos == 16)
		return (check_matrix());
	next_pos = pos + 1;
	row = pos / 4;
	col = pos % 4;
	input_num = 1;
	while (input_num <= 4)
	{
		if (validate_row_col(row, col, input_num) == 0)
		{
			g_matrix[row][col] = input_num;
			returned = brute_force(next_pos);
			if (returned == 0)
				return (0);
			g_matrix[row][col] = 0;
		}
		input_num++;
	}
	return (1);
}

// INPUT ERROR: unable to solve with current sides, no possible combination
void	solve_matrix(void)
{
	if (brute_force(0) == 0)
	{
		print_matrix();
	}
	else
	{
		print_msg();
	}
}
