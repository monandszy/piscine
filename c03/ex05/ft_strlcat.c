/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:53:11 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/03 20:33:27 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	l1;
	unsigned int	l2;

	l1 = 0;
	while (dest[l1])
		l1++;
	l2 = 0;
	while ((l2 + l1) < (size - 1))
	{
		if (src[l2] == '\0')
			break ;
		dest[l1 + l2] = src[l2];
		l2++;
	}
	dest[l1 + l2] = '\0';
	return (l1 + l2);
}
