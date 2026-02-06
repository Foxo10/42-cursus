/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 12:11:53 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/27 14:18:14 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_digits(long n)
{
	size_t	digits;

	if (n == 0)
		return (1);
	digits = 0;
	if (n < 0)
	{
		digits++;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	size_t	digits;
	long	nb;
	char	*result;

	nb = (long)n;
	digits = ft_count_digits(nb);
	result = (char *)malloc((sizeof(char) * (digits + 1)));
	if (result != NULL)
	{
		result[digits] = '\0';
		if (nb == 0)
			result[0] = '0';
		if (nb < 0)
		{
			result[0] = '-';
			nb = -nb;
		}
		while (nb > 0)
		{
			result[digits - 1] = (nb % 10) + '0';
			nb /= 10;
			digits--;
		}
	}
	return (result);
}
