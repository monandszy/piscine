/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:29:20 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/12 14:41:10 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
//#include <stdio.h>
//#include "../ft_stock_str.h"

int	ft_strlcpy(char *dest, char *src, int size)
{
	int	l1;
	int	l2;

	l1 = 0;
	while (src[l1] != '\0')
		l1++;
	if (size == 0)
		return (l1);
	l2 = 0;
	while (l2 < (size - 1) && src[l2] != '\0')
	{
		dest[l2] = src[l2];
		l2++;
	}
	dest[l2] = '\0';
	return (l2);
}

t_stock_str	transfer(int size, char *str)
{
	t_stock_str	*obj;
	char		*dest;

	obj = (t_stock_str *) malloc(sizeof(t_stock_str));
	obj->size = size;
	obj->str = str;
	dest = (char *) malloc(size * sizeof(char));
	ft_strlcpy(dest, str, size);
	obj->copy = dest;
	return (*obj);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*arr;
	int			size;
	int			tmp;

	tmp = ac;
	arr = (t_stock_str *) malloc((ac + 1) * sizeof(t_stock_str));
	while (ac > 0)
	{
		size = 0;
		while (av[ac - 1][size])
			size++;
		size++;
		arr[ac - 1] = transfer(size, av[ac - 1]);
		ac--;
	}
	arr[tmp] = transfer(1, "\0");
	return (arr);
}
