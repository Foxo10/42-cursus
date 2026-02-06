/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 17:16:04 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/27 14:17:46 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
isdigit()
		checks for a digit (0 through 9).

RETURN VALUE
		The  values  returned  are  nonzero  if  the character c falls into the
		tested class, and zero if not.
*/

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
