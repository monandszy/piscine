/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:40:44 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/09 15:10:02 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	fibonacci(int prev, int curr, int index)
{
	if (index > 1)
	{
		index--;
		curr = fibonacci(curr, (prev + curr), index);
	}
	return (curr);
}

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (1);
	if (index == 0)
		return (0);
	return (fibonacci(0, 1, index));
}
