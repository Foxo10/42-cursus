/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:27:48 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/15 13:23:33 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
isascii()
				checks whether c is a 7-bit unsigned char value that  fits  into
				the ASCII character set.

				RETURN VALUE
		The  values  returned  are  nonzero  if  the character c falls into the
		tested class, and zero if not.

*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
