/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 12:19:09 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/07 20:07:37 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

// guarantees string termination.
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	l1;
	unsigned int	l2;

	l1 = 0;
	while (src[l1] != '\0')
		l1++;
	if (size == 0)
		return (l1);
	l2 = 0;
	while (l2 < (size - 1) && src[l2] != '\0')
	{
		dest[l2] = src[l2];
		l2++;
	}
	dest[l2] = '\0';
	return (l2);
}
