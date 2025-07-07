/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:15:55 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/07 19:43:13 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*g_en;
char	*g_str;
long	g_end;
long	g_num;
long	g_i;
long	g_j;

// #include <stdio.h>

long	validate_encoding_duplication(void)
{
	long	i;
	long	j;

	i = 0;
	j = 0;
	while (g_en[i])
	{
		j = 0;
		if (g_en[i] == '-' || g_en[i] == '+')
			return (1);
		while (g_en[j])
		{
			if (j != i && g_en[i] == g_en[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

//	prlongf("[b:%d, j:%d, i:%d, p:%d]", power, j, i, prev);
//prlongf("(%d, %c)", (g_end - i), g_str[g_end - i]);
long	convert(long i, long b)
{
	long	prev;
	long	j;
	long	power;

	if (i > 0)
		prev = convert(i - 1, b);
	else
		prev = 0;
	j = 0;
	while (g_en[j])
	{
		if (g_str[g_end - i] == g_en[j])
			break ;
		j++;
	}
	if (i == 0)
		b = 1;
	power = 1;
	while (i > 0)
	{
		power = power * b;
		i--;
	}
	prev = prev + (power * j);
	return (prev);
}
/*	i = 0;
	while (i < end)
	{
		write(1, &str[i], 1);
		i++;
	} */

long	terminate_invalid_str(void)
{
	long	flag;

	while (*g_str)
	{
		if (!(*g_str == g_en[0]))
			break ;
		g_str++;
	}
	g_i = 0;
	while (g_str[g_i])
	{
		g_j = 0;
		flag = 0;
		while (g_en[g_j])
		{
			if (g_str[g_i] == g_en[g_j])
				flag = 1;
			g_j++;
		}
		if (flag == 0)
			return (g_i);
		g_i++;
	}
	return (g_i);
}

long	ft_atoi_to_base(long b)
{
	long	m_c;

	m_c = 0;
	while (*g_str)
	{
		if (*g_str == ' ')
		{
		}
		else if (*g_str == '-')
			m_c++;
		else if (*g_str != '+')
			break ;
		g_str++;
	}
	g_end = terminate_invalid_str() - 1;
	if (*g_str == g_str[g_end + 1])
		return (0);
	g_num = convert(g_end, b);
	if (m_c % 2 == 1 && g_num != 0)
		g_num = -g_num;
	return (g_num);
}

int	ft_atoi_base(char *str, char *base)
{
	long	size;

	g_num = 0;
	g_en = base;
	g_str = str;
	size = 0;
	if (validate_encoding_duplication() == 1)
		return (0);
	while (base[size])
		size++;
	if (size < 2)
		return (0);
	return ((int)ft_atoi_to_base(size));
}
