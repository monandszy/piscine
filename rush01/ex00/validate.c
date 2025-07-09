/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 23:48:26 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/08 13:49:42 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int	g_matrix[4][4];

int	validate_visibility(int *arr)
{
	int	seen_max;
	int	visibility;
	int	current_pos;

	seen_max = 0;
	visibility = 0;
	current_pos = 0;
	while (current_pos < 4)
	{
		if (arr[current_pos] > seen_max)
		{
			seen_max = arr[current_pos];
			visibility++;
		}
		current_pos++;
	}
	return (visibility);
}

// reverses int array, example 1234 to 4321
int	*rev(int *arr)
{
	int	f;
	int	l;
	int	tmp;

	f = 0;
	l = 3;
	while (f < l)
	{
		tmp = arr[f];
		arr[f] = arr[l];
		arr[l] = tmp;
		f++;
		l--;
	}
	return (arr);
}

// if number is already in row or col return 1
// if I am checking the row, then I have to change / go through the colums (i)
// if I am checking the column then I have to change / go through the rows (i)
// position of cell is given by [row][col]
// Checks both the column and the row at the same time
int	validate_row_col(int row, int col, int input_num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (g_matrix[row][i] == input_num || g_matrix[i][col] == input_num)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
