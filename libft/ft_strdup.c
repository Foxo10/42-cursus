/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 12:45:15 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/16 12:58:35 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
DESCRIPTION
		The  strdup() function returns a pointer to a new string which is a du‐
		plicate of the string s.  Memory for the new string  is  obtained  with
		malloc(3), and can be freed with free(3).

RETURN VALUE
		On  success,  the strdup() function returns a pointer to the duplicated
		string.  It returns NULL if insufficient memory was available, with er‐
		rno set to indicate the cause of the error.

*/

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;
	size_t	size;

	size = ft_strlen(s);
	dest = (char *)malloc(size + 1);
	if (dest != NULL)
	{
		i = 0;
		while (i <= size)
		{
			dest[i] = s[i];
			i++;
		}
	}
	return (dest);
}
