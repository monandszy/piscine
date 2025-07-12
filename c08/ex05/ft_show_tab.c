/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:36:33 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/12 14:37:56 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_stock_str.h"
#include <stdio.h>
#include <unistd.h>

struct s_stock_str	*ft_strs_to_tab(int ac, char **av);

void	loop_nb(int nb)
{
	int		i;
	int		j;
	int		cp;
	char	tmp;

	cp = nb;
	i = 0;
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	while (i > 0)
	{
		nb = cp;
		j = i;
		while (j > 1)
		{
			nb = nb / 10;
			j--;
		}
		tmp = (nb % 10) + '0';
		write(1, &tmp, 1);
		i--;
	}
}

void	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].size != 1)
	{
		loop_nb(par[i].size);
		write(1, "\n", 1);
		print_str(par[i].str);
		write(1, "\n", 1);
		print_str(par[i].copy);
		write(1, "\n", 1);
		i++;
	}
}

int	main(void)
{
	char				*av[4];
	struct s_stock_str	*out;

	av[0] = "catnip";
	av[1] = "cat2";
	av[2] = "cat3";
	av[3] = "cat4";
	out = ft_strs_to_tab(4, av);
	ft_show_tab(out);
}
