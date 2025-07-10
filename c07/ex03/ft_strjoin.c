/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:31:49 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/10 12:37:35 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	calc_s(int size, char **strs)
{
	int	i;
	int	j;
	int	s;

	s = 0;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			s++;
			j++;
		}
		i++;
	}
	return (s);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		s;
	char	*con;

	if (size <= 0)
		return ("");
	s = calc_s(size, strs);
	con = malloc((s + size) * sizeof(char));
	i = 0;
	s = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			con[s] = strs[i][j];
			s++;
			j++;
		}
		con[s] = *sep;
		s++;
		i++;
	}
	return (con);
}
