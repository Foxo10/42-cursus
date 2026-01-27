/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:59:11 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/15 13:54:02 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
DESCRIPTION
		The strnstr() function locates the first occurrence of the null-termi‐
		nated string little in the string big,
			where not more than len characters
		are searched.  Characters that appear after a ‘\0’ character are not
		searched.  Since the strnstr() function is a FreeBSD specific API, it
		should only be used when portability is not a concern.

RETURN VALUES
		If little is an empty string, big is returned; if little occurs nowhere
		in big, NULL is returned; otherwise a pointer to the first character of
		the first occurrence of little is returned.
EXAMPLES
		The following sets the pointer ptr to NULL, because only the first 4
		characters of largestring are searched:

			const char *largestring = "Foo Bar Baz";
			const char *smallstring = "Bar";
			char *ptr;

			ptr = strnstr(largestring, smallstring, 4);
*/

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;
	size_t	big_len;

	if (len == 0 && big == NULL)
		return (NULL);
	little_len = ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	big_len = ft_strlen(big);
	i = 0;
	while (i + little_len <= len && i <= big_len - little_len)
	{
		if (!ft_strncmp(big + i, little, little_len))
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
