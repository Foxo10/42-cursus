/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:04:02 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/23 19:34:13 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
DESCRIPTION
		The  memcpy()  function  copies  n bytes from memory area src to memory
		area dest.  The memory areas must not overlap.  Use memmove(3)  if  the
		memory areas do overlap.

RETURN VALUE
		The memcpy() function returns a pointer to dest.
*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == NULL && src == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}

/*
#include <stddef.h>
#include <string.h>

int	main(void)
{
	void		*dest;
	const void	*src;
	size_t		n;
	void		*ret_libc;
	void		*ret_ft;

	dest = NULL;
	src = NULL;
	n = 0;
	ret_libc = memcpy(dest, src, n);
	ret_ft = ft_memcpy(dest, src, n);
	printf("libc memcpy : dest=%p src=%p n=%zu -> ret=%p\n", dest, src, n,
		ret_libc);
	printf("ft_memcpy   : dest=%p src=%p n=%zu -> ret=%p\n", dest, src, n,
		ret_ft);
	if (ret_libc == ret_ft)
		printf("same return? YES\n");
	else
		printf("same return? NO\n");
	return (0);
}*/
