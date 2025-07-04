/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:39:57 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/03 12:41:41 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	tmp;
	int	prev;
	int	next;

	i = size;
	prev = 0;
	next = 1;
	while (i > 0)
	{
		prev = 0;
		next = 1;
		while (next < size)
		{
			if (tab[prev] > tab[next])
			{
				tmp = tab[prev];
				tab[prev] = tab[next];
				tab[next] = tmp;
			}
			prev++;
			next++;
		}
		i--;
	}
}
