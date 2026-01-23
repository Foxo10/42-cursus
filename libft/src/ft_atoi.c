/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 13:55:46 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/21 15:56:40 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
DESCRIPTION
		The  atoi() function converts the initial portion of the string pointed
		to by nptr to int.  The behavior is the same as

			strtol(nptr, NULL, 10);

		except that atoi() does not detect errors.

		The atol() and atoll() functions behave the same as atoi(), except that
		they  convert the initial portion of the string to their return type of
		long or long long.

RETURN VALUE
		The converted value or 0 on error.
*/

static int	ft_isspace(int c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v');
}

static int	ft_get_sign(char c, int *i)
{
	if (c == '-')
	{
		(*i)++;
		return (-1);
	}
	if (c == '+')
		(*i)++;
	return (1);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	sign = ft_get_sign(nptr[i], &i);
	result = 0;
	while (ft_isdigit(nptr[i]))
	{
		result = (result * 10) + (nptr[i] - '0');
		i++;
	}
	return (result * sign);
}
