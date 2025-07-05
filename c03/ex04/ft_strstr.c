/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 18:54:18 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/05 11:46:48 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*loop(int i, int j, char *str, char *to_find)
{
	char	*s;

	while (str[i] && to_find[0])
	{
		if (str[i] == to_find[j])
		{
			if (j == 0)
				s = &str[i];
			j++;
			if (!(to_find[j]))
				return (s);
		}
		else if (str[i] != to_find[j])
		{
			j = 0;
			if (str[i] == to_find[j])
			{
				s = &str[i];
				j++;
			}
		}
		i++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	if (!(to_find[0]))
		return (str);
	i = 0;
	j = 0;
	return (loop(i, j, str, to_find));
}
