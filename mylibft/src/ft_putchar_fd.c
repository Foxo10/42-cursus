/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:06:55 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/22 18:32:35 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
c: El carácter a enviar.
fd: El descriptor de archivo sobre el que escribir.
Envía el carácter ‘c’ al descriptor de archivo
(file descriptor ) especificado.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*#include <fcntl.h>

int	main(void)
{
	int	fd;

	// 1) STDOUT (terminal normal)
	ft_putchar_fd('O', 1);
	ft_putchar_fd('K', 1);
	ft_putchar_fd('\n', 1);
	// 2) STDERR (sale también en terminal, pero por el canal de error)
	ft_putchar_fd('E', 2);
	ft_putchar_fd('R', 2);
	ft_putchar_fd('R', 2);
	ft_putchar_fd('\n', 2);
	// 3) Archivo (crea/reescribe "out.txt")
	fd = open("out.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	ft_putchar_fd('H', fd);
	ft_putchar_fd('o', fd);
	ft_putchar_fd('l', fd);
	ft_putchar_fd('a', fd);
	ft_putchar_fd('\n', fd);
	close(fd);
	return (0);
}*/
