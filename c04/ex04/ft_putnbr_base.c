/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:10:11 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/06 20:19:49 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	print_in_base(int nbr, int base, char *en)
{
	if (nbr > base)
	{
		// go lower to the first one which 
		print_in_base(nbr / base, base, en);
	}
	printf("[%d]", nbr);
	write(1, &en[nbr % base], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	tmp;
	int	size;

	tmp = nbr;
	size = 0;
	while (base[size])
	{
		size++;
	}
	printf("{%d, %d, %s}", nbr, size, base);
	print_in_base(nbr, size, base);
}
