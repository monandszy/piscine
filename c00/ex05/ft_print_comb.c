/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 20:03:03 by sandrzej          #+#    #+#             */
/*   Updated: 2025/06/30 18:41:16 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	cast_and_write(int c)
{
	int	tmp;

	tmp = c + 48;
	write(1, &tmp, 1);
}

void	loop(int first, int second, int third)
{
	if (first < second && second < third && third <= 9)
	{
		cast_and_write(first);
		cast_and_write(second);
		cast_and_write(third);
		if (first != 7 || second != 8 || third != 9)
		{
			write(1, ", ", 2);
		}
	}
}

void	ft_print_comb(void)
{
	int	first;
	int	second;
	int	third;

	first = 0;
	second = 0;
	third = 0;
	while (first <= 9)
	{
		while (second <= 9)
		{
			while (third <= 9)
			{
				loop(first, second, third);
				third++;
			}
			second++;
			third = 0;
		}
		first++;
		second = 0;
	}
}
