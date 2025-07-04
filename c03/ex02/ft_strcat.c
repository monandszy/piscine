/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 17:44:25 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/03 20:20:39 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	l1;
	int	l2;

	l1 = 0;
	while (dest[l1])
		l1++;
	l2 = 0;
	while (src[l2])
	{
		dest[l1 + l2] = src[l2];
		l2++;
	}
	dest[l1 + l2] = '\0';
	return (dest);
}
