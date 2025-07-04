/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 15:10:00 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/03 11:00:52 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

// add printing last as 0 only (for first line and other i+16)
void	get_hex(unsigned long mem, int i)
{
	unsigned long	base;
	char			hex[16];
	int				mod;
	int				j;

	base = 16;
	j = i;
	while (i >= 0)
	{
		mod = mem % base;
		if (mod >= 0 && mod <= 9)
			hex[i] = '0' + mod;
		else if (mod >= 10 && mod <= 15)
			hex[i] = 'a' + (mod % 10);
		mem = mem / base;
		i--;
	}
	i = 0;
	while (i <= j)
	{
		write(1, &hex[i], 1);
		i++;
	}
}

void	print_chars(char *start, int last, int a_c)
{
	int		i;
	char	dot;

	dot = '.';
	i = last - (16 - a_c);
	write(1, " ", 1);
	while (i <= last)
	{
		if (start[i] < 32)
		{
			write(1, &dot, 1);
		}
		else
		{
			write(1, &start[i], 1);
		}
		i++;
	}
	write(1, "\n", 1);
}

void	check_end(int i, int s_t, int a_c, char *start)
{
	int	tmp;

	if (i == s_t)
	{
		tmp = a_c;
		while (a_c > 0)
		{
			if (a_c % 2 == 0)
			{
				write(1, " ", 1);
			}
			write(1, "  ", 2);
			a_c--;
		}
		tmp++;
		print_chars(start, i, tmp);
		return ;
	}
	if (a_c == 0)
	{
		print_chars(start, i, 1);
	}
}

int	print_hexes(int i, int a_c, char *start)
{
	if (a_c == 0)
	{
		get_hex((unsigned long)&start[i], 15);
		a_c = 16;
		write(1, ":", 1);
	}
	if (i % 2 == 0)
	{
		write(1, " ", 1);
	}
	get_hex((unsigned long)start[i], 1);
	return (a_c);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int		i;
	int		s_t;
	int		a_c;
	char	*start;

	a_c = 0;
	i = 0;
	s_t = size - 2;
	start = addr;
	while (i <= s_t)
	{
		a_c = print_hexes(i, a_c, start);
		a_c--;
		check_end(i, s_t, a_c, start);
		i++;
	}
	return (addr);
}
