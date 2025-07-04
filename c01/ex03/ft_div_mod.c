/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:57:25 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/01 16:07:21 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// I assume zero will not be passed as a parameter.
void	ft_div_mod(int a, int b, int *div, int *mod)
{
	int	r1;
	int	r2;

	r1 = a / b;
	r2 = a % b;
	*div = r1;
	*mod = r2;
}
