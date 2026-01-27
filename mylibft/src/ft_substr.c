/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 11:40:27 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/22 18:33:29 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
s: La cadena original desde la que se crea la
subcadena.
start: El índice del carácter en ‘s’ desde el que
empieza la subcadena.
len: La longitud máxima de la subcadena.
*/

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	result_len;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if ((size_t)start >= s_len)
		result_len = 0;
	else
		result_len = s_len - (size_t)start;
	if (result_len > len)
		result_len = len;
	result = (char *)malloc(sizeof(char) * (result_len + 1));
	if (result != NULL)
	{
		ft_memcpy(result, s + start, result_len);
		result[result_len] = '\0';
	}
	return (result);
}
