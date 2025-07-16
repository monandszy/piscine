#ifndef FTS_H
# define FTS_H

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int	calculate_size(int col_size, int row_size, int x, int y);
int	find_max(int col_size, int row_size, int *m_x, int *m_y);
void	fill_max(int x, int y, int size);
int	handle_max(int col_size, int row_size);
void	print_matrix(int row_size, int col_size);
int	process_file(int *col_size, int *row_size, int fd);
int	to_matrix(int col_size, int row_size, int fd);
int	process_arg(char *filename);

#endif
