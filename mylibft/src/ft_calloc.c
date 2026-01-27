/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 12:34:49 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/23 18:16:33 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
DESCRIPTION
		The calloc() function allocates memory for an array of  nmemb  elements
		of  size bytes each and returns a pointer to the allocated memory.  The
		memory is set to zero.  If nmemb or size is 0,  then  calloc()  returns
		either  NULL,  or a unique pointer value that can later be successfully
		passed to free().  If the multiplication of nmemb and size would result
		in  integer  overflow, then calloc() returns an error.  By contrast, an
		integer overflow would not be detected in the following  call  to  mal‐
		loc(),  with the result that an incorrectly sized block of memory would
		be allocated:

RETURN VALUE
		The malloc() and calloc() functions return a pointer to  the  allocated
		memory,  which  is  suitably  aligned for any built-in type.  On error,
		these functions return NULL.  NULL may also be returned by a successful
		call  to  malloc() with a size of zero, or by a successful call to cal‐
		loc() with nmemb or size equal to zero.
*/

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*result;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total = nmemb * size;
	result = malloc(total);
	if (result != NULL)
		ft_bzero(result, total);
	return (result);
}
