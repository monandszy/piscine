/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wszlaga <wszlaga@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:14:52 by wszlaga           #+#    #+#             */
/*   Updated: 2025/07/06 11:59:19 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

extern int	g_rush_version;
/* int	g_x;
int	g_y;
char	g_m1[];
char	g_m2[]; */

void	rush(int x, int y);
/* void	rush00(int x, int y);
void	rush01(int x, int y);
void	rush02(int x, int y);
void	rush03(int x, int y);
void	rush04(int x, int y); */
void	ft_putchar(char c);
void	print_helper(char *message);
/* void	choose_rush_version(void);*/

void	print_helper(char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		ft_putchar(message[i]);
		i++;
	}
}

int	extract_int(char *arr)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] >= 48 && arr[i] <= 57)
		{
			num = num * 10 + (arr[i] - 48);
		}
		i++;
	}
	return (num);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (&*argv[1] && &*argv[2] && &*argv[3])
	{
		x = extract_int(argv[2]);
		y = extract_int(argv[3]);
		g_rush_version = *argv[1] - '0';
		if (g_rush_version < 5)
		{
			rush(x, y);
		}
		else
		{
			print_helper("Invalid number of {rush_version},");
			print_helper(" please input a number from 0 to 4");
		}
	}
	else
	{
		print_helper("Incorrect input. ./{output_file} {rush_version} {x} {y}");
	}
	return (0);
}
