/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:23:54 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/27 13:35:49 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
DESCRIPTION
		The strlcpy() and strlcat() functions copy and concatenate strings re‐
		spectively.  They are designed to be safer, more consistent,
			and less er‐
		ror prone replacements for strncpy(3) and strncat(3).  Unlike those func‐
		tions,
			strlcpy() and strlcat() take the full size of the buffer (not just
		the length) and guarantee to NUL-terminate the result (as long as size is
		larger than 0 or, in the case of strlcat(), as long as there is at least
		one byte free in dst).  Note that a byte for the NUL should be included
		in size.  Also note that strlcpy() and strlcat() only operate on true “C”
		strings.  This means that for strlcpy() src must be NUL-terminated and
		for strlcat() both src and dst must be NUL-terminated.

		The strlcpy() function copies up to size
			- 1 characters from the NUL-ter‐
		minated string src to dst, NUL-terminating the result.

		The strlcat() function appends the NUL-terminated string src to the end
		of dst.  It will append at most size - strlen(dst) - 1 bytes, NUL-termi‐
		nating the result.

RETURN VALUES
		The strlcpy() and strlcat() functions return the total length of the
		string they tried to create.  For strlcpy() that means the length of src.
		For strlcat() that means the initial length of dst plus the length of
		src.  While this may seem somewhat confusing,
			it was done to make trunca‐
		tion detection simple.

		Note, however, that if strlcat() traverses size characters without find‐
		ing a NUL,
			the length of the string is considered to be size and the des‐
		tination string will not be NUL-terminated (since there was no space for
		the NUL).  This keeps strlcat() from running off the end of a string.  In
		practice this should not happen (as it means that either size is incor‐
		rect or that dst is not a proper “C” string).  The check exists to pre‐
		vent potential security problems in incorrect code.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	i;
	size_t	srclen;

	srclen = ft_strlen(src);
	if (dstsize == 0)
		return (srclen);
	dstlen = 0;
	while (dstlen < dstsize && dst[dstlen] != '\0')
		dstlen++;
	if (dstlen == dstsize)
		return (dstsize + srclen);
	i = 0;
	while (src[i] && i + dstlen < dstsize - 1)
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}
