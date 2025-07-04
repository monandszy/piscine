/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:09:54 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/03 19:09:55 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// termination not guaranteed if not included in the src
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int	tmp_n;
	int	i;

	i = 0;
	tmp_n = n;
	while (i < tmp_n)
	{
		dest[i] = src[i];
		i++;
	}

	return (dest);
}
