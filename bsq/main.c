/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 00:31:37 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/15 14:18:28 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char	**g_matrix;

int	process_file(int *i_col_size, int *i_row_size, int fd)
{
	char	tmp[1];
	int		bytes_read;
	int		total_size;
	int		row_size;
	int		tmp_row_size;


	bytes_read = 0;
	total_size = 0;
	row_size = 0;
	tmp_row_size = 0;
	while ((bytes_read = read(fd, tmp, sizeof(tmp))) > 0)
	{
		row_size++;
		if (row_size < 0)
			return (1);
		if (*tmp != '.' && *tmp != 'o' && *tmp != '\n')
			return (1);
		if (*tmp == '\n')
		{
			tmp_row_size = row_size;
			if (row_size != tmp_row_size)
				return (1);
			total_size += row_size;
			row_size = 0;
			if (total_size < 0)
				return (1);
		}
	}
	if (tmp_row_size <= 0)
		return (1);
	*i_row_size = tmp_row_size;
	*i_col_size = total_size / tmp_row_size;
	return (0);
}

int	to_matrix(int col_size, int row_size, int fd)
{
	int		row_count;
	char	buffer[row_size];
	int		bytes_read;
	int		i;
	int		j;

//	buffer = (char *) malloc(sizeof(char) * row_size);
	g_matrix = (char **) malloc(sizeof(char *) * col_size);
	i = 0;
	while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
	{
		g_matrix[i] = (char *) malloc(sizeof(char) * row_size);
		j = 0;
		while (buffer[j])
		{
			g_matrix[i][j] = buffer[j];
			j++;
		}
		g_matrix[i][row_size - 1] = '\0';
		i++;
	}
	return (0);
}

int	calculate_size(int col_size, int row_size, int x, int y)
{
	int	size;
	int	a_y;
	int	a_x;
	int	tmp_y;
	int	tmp_x;
	int	tmp_s;

	size = 0;
	tmp_x = x;
	tmp_y = y;
	while (x < col_size && y < row_size)
	{
		a_x = tmp_x;
		a_y = tmp_y;
		tmp_s = size + 1;
		while (tmp_s > 0)
		{
			if (g_matrix[x][a_y] == 'o' || g_matrix[a_x][y] == 'o')
				return (size);
			a_y++;
			a_x++;
			tmp_s--;
		}
		x++;
		y++;
		size++;
	}
	return (size);
}

int	find_max(int col_size, int row_size, int *m_x, int *m_y)
{
	int	x;
	int	y;
	int	size;
	int	max;

	x = 0;
	max = 0;
	while (x < col_size)
	{
		y = 0;
		while (y < row_size)
		{
			if (g_matrix[x][y] != 'o')
			{
				size = calculate_size(col_size, row_size, x, y);
				if (size > max)
				{
					*m_x = x;
					*m_y = y;
					max = size;
				}
			}
			y++;
		}
		x++;
	}
	return (max);
}

void fill_max(int m_x, int m_y, int m_size)
{
/*	int	size;
	int	x;
	int	y;
	int	a_y;
	int	a_x;
	int	tmp_s;
*/
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			g_matrix[i + x][j + y] = '!';
			j++;
		}
		i++;
	}
/*	size = 0;
	x = m_x;
	y = m_y;
	while (x < (m_x + m_size) && y < (m_y + m_size))
	{
		a_x = m_x;
		a_y = m_y;
		tmp_s = size + 1;
		while (tmp_s > 0)
		{
			g_matrix[x][a_y] = '!';
			g_matrix[a_x][y] = '!';
			a_y++;
			a_x++;
			tmp_s--;
		}
		x++;
		y++;
		size++;
	} */
}

int	write_max(int col_size, int row_size)
{
	int	m_x;
	int	m_y;
	int	m_size;

	m_size = find_max(col_size, row_size, &m_x, &m_y);

	fill_max(m_x, m_y, m_size);

	// change the logic to actually write into the file.
	printf("[%d]", m_size);
	if (m_size == 0)
		return (1);
	return (0);
}

void	print_matrix(int row_size)
{
	int	i;
	int j;

	i = 0;
	while (g_matrix[i])
	{
		j = 0;
		while(g_matrix[i][j])
		{
			write(1, &g_matrix[i][j], 1);
			write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
/* int g_size_x;
int g_size_y;

int calc_current_height(int x, int y)
{
	int height;

	height = 0;
	x--;
	while (x >= 0 && g_matrix[x][y] != 'o')
	{
		height++;
		x--;
	}
	return (height);
}

void	idea(int o_x, int o_y, int max_y_height)
{
	int	x;
	int	y;
	int y_height;

	x = o_x;
	y = o_y;
	// remember to check the bottom row as an obstacle possibilities
	while (x < g_size_x - 10)
	{
		y = 0;
		while (y < g_size_y)
		{
			if (g_matrix[x][y] == 'o')
			{
				y_height = calc_current_height(x, y);
				if (y_height > max_y_height)
				{
					printf("{x:%d, y:%d, h:%d}\n", x, y, y_height);
					// breakpoint for the end of the matrix?
					idea(x, y, y_height);
					return ;
					// nest into the next y with the new y
					// after break, find the x that match the y
				}
			}
			y++;
		}
		x++;
	}
	printf("[%d, %d, %d]", o_x, o_y, max_y_height);
} */

/*			g_size_y = col_size;
			g_size_x = row_size; */
//			idea(0, 0, 0);

int	main(int argc, char **argv)
{
	int		fd;
	int		col_size;
	int		row_size;
	char	*filename;

	if (argc > 1)
	{
		argv++;
		while (*argv)
		{
			filename = *argv;
			fd = open(filename, O_RDONLY);
			if (fd == -1 || process_file(&col_size, &row_size, fd) == 1)
				return (1);
			close(fd);
			fd = open(filename, O_RDONLY);
			if (fd == -1 || col_size <= 0 || row_size <= 0
				|| to_matrix(col_size, row_size, fd) == 1)
				return (1);
			close(fd);
			fd = open(filename, O_WDONLY | O_CREAT | O_TRUNC, 0644);
			if (fd == -1 || fill_max(col_size, row_size) == 1)
				return (1);
			print_matrix(row_size);
			argv++;
		}
	}
}
