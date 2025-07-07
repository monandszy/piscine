/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 21:15:55 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/07 15:25:18 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*g_en;
char	*g_str;
int		g_end;
int		g_num;

int	validate_encoding_duplication(void)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (g_en[i])
	{
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

//	printf("[b:%d, j:%d, i:%d, p:%d]", power, j, i, prev);
//  printf("(%d, %c)", (g_end - i), g_str[g_end - i]);
int	convert(int i, int b)
{
	int	prev;
	int	j;
	int	power;

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
	while (i > 1)
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

int	terminate_invalid_str(void)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
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
		{
			return (i);
		}
		i++;
	}
	return (i);
}

int	ft_atoi_to_base(int b)
{
	int		m_c;

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
	while (*g_str)
	{
		if (!(*g_str == g_en[0]))
			break ;
		g_str++;
	}
	g_end = terminate_invalid_str() - 1;
	g_num = convert(g_end, b);
	if (m_c % 2 == 1)
		g_num = -g_num;
	return (g_num);
}

int	ft_atoi_base(char *str, char *base)
{
	int	size;

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
	return (ft_atoi_to_base(size));
}
