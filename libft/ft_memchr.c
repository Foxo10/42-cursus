/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:42:12 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/16 12:08:30 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
DESCRIPTION
		The  memchr()  function  scans  the  initial n bytes of the memory area
		pointed to by s for the first instance of c.  Both c and the  bytes  of
		the memory area pointed to by s are interpreted as unsigned char.

RETURN VALUE
		The  memchr()  and memrchr() functions return a pointer to the matching
		byte or NULL if the character does not occur in the given memory area.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((unsigned char *)s + i);
		i++;
	}
	return (NULL);
}
