/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 10:46:13 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/12 11:39:02 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// int has size of 4
int	*get_range(int min, int size)
{
	int	*arr;
	int	i;

	arr = (int *) malloc(size * sizeof(int));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	size = -min + max;
	if (size < 0)
		size = -size;
	*range = get_range(min, size);
	if (range == NULL)
		return (-1);
	return (size);
}
