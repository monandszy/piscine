/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 11:27:09 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/03 18:57:05 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	prev;
	int	i;

	i = 0;
	prev = ' ';
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] + 32;
		}
		if (!(prev >= 'a' && prev <= 'z') && !(prev >= 'A' && prev <= 'Z'))
		{
			if (!(prev >= '0' && prev <= '9'))
			{
				if (str[i] >= 'a' && str[i] <= 'z')
				{
					str[i] = str[i] - 32;
				}
			}
		}
		i++;
		prev = str[i - 1];
	}
	return (str);
}
