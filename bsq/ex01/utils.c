/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 14:47:28 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/15 19:35:28 by bkarabab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fts.h"

extern char **g_matrix;

void	print_matrix(int row_size, int col_size)
{
	int	i;

	i = 0;
	while (i < col_size)
	{
		write(1, g_matrix[i], row_size - 1);
		write(1, "\n", 1);	
		i++;
	}
}
