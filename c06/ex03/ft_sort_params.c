/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:40:28 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/07 23:02:47 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (1 == 1)
	{
		if (s1[i] == '\0' && s2[i] == '\0')
			return (s1);
		else if (s1[i] < s2[i])
			return (s1);
		else if (s1[i] > s2[i])
			return (s2);
		i++;
	}
}

// fills already found with highest existing
void	print(char *low)
{
	int	i;

	i = 0;
	while (low[i])
	{
		write(1, &low[i], 1);
		low[i] = 127;
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	int		i;
	int		c;
	char	*low;
	char	*cmp;

	c = 1;
	while (c < argc)
	{
		low = argv[1];
		i = 2;
		while (i < argc)
		{
			cmp = argv[i];
			low = ft_strcmp(low, cmp);
			i++;
		}
		print(low);
		c++;
	}
}
