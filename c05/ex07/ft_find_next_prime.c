/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 11:40:28 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/09 11:46:25 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime_ex07(int nb)
{
	int	i;

	if (nb < 2)
		return (0);
	i = 2;
	while (i < ((nb / 2) + 1))
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb <= 1 || nb == 2)
		return (2);
	if (nb % 2 == 0)
		nb++;
	while (ft_is_prime_ex07(nb) == 0)
	{
		nb = nb + 2;
	}
	return (nb);
}
