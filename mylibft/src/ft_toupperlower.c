/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupperlower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:17:55 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/15 13:23:11 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
DESCRIPTION
		These functions convert lowercase letters to uppercase, and vice versa.

		If c is a lowercase letter, toupper() returns its uppercase equivalent,
		if an uppercase representation exists in the  current  locale.   Other‐
		wise,  it  returns c.  The toupper_l() function performs the same task,
		but uses the locale referred to by the locale handle locale.

		If c is an uppercase letter, tolower() returns  its  lowercase  equiva‐
		lent, if a lowercase representation exists in the current locale.  Oth‐
		erwise, it returns c.  The tolower_l() function performs the same task,
		but uses the locale referred to by the locale handle locale.

		If  c  is neither an unsigned char value nor EOF, the behavior of these
		functions is undefined.

		The behavior of toupper_l() and tolower_l() is undefined if  locale  is
		the special locale object LC_GLOBAL_LOCALE (see duplocale(3)) or is not
		a valid locale object handle.

		RETURN VALUE
		The value returned is that of the converted letter, or c if the conver‐
		sion was not possible.
*/

static int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

static int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

int	ft_toupper(int c)
{
	if (ft_islower(c))
		c -= 'a' - 'A';
	return (c);
}

int	ft_tolower(int c)
{
	if (ft_isupper(c))
		c += 'a' - 'A';
	return (c);
}
