/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 23:24:05 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/07 19:05:21 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int	g_matrix[4][4];

/* void	print_intarr(int *arr)
{
	int		i;
	char	c;

	i = 0;
	while (i < 4)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
		i++;
	}
} */

void	print_msg(void)
{
	int		i;
	char	*msg;

	msg = "Error";
	i = 0;
	while (msg[i])
	{
		write(1, &msg[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	print_matrix(void)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			tmp = g_matrix[i][j] + '0';
			write(1, &tmp, 1);
			j++;
			if (j != 4)
				write(1, " ", 1);
		}
		write(1, "\n", 1);
		i++;
	}
}

/* void	fillnull(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			g_matrix[i][j] = 'x' - '0';
			j++;
		}
		i++;
	}
} */
