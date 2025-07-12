/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 11:31:49 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/12 16:41:17 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**g_strs;
char	*g_sep;
int		g_size;

char	*iterate(char *con, int i, int j, int s)
{
	while (i < g_size)
	{
		j = 0;
		while (g_strs[i][j])
		{
			con[s] = g_strs[i][j];
			j++;
			s++;
		}
		j = 0;
		while (g_sep[j] && i != g_size - 1)
		{
			con[s] = g_sep[j];
			s++;
			j++;
		}
		i++;
	}
	con[s] = '\0';
	return (con);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*allocate(void)
{
	int		i;
	int		sum;
	char	*con;

	sum = 0;
	i = 0;
	if (g_size <= 0)
		sum = 1;
	else
	{
		while (i < g_size)
		{
			sum += ft_strlen(g_strs[i]);
			i++;
		}
		sum += ft_strlen(g_sep) * g_size - 1;
	}
	con = (char *) malloc(sum * sizeof(char));
	if (con == NULL)
		return (0);
	return (con);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*con;

	g_strs = strs;
	g_sep = sep;
	g_size = size;
	con = allocate();
	return (iterate(con, 0, 0, 0));
}
