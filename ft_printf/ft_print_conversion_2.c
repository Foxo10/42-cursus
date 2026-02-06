/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:25:29 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/30 20:14:04 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr_base_ul(unsigned long n, const char *base)
{
	unsigned long	b;
	int				count;

	b = ft_strlen(base);
	count = 0;
	if (n >= b)
		count += ft_putnbr_base_ul(n / b, base);
	ft_putchar_fd(base[n % b], 1);
	return (count + 1);
}
