/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:28:12 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/01 16:39:06 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int *tab, int size)
{
	int	f;
	int	l;
	int	tmp;

	f = 0;
	l = size - 1;
	while (f <= l)
	{
		tmp = tab[f];
		tab[f] = tab[l];
		tab[l] = tmp;
		f++;
		l--;
	}
}
