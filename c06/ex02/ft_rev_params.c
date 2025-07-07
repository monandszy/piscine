/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:20:44 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/07 22:23:42 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*arg;

	i = argc - 1;
	while (i > 0)
	{
		arg = argv[i];
		j = 0;
		while (arg[j])
		{
			write(1, &arg[j], 1);
			j++;
		}
		write(1, "\n", 1);
		i--;
	}
	return (0);
}
