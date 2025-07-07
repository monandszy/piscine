/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:53:11 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/07 20:10:43 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	l1;
	unsigned int	l2;
	unsigned int	i;

	l1 = 0;
	l2 = 0;
	while (dest[l1])
		l1++;
	while (src[l2])
		l2++;
	i = 0;
	if (size == 0 || l1 == 0)
		return(l1 + l2);
	while ((l1 + i) < (size - 1))
	{
		if (src[i] == '\0')
			break ;
		dest[l1 + i] = src[i];
		i++;
	}
	dest[l1 + i] = '\0';
	return (l1 + l2);
}
