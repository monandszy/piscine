/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 22:30:00 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/07 19:28:05 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	convert_atoi(int m_c, int i, char *arr)
{
	int		num;

	num = 0;
	while (arr[i])
	{
		if (!(arr[i] == '0'))
			break ;
		i++;
	}
	while (arr[i])
	{
		if (arr[i] >= '0' && arr[i] <= '9')
			num = num * 10 + (arr[i] - 48);
		else
			break ;
		i++;
	}
	if (m_c % 2 == 1 && num != 0)
		num = -num;
	return (num);
}

int	ft_atoi(char *str)
{
	int	i;
	int	m_c;

	i = 0;
	m_c = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
		}
		else if (str[i] == '-')
			m_c++;
		else if (str[i] >= '0' && str[i] <= '9')
			return (convert_atoi(m_c, i, str));
		else if (str[i] != '+')
			break ;
		i++;
	}
	return (0);
}
