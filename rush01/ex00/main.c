/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:18:39 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/06 12:43:20 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

extern int	g_top[4];
extern int	g_btm[4];
extern int	g_rig[4];
extern int	g_lft[4];

// function order after compilation
void	solve_matrix(void);
void	print_msg(void);
int		validate(char *arg);
void	assign_to_side(int pos, int arg);
// main 

// GRAVE ERROR
void	assign_to_side(int pos, int arg)
{
	int	side;
	int	index;

	pos = pos - 1;
	side = (pos / 4);
	index = (pos % 4);
	if (side == 0)
		g_top[index] = arg;
	else if (side == 1)
		g_btm[index] = arg;
	else if (side == 2)
		g_lft[index] = arg;
	else if (side == 3)
		g_rig[index] = arg;
	else
		print_msg();
}

// VALIDATION ERROR: size of input higher than 1
// VALIDATION ERROR: number higher than 4
// VALIDATION ERROR: not a number
int	validate(char *arg)
{
	if (arg[1] != '\0')
	{
		print_msg();
		return (1);
	}
	else if (arg[0] > '4' && arg[0] <= '9')
	{
		print_msg();
		return (1);
	}
	else if (!(arg[0] >= '0' && arg[0] <= '9'))
	{
		print_msg();
		return (1);
	}
	return (0);
}

// INPUT ERROR: Argument count not 16
int	main(int argc, char **argv)
{
	char	*arg;
	int		pos;

	pos = 1;
	if (argc == 17)
	{
		while (argv[pos])
		{
			arg = argv[pos];
			if (validate(arg) == 1)
				return (1);
			assign_to_side(pos, (*arg - '0'));
			pos++;
		}
		solve_matrix();
		return (0);
	}
	else
	{
		print_msg();
		return (1);
	}
}
