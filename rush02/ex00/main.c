/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kochniak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 14:23:37 by kochniak          #+#    #+#             */
/*   Updated: 2025/07/14 12:27:15 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "number_to_words.h"

t_dict_entry	*g_dict;
int				g_dict_size;

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (1);
	g_dict = malloc(sizeof(t_dict_entry) * MAX_DICT_SIZE);
	if (!g_dict)
		return (1);
	if (argc == 2)
		g_dict_size = load_dict(g_dict, "numbers.dict");
	else
		g_dict_size = load_dict(g_dict, argv[2]);
	if (g_dict_size == -1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	if (correct_nmb(argv[1]) == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	convert_number_to_words(argv[1], g_dict, g_dict_size);
	free_dict(g_dict, g_dict_size);
	free(g_dict);
	return (0);
}
