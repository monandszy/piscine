/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:21:44 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/10 16:12:30 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*g_en;
char		*g_str;
long		g_end;
long		g_num;
long		g_zero_only;
extern int	g_flag;

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

long	terminate_invalid_str(int i, int j)
{
	long	flag;

	while (*g_str)
	{
		if (!(*g_str == g_en[0]))
			break ;
		g_str++;
		g_zero_only = 1;
	}
	while (g_str[i])
	{
		j = 0;
		flag = 0;
		while (g_en[j])
		{
			if (g_str[i] == g_en[j])
				flag = 1;
			j++;
		}
		if (flag == 0)
			return (i);
		i++;
	}
	return (i);
}

long	ft_atoi_init(long b)
{
	long	m_c;

	m_c = 0;
	while (*g_str)
	{
		if (*g_str == ' ')
			;
		else if (*g_str == '-')
			m_c++;
		else if (*g_str != '+')
			break ;
		g_str++;
	}
	g_end = terminate_invalid_str(0, 0) - 1;
	if (*g_str == g_str[g_end + 1])
	{
		if (!(g_zero_only == 1))
			g_flag = 1;
		return (0);
	}
	g_num = convert(g_end, b);
	if (m_c % 2 == 1 && g_num != 0)
		g_num = -g_num;
	return (g_num);
}

long	ft_atoi_base(char *str, char *base, long b)
{
	g_num = 0;
	g_en = base;
	g_str = str;
	g_zero_only = 0;
	return (ft_atoi_init(b));
}
