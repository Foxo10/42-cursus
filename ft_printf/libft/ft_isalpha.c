/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 11:34:01 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/27 14:17:15 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
isalpha()
		checks  for an alphabetic character; in the standard "C" locale,
		it is equivalent to (isupper(c) ||  islower(c)).   In  some  lo‐
		cales, there may be additional characters for which isalpha() is
		true—letters which are neither uppercase nor lowercase.

RETURN VALUE
		The  values  returned  are  nonzero  if  the character c falls into the
		tested class, and zero if not.
*/

static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

static int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
