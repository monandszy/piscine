/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:07:43 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/01 16:14:47 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// I assume zero will not be passed as an argument
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	r1;
	int	r2;

	r1 = *a / *b;
	r2 = *a % *b;
	*a = r1;
	*b = r2;
}
