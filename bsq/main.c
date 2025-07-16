/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 00:31:37 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/15 16:45:44 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

const int g_x_size;
const int g_y_size;

int		calculate_size(int col_size, int row_size, int x, int y);
int		find_max(int col_size, int row_size, int *m_x, int *m_y);
void	fill_max(int x, int y, int size);
int		write_max(int col_size, int row_size, int fd);
void	print_imatrix(int row_size);

void process_encoding(int bytes_read)
{
	char tmp[1];

	while (bytes_read > 0)
	{
		if (tmp >= '0' && tmp <= '9')
		{
			bytes_read = read(fd, tmp, sizeof(tmp));
			continue;
		}
	}
	while (tmp >= '0' && tmp <= '9')
	{
	}
	if (!(bytes_read > 0))
		return(1);
	while ()
	bytes_read = read(fd, &tmp, sizeof(tmp));
		if (bytes_
}

int	process_file(int fd)
{
	char	tmp[1];
	int		bytes_read;
	int		file_size;
	int		x_size;
	int		tmp_x_size;

	bytes_read = read(fd, tmp, sizeof(tmp));
	file_size = 0;
	x_size = 0;
	tmp_x_size = 0;
	process_encoding(bytes_read);
	while (bytes_read > 0)
	{
		x_size++;
		if (*tmp != '.' && *tmp != 'o' && *tmp != '\n')
			return (1);
		if (*tmp == '\n')
		{
			*tmp_x_size = x_size;
			if (x_size != *tmp_x_size)
				return (1);
			file_size += x_size;
			x_size = 0;
			if (file_size < 0)
				return (1);
		}
		bytes_read = read(fd, tmp, sizeof(tmp));
	}
	if (tmp_x_size <= 0)
		return (1);
	g_x_size = tmp_x_size;
	g_y_size = file_size / tmp_x_size;
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

int process_arg(char *filename)
{
	int		fd;
	int		col_size;
	int		row_size;
	int		m_x;
	int		m_y;

	fd = open(filename, O_RDONLY);
	if (fd == -1 || process_file(&col_size, &row_size, fd) == 1)
		return (1);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1 || col_size <= 0 || row_size <= 0
		|| to_matrix(col_size, row_size, fd) == 1)
		return (1);
	close(fd);

    fill_max(m_x, m_y, find_max(col_size, row_size, &m_x, &m_y)); 
	print_matrix(row_size);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		argv++;
		while (*argv)
		{
			if (process_arg(*argv) == 1)
			{
//				error();
				return (1);
			}
			argv++;
		}
		return(0);
	}
	return(1);
}
