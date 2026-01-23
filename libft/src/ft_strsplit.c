/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 13:22:51 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/22 18:33:23 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
s: La cadena que se va a dividir.
c: El carácter delimitador.
*/

static char	**free_splits(char **split, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static size_t	ft_count_words(char const *str, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] != c && (i == 0 || str[i - 1] == c))
			n++;
		i++;
	}
	return (n);
}

static char	*get_split(const char *str, size_t *i, char c)
{
	size_t	start;
	size_t	len;

	while (str[*i] && str[*i] == c)
		(*i)++;
	start = *i;
	while (str[*i] && str[*i] != c)
		(*i)++;
	len = *i - start;
	return (ft_substr(str, start, len));
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	n_split;
	size_t	n;
	size_t	i;

	if (!s)
		return (NULL);
	n_split = ft_count_words(s, c);
	split = (char **)malloc(sizeof(char *) * (n_split + 1));
	if (!split)
		return (NULL);
	i = 0;
	n = 0;
	while (n < n_split)
	{
		split[n] = get_split(s, &i, c);
		if (!split[n])
			return (free_splits(split, n));
		n++;
	}
	split[n] = NULL;
	return (split);
}
