/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:09:23 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/07 22:24:56 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*arg;

	i = 1;
	while (i < argc)
	{
		arg = argv[i];
		j = 0;
		while (arg[j])
		{
			write(1, &arg[j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
