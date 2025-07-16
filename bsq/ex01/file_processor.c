#include "fts.h"

char **g_matrix;

int	process_file(int *final_col_size, int *final_row_size, int fd)
{
	char		tmp;
	int		bytes_read;
	int		total_size;
	int		row_size;
	int		tmp_row_size;

	bytes_read = read(fd, &tmp, sizeof(tmp));
	total_size = 0;
	row_size = 0;
	tmp_row_size = 0;
	while (bytes_read > 0)
	{
		row_size++;
		if (row_size < 0)
			return (1);
		if (tmp != '.' && tmp != 'o' && tmp != '\n')
			return (1);
		if (tmp == '\n')
		{
			tmp_row_size = row_size;
			if (row_size != tmp_row_size)
				return (1);
			total_size += row_size;
			row_size = 0;
			if (total_size < 0)
				return (1);
		}
		bytes_read = read(fd, &tmp, sizeof(tmp));
	}
	if (tmp_row_size <= 0)
		return (1);
	*final_row_size = tmp_row_size;
	*final_col_size = total_size / tmp_row_size;
	return (0);
}

int	to_matrix(int col_size, int row_size, int fd)
{
	char		buffer[row_size];
	int		bytes_read;
	int		i;
	int		j;

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

int	process_arg(char *filename)
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
	if (fd == -1 || handle_max(col_size, row_size) == 1)
		return (1);
	return (print_matrix(row_size, col_size), 0);
}
