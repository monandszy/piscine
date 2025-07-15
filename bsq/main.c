/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 00:31:37 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/15 15:03:29 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char	**g_matrix;

int calculate_size(int col_size, int row_size, int x, int y);
int find_max(int col_size, int row_size, int *m_x, int *m_y);
void fill_max(int x, int y, int size);
int write_max(int col_size, int row_size, int fd);
void    print_matrix(int row_size);

int	process_file(int *i_col_size, int *i_row_size, int fd)
{
	char	tmp[1];
	int		bytes_read;
	int		total_size;
	int		row_size;
	int		tmp_row_size;

	bytes_read = read(fd, tmp, sizeof(tmp));
	total_size = 0;
	row_size = 0;
	tmp_row_size = 0;
	while (bytes_read > 0)
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
		bytes_read = read(fd, tmp, sizeof(tmp));
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

int process_arg(char *filename)
{
	int		fd;
	int		col_size;
	int		row_size;

	fd = open(filename, O_RDONLY);
	if (fd == -1 || process_file(&col_size, &row_size, fd) == 1)
		return (1);
	close(fd);
	fd = open(filename, O_RDONLY);
	if (fd == -1 || col_size <= 0 || row_size <= 0
		|| to_matrix(col_size, row_size, fd) == 1)
		return (1);
	close(fd);
	fd = open(filename, O_WRONLY | O_TRUNC);
	if (fd == -1 || write_max(col_size, row_size, fd) == 1)
		return (1);
	close(fd);
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
