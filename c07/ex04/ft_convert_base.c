/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:22:05 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/12 12:15:47 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*g_encoding;
long	g_base;
char	*g_fnum;
int		g_is_min;
int		g_flag;

int		ft_atoi_base(char *str, char *base, long b);

long	validate_encoding_duplication(char *base)
{
	long	i;
	long	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		j = 0;
		if (base[i] == '-' || base[i] == '+')
			return (1);
		while (base[j])
		{
			if (j != i && base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// recursively converts the number to the rquired base 
// and puts it in the global g_fnum string
int	print_in_base(long nbr, int size)
{
	int	i;

	size++;
	if (nbr >= g_base)
	{
		i = print_in_base(nbr / g_base, size);
		i++;
	}
	else
	{
		i = 0;
		g_fnum = (char *) malloc((size + g_is_min) * sizeof(char));
		if (g_is_min == 1)
		{
			g_fnum[0] = '-';
			i++;
		}
		g_fnum[i] = g_encoding[nbr % g_base];
		return (i);
	}
	g_fnum[i] = g_encoding[nbr % g_base];
	return (i);
}

// validates the encoding, size, and sign
char	*ft_putnbr_base(long nbr, char *base)
{
	long	size;
	long	num;

	g_is_min = 0;
	g_encoding = base;
	num = (long)nbr;
	size = 0;
	if (validate_encoding_duplication(g_encoding) == 1)
		return (NULL);
	while (g_encoding[size])
		size++;
	if (size < 2)
		return (NULL);
	g_base = size;
	if (num < 0)
	{
		num = -num;
		g_is_min = 1;
	}
	print_in_base(num, 0);
	return (g_fnum);
}

// Uses ft_atoi_base from c04 ex05, converts the number to decimal
// Then changes the number into the base with c04 ex04 ft_putnbr_base
char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	num;
	int		size;

	g_flag = 0;
	size = 0;
	while (base_from[size])
		size++;
	if (size < 2)
		return (NULL);
	if (validate_encoding_duplication(base_from) == 1)
		return (NULL);
	num = ft_atoi_base(nbr, base_from, size);
	if (g_flag == 0)
		return (ft_putnbr_base(num, base_to));
	else
		return (NULL);
}
