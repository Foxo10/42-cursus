/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 13:06:55 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/27 19:00:46 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
c: The character to send.
fd: The file descriptor to write to.

Sends the character 'c' to the specified file descriptor.

*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
