/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:31:49 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/12 12:58:14 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**g_strs;
char	*g_sep;
int		g_size;

int	calc_s(void)
{
	int	i;
	int	j;
	int	s;

	s = 0;
	i = 0;
	while (i < g_size)
	{
		j = 0;
		while (g_strs[i][j])
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

char	*iterate(char *con, int i, int j, int s)
{
	while (i < g_size)
	{
		j = 0;
		while (g_strs[i][j])
		{
			con[s] = g_strs[i][j];
			s++;
			j++;
		}
		i++;
		j = 0;
		if (i != g_size)
		{
			while (g_sep[j])
			{
				con[s] = g_sep[j];
				j++;
				s++;
			}
		}
	}
	return (con);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		s;
	int		ss;
	char	*con;

	g_strs = strs;
	g_sep = sep;
	g_size = size;
	ss = 0;
	while (g_sep[ss])
		ss++;
	if (g_size <= 0)
		return (empty());
	s = calc_s();
	con = (char *) malloc((s + g_size + (ss * g_size)) * sizeof(char));
	return (iterate(con, 0, 0, 0));
}
