/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 12:41:13 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/15 13:23:45 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
isprint()
				checks for any printable character including space.

				RETURN VALUE
		The  values  returned  are  nonzero  if  the character c falls into the
		tested class, and zero if not.
*/

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
