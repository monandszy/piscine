/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 22:04:44 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/09 11:26:47 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char**argv)
{
	char	*name;
	int		i;

	i = 0;
	name = argv[0];
	if (argc >= 0)
	{
		while (name[i])
		{
			write(1, &name[i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
