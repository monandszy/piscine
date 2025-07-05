/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 23:48:26 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/05 23:50:44 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int	g_matrix[4][4];

int	validate_visibility(int *arr)
{
	int	max;
	int	m_c;
	int	i;

	max = 0;
	m_c = 0;
	i = 0;
	while (i < 4)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			m_c++;
		}
		i++;
	}
	return (m_c);
}

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

int	validate_row_col(int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (g_matrix[row][i] == num || g_matrix[i][col] == num)
		{
			return (1);
		}
		i++;
	}
	return (0);
}
