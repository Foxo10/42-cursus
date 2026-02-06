/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 16:08:57 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/27 14:29:02 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
s: The string to iterate over.
f: The function to apply to each character.
Applies the function 'f' to each character in the string
's', passing its index as the first argument and t
he character itself as the second argument.
A new string is created (using malloc(3))
to store the results of the successive applications of 'f'.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			s_len;
	char			*result;

	if (s == NULL || f == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (s_len + 1));
	if (result != NULL)
	{
		i = 0;
		while (s[i])
		{
			result[i] = f(i, s[i]);
			i++;
		}
		result[i] = '\0';
	}
	return (result);
}
