/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 13:00:38 by sandrzej          #+#    #+#             */
/*   Updated: 2025/06/30 21:17:32 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printy(char c)
{
	write(1, &c, 1);
}

void	loop_nb(int nb)
{
	int	i;
	int	j;
	int	cp;

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
		printy((nb % 10) + '0');
		i--;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		printy('-');
		loop_nb(214748364);
		printy('8');
	}
	else if (nb < 0)
	{
		printy('-');
		nb = -nb;
		loop_nb(nb);
	}
	else if (nb > 0)
	{
		loop_nb(nb);
	}
	else if (nb == 0)
	{
		printy('0');
	}
}
