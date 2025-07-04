/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 12:02:52 by sandrzej          #+#    #+#             */
/*   Updated: 2025/06/30 18:40:20 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	g_num[10];
char	g_depth;
char	g_spc;
char	g_coma;

void	print_separator(void)
{
	int	i;
	int	c;
	int	j;

	j = 10 - g_depth;
	i = 0;
	c = 0;
	while (i < g_depth)
	{
		if (g_num[i] == (j + '0'))
		{
			c++;
			j++;
		}
		else
		{
			break ;
		}
		i++;
	}
	if (c != g_depth)
	{
		write(1, &g_coma, 1);
		write(1, &g_spc, 1);
	}
}

void	print_num(void)
{
	int	i;

	i = 0;
	while (g_num[i] && i < g_depth)
	{
		write(1, &g_num[i], 1);
		i++;
	}
	print_separator();
}

void	recursive_print(int btm_limit, int up_limit, int nest)
{
	nest++;
	up_limit++;
	while (btm_limit < up_limit)
	{
		g_num[nest] = (btm_limit + '0');
		btm_limit++;
		if (nest < g_depth)
		{
			recursive_print(btm_limit, up_limit, nest);
		}
	}
	if (nest == g_depth)
	{
		print_num();
	}
}

void	ft_print_combn(int n)
{
	int	nest;
	int	btm_limit;
	int	up_limit;

	g_spc = ' ';
	g_coma = ',';
	nest = -1;
	btm_limit = 0;
	up_limit = 10 - n;
	g_depth = n;
	recursive_print(btm_limit, up_limit, nest);
}
