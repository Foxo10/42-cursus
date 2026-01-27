/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 11:38:29 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/27 13:36:15 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
DESCRIPTION
		The  memmove()  function  copies n bytes from memory area src to memory
		area dest.  The memory areas may overlap: copying takes place as though
		the  bytes in src are first copied into a temporary array that does not
		overlap src or dest, and the bytes are then copied from  the  temporary
		array to dest.

RETURN VALUE
		The memmove() function returns a pointer to dest.
*/

static void	*ft_memrcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = n - 1;
	while (i + 1 > 0)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (n == 0 || src == dest)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	return (ft_memrcpy(dest, src, n));
}
