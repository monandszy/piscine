/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:10:11 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/07 15:37:55 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	g_is_edge;

void	print_in_base(int nbr, int base, char *encoding)
{
	if (nbr >= base)
	{
		print_in_base(nbr / base, base, encoding);
	}
	write(1, &encoding[nbr % base], 1);
}

int	validate_duplication(char *base)
{
	int	i;
	int	j;

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

void	ft_putnbr_base(int nbr, char *base)
{
	int		size;
	long	num;

	num = (long)nbr;
	size = 0;
	if (validate_duplication(base) == 1)
		return ;
	while (base[size])
		size++;
	if (size < 2)
		return ;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	print_in_base(nbr, size, base);
}
