/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 16:49:19 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/09 14:56:10 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	f;

	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	f = nb;
	i = (nb - 1);
	while (i > 0)
	{
		f = f * i;
		i--;
	}
	return (f);
}
