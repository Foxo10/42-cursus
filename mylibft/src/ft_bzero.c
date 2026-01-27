/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:27:10 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/16 12:08:10 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
DESCRIPTION
		The  bzero()  function  erases  the  data  in the n bytes of the memory
		starting at the location pointed to by s, by writing zeros (bytes  con‐
		taining '\0') to that area.

		The  explicit_bzero()  function  performs the same task as bzero().  It
		differs from bzero() in that it guarantees that compiler  optimizations
		will  not  remove  the erase operation if the compiler deduces that the
		operation is "unnecessary".

RETURN VALUE
		None.
*/

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = 0;
		i++;
	}
}
