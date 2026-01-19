/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:49:46 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/15 13:23:49 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
DESCRIPTION
		The  strchr() function returns a pointer to the first occurrence of the
		character c in the string s.

		The strrchr() function returns a pointer to the last occurrence of  the
		character c in the string s.

		The strchrnul() function is like strchr() except that if c is not found
		in s, then it returns a pointer to the null  byte  at  the  end  of  s,
		rather than NULL.

		Here "character" means "byte"; these functions do not work with wide or
		multibyte characters.

RETURN VALUE
		The strchr() and strrchr() functions return a pointer  to  the  matched
		character  or NULL if the character is not found.  The terminating null
		byte is considered part of the string, so that if  c  is  specified  as
		'\0', these functions return a pointer to the terminator.

		The strchrnul() function returns a pointer to the matched character, or
		a pointer to the null byte at the end of s (i.e., s+strlen(s))  if  the
		character is not found.
*/

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	ch;

	i = 0;
	ch = (char)c;
	while (s[i] && s[i] != ch)
		i++;
	if (s[i] == ch)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		pos;
	char	ch;

	i = 0;
	pos = -1;
	ch = (char)c;
	while (s[i])
	{
		if (s[i] == ch)
			pos = i;
		i++;
	}
	if (ch == '\0')
		return ((char *)(s + i));
	if (pos != -1)
		return ((char *)(s + pos));
	return (NULL);
}
