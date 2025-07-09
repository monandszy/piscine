/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:19:52 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/09 14:57:52 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	mult;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	mult = nb;
	while (power > 1)
	{
		nb = nb * mult;
		power--;
	}
	return (nb);
}
