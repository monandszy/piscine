/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:18:28 by wszlaga           #+#    #+#             */
/*   Updated: 2025/07/01 10:25:27 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	print_corner(int x, int y, char c[]);
void	print_line(int x, int y, char c[]);
void	rush_xx(int x, int y, char c[]);
void	rush(int x, int y);

// x start
// y start
int	g_rush_version;
int	g_x_inital;
int	g_y_initial;

void	rush(int x, int y)
{
	if (g_rush_version == 0)
	{
		rush_xx(x, y, "oooo-|");
	}
	else if (g_rush_version == 1)
	{
		rush_xx(x, y, "/\\\\/**");
	}
	else if (g_rush_version == 2)
	{
		rush_xx(x, y, "AACCBB");
	}
	else if (g_rush_version == 3)
	{
		rush_xx(x, y, "ACACBB");
	}
	else if (g_rush_version == 4)
	{
		rush_xx(x, y, "ACCABB");
	}
}
// x is start and y is start, (left top corner)
// x is end, y is start, (right top corner)
// x is start, y is end, (left bottom corner)	
// x is end, y is end, (right bottom corner)
// x between start and end, and, y start or end, (horizontal lines)
// x start or end, and, y between start and end (vertical lines)
// y is not at start or end, and, x is between end and start, (spaces)

void	print_corner(int x, int y, char c[])
{
	if (x == g_x_inital && y == g_y_initial)
	{
		ft_putchar(c[0]);
	}
	else if (x == 1 && y == g_y_initial)
	{
		ft_putchar(c[1]);
	}
	else if (x == g_x_inital && y == 1)
	{
		ft_putchar(c[2]);
	}
	else if (x == 1 && y == 1)
	{
		ft_putchar(c[3]);
	}
}

void	print_line(int x, int y, char c[])
{
	if ((x > 1 && x < g_x_inital) && (y == g_y_initial || y == 1))
	{
		ft_putchar(c[4]);
	}
	else if ((x == g_x_inital || x == 1) && (y > 1 && y < g_y_initial))
	{
		ft_putchar(c[5]);
	}
	else if ((x > 1 && x < g_x_inital) && (y != g_y_initial && y != 1))
	{
		ft_putchar (' ');
	}
}

void	rush_xx(int x, int y, char c[])
{
	g_x_inital = x;
	g_y_initial = y;
	while (y > 0)
	{
		while (x > 0)
		{
			print_corner(x, y, c);
			print_line(x, y, c);
			x--;
		}
		x = g_x_inital;
		ft_putchar('\n');
		y--;
	}
}
