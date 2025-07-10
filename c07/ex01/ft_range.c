/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 10:37:51 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/10 11:35:34 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

// int has size of 4
int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;
	int	size;

	if (min >= max)
		return (NULL);
	size = -min + max;
	if (size < 0)
		size = -size;
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
