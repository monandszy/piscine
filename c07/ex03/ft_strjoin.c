/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:31:49 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/12 12:21:18 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

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

char	*empty(void)
{
	char	*con;

	con = (char *) malloc(2 * sizeof(char));
	con[0] = '\0';
	return (con);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		s;
	char	*con;

	if (size <= 0)
		return (empty());
	s = calc_s(size, strs);
	printf("s%d", s);
	con = (char*) malloc((s + size) * sizeof(char));
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
		i++;
		if (i != size)
			con[s] = *sep;
		s++;
	}
	return (con); 
}
