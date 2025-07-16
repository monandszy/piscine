/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:47:28 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/15 14:54:26 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern char **g_matrix;

void	print_matrix(int row_size)
{
	int	i;
	int	j;

	i = 0;
	while (g_matrix[i])
	{
		j = 0;
		while(g_matrix[i][j])
		{
			write(1, &g_matrix[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
