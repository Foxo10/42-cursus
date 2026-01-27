/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 19:40:13 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/16 12:08:35 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
DESCRIPTION
		The  memcmp()  function compares the first n bytes (each interpreted as
		unsigned char) of the memory areas s1 and s2.

RETURN VALUE
		The memcmp() function returns  an  integer  less  than,  equal  to,  or
		greater than zero if the first n bytes of s1 is found, respectively, to
		be less than, to match, or be greater than the first n bytes of s2.

		For a nonzero return value, the sign is determined by the sign  of  the
		difference  between  the  first  pair of bytes (interpreted as unsigned
		char) that differ in s1 and s2.

		If n is zero, the return value is zero.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (n);
	i = 0;
	while (i < n - 1 && (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i]))
	{
		i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
