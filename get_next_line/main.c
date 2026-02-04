/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:29:16 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/02/04 13:24:50 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

static void	read_file(const char *path)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		perror(path);
		return ;
	}
	printf("\n===== FILE: %s =====\n", path);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}

static void	read_stdin(void)
{
	char	*line;

	printf("\n===== STDIN (fd=0) =====\n");
	printf("Escribe líneas y pulsa Enter. Para terminar: Ctrl+D\n");
	line = get_next_line(0);
	while (line != NULL)
	{
		printf("[stdin] %s", line);
		free(line);
		line = get_next_line(0);
	}
}

int	main(void)
{
	// read_file("file_tests/vacio.txt");
	// read_file("file_tests/una_linea.txt");
	// read_file("file_tests/una_linea_2.txt");
	// read_file("file_tests/saltos.txt");
	read_file("file_tests/lineas.txt");
	read_stdin();
	return (0);
}
