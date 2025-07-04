/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 14:20:40 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/03 19:56:52 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	pri(char c)
{
	write(1, &c, 1);
}

// I ignored conversion of higher than 1F (the highest not printable)
void	to_hex(char c)
{
	int	base;
	int	rem;

	base = c / 16;
	rem = c % 16;
	pri('\\');
	if (base < 10)
		pri(base + '0');
	if (rem >= 10 && rem <= 15)
		pri('a' + (rem % 10));
	else
		pri(rem + '0');
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 0 && str[i] <= 31)
		{
			to_hex(str[i]);
		}
		else
		{
			pri(str[i]);
		}
		i++;
	}
}
