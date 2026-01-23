/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 12:58:18 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/22 13:07:42 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
s: La cadena sobre la que iterar.
f: La función a aplicar sobre cada carácter.
Aplica la función ‘f’ a cada carácter de la string
‘s’, pasando como parámetros el índice de cada
carácter dentro de ‘s’ y la dirección del propio
carácter, que puede modificarse si es necesario.
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
