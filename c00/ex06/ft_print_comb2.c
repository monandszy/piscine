/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 10:48:54 by sandrzej          #+#    #+#             */
/*   Updated: 2025/06/30 18:41:11 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	pc(char c)
{
	write(1, &c, 1);
}

void	print_set(int first, int second, int prev_first, int prev_second)
{
	pc(prev_first + '0');
	pc(prev_second + '0');
	pc(' ');
	pc(first + '0');
	pc(second + '0');
	if (prev_first != 9 || prev_second != 8 || first != 9 || second != 9)
	{
		pc(',');
		pc(' ');
	}
}

void	print_second(int prev_first, int prev_second, int prev_count)
{
	int	first;
	int	second;
	int	count;

	first = 0;
	second = 0;
	count = 0;
	while (first <= 9)
	{
		while (second <= 9)
		{
			if (prev_count < count)
			{
				print_set(first, second, prev_first, prev_second);
			}
			second++;
			count++;
		}
		second = 0;
		first++;
	}
}

void	ft_print_comb2(void)
{
	int	first;
	int	second;
	int	count;

	first = 0;
	second = 0;
	count = 0;
	while (first <= 9)
	{
		while (second <= 9)
		{
			print_second(first, second, count);
			second++;
			count++;
		}
		second = 0;
		first++;
	}
}
