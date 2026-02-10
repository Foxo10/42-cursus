/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 16:29:16 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/02/05 15:44:44 by odiez-gu         ###   ########.fr       */
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
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		printf("%s", line);
		free(line);
	}
	close(fd);
}

int	main(void)
{
	// read_file("file_tests/vacio.txt");
	// read_file("file_tests/una_linea.txt");
	// read_file("file_tests/una_linea_2.txt");
	// read_file("file_tests/saltos.txt");
	read_file("file_tests/lineas.txt");
	return (0);
}
