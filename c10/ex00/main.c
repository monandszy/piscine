/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sandrzej <sandrzej@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 16:45:52 by sandrzej          #+#    #+#             */
/*   Updated: 2025/07/15 17:33:58 by sandrzej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

int	error(char *msg)
{
	while (*msg)
	{
		write(STDERR_FILENO, msg, 1);
		msg++;
	}
	write(STDERR_FILENO, "\n", 1);
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd;
	char	*filename;
	int		buff[4096];
	int		bytes_read;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (error("Cannot read file"));
		bytes_read = read(fd, buff, sizeof(buff));
		while (bytes_read > 0)
		{
			write(STDOUT_FILENO, buff, bytes_read);
			bytes_read = read(fd, buff, sizeof(buff));
		}
		argv++;
		return (0);
	}
	else if (argc < 2)
		return (error("File name missing"));
	else if (argc > 2)
		return (error("Too many arguments"));
	return (1);
}
