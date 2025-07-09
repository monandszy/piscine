/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 17:11:44 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/08 17:19:41 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	int	i;

	i = nb;
	if (nb > 1)
	{
		nb--;
		nb = ft_recursive_factorial(nb);
		return (nb * i);
	}
	return (nb);
}
