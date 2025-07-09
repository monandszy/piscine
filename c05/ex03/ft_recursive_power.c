/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:26:18 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/08 17:40:38 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	mult;

	mult = nb;
	if (power > 1)
	{
		power--;
		nb = ft_recursive_power(nb, power);
		return (nb * mult);
	}
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * mult);
}
