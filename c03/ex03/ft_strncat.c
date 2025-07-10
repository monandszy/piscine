/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:59:55 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/10 11:31:38 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	l1;
	unsigned int	l2;

	l1 = 0;
	while (dest[l1])
		l1++;
	l2 = 0;
	while (src[l2] && l2 < nb)
	{
		dest[l1 + l2] = src[l2];
		l2++;
	}
	dest[l1 + l2] = '\0';
	return (dest);
}
