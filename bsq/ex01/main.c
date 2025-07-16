/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 00:31:37 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/16 16:55:28 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fts.h"

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		while (*(++argv))
		{
			if (process_arg(*argv) == 1)
			{
//				error(); Should print error message for each failed file given
//					Should continue until we run out of files to process
			}
		}
	}
	return(0);
}
