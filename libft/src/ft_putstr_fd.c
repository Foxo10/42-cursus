/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:52:33 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/22 18:33:15 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
s: La cadena a enviar.
fd: El descriptor de archivo sobre el que escribir.
Envía la cadena ‘s’ al descriptor de archivo
especificado.
*/

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
		write(fd, s, ft_strlen(s));
}

/*
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int	fd;

	// 1) STDOUT
	ft_putstr_fd("Hola por stdout (fd=1)\n", 1);
	// 2) STDERR
	ft_putstr_fd("Hola por stderr (fd=2)\n", 2);
	// 3) Archivo
	fd = open("out_putstr.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	ft_putstr_fd("Esto va al archivo out_putstr.txt\n", fd);
	ft_putstr_fd("Segunda linea en el archivo.\n", fd);
	close(fd);
	return (0);
}
	*/
