/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:18:39 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/07 18:35:26 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

extern int	g_top[4];
extern int	g_btm[4];
extern int	g_rig[4];
extern int	g_lft[4];

// function order after compilation
// void	print_intarr(int *arr);
void	solve_matrix(void);
void	print_msg(void);
int		validate(char arg, char spc, int pos);
void	assign_to_side(int pos, int arg);
// main 

// GRAVE ERROR
void	assign_to_side(int pos, int arg)
{
	int	side;
	int	index;

	pos = (pos / 2) + (pos % 2);
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
		write(1, "GRAVE", 5);
}

// VALIDATION ERROR: Input size higher than 32
// VALIDATION ERROR: number separator not space or multiline argument
// VALIDATION ERROR: size of input higher than 1
// VALIDATION ERROR: number higher than 4
// VALIDATION ERROR: not a number
int	validate(char arg, char spc, int pos)
{
	if (spc != ' ' && pos < 30)
	{
		return (1);
	}
	else if (arg > '4' && arg <= '9')
	{
		return (1);
	}
	return (0);
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == ' '))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	iterate_positions(char *args)
{
	int	pos;

	pos = 0;
	while (pos < 32)
	{
		if (validate(args[pos], args[pos + 1], pos) == 1)
		{
			print_msg();
			return (1);
		}
		assign_to_side(pos, (args[pos] - '0'));
		pos = pos + 2;
	}
	solve_matrix();
	return (0);
}

// INPUT ERROR: Argument count not 16
// 0-30 pos, 16 num 15 spc
// if args[pos_c], and pos_c = 30 (last) pos_c will be 31
int	main(int argc, char **argv)
{
	char	*args;
	int		pos_c;

	if (argc == 2)
	{
		args = argv[1];
		pos_c = 0;
		while (args[pos_c])
			pos_c++;
		if (pos_c >= 32 || ft_str_is_numeric(args) == 1)
		{
			print_msg();
			return (1);
		}
		iterate_positions(args);
	}
	else
	{
		print_msg();
		return (1);
	}
}
