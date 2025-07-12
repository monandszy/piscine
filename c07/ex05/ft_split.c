/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:59:22 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/12 12:41:33 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*g_str;
char	*g_charset;
char	**g_split;
int		g_c;
int		g_c_size;
int		g_s_size;

int	c_splitters(int i, int j, int s, int c)
{
	while (g_str[i])
	{
		if (g_str[i] != '\0' && g_charset[j] == '\0')
		{
			j = 0;
			s = 0;
			c = c + 1;
		}
		if (g_str[i] == g_charset[j] && i != 0)
			j++;
		else
		{
			j = 0;
			if (g_str[i] == g_charset[j])
				j++;
		}
		i++;
		s++;
	}
	return (c);
}

void	assign(char *start, int size)
{
	int	i;

	g_split[g_c] = (char *) malloc((size - g_c_size + 1) * sizeof(char));
	i = 0;
	while (i < (size - g_c_size))
	{
		g_split[g_c][i] = start[i];
		i++;
	}
	g_c++;
}

void	c_fill(int i, int j, int s)
{
	char	*start;

	start = &g_str[0];
	while (g_str[i])
	{
		if (g_str[i] != '\0' && g_charset[j] == '\0')
		{
			if (s > g_c_size)
				assign(start, s);
			s = 0;
			j = 0;
			start = &g_str[i];
		}
		if (g_str[i] == g_charset[j])
			j++;
		else
		{
			j = 0;
			if (g_str[i] == g_charset[j])
				j++;
		}
		s++;
		i++;
	}
}

char	**ft_split(char *str, char *charset)
{
	int	c;

	g_c_size = 0;
	g_s_size = 0;
	while (charset[g_c_size])
		g_c_size++;
	while (str[g_s_size])
		g_s_size++;
	g_str = str;
	g_charset = charset;
	c = 0;
//	if (g_c_size == 0 && g_c_size == 0)
//		return ();
	if (g_c_size == 0)
	{
		g_split = (char **) malloc((2) * sizeof(char *));
		while (str[c])
			c++;
		g_split[0] = (char *) malloc((c + 1) * sizeof(char *));
		c = 0;
		while (str[c])
		{
			g_split[0][c] = str[c];
			c++;
		}
		return (g_split);
	}
	else 
		c = c_splitters(0, 0, 0, 0);
	g_split = (char **) malloc((c + 1) * sizeof(char *));
	g_c = 0;
	c_fill(0, 0, 0);
	g_split[g_c + 1] = (char *) malloc((1) * sizeof(char *));
	g_split[g_c + 1][0] = '\0';
	return (g_split);
}
