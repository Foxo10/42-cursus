/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 14:10:06 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/28 10:30:30 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	int				pos;
	unsigned char	ch;

	i = 0;
	pos = -1;
	ch = (unsigned char)c;
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
