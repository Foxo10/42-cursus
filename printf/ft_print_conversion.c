/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:40:22 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/29 19:24:16 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_print_c(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	ft_print_str(char *str)
{
	if (str == NULL)
	{
		ft_putstr_fd("(null)", 1);
		return (ft_strlen("(null)"));
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	ft_print_nbr(int nbr)
{
	long	n;
	int		count;

	count = 0;
	n = (long)nbr;
	if (n < 0)
	{
		ft_putchar_fd('-', 1);
		n = -n;
		count++;
	}
	if (n / 10 != 0)
		count += ft_print_nbr(n / 10);
	ft_putchar_fd((n % 10) + '0', 1);
	return (count + 1);
}

int	ft_print_conversion(char conversion, va_list args)
{
	if (conversion == 'c')
		return (ft_print_c(va_arg(args, int)));
	else if (conversion == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (conversion == 'p')
		return (16);
	else if (conversion == 'd')
		return (ft_print_nbr(va_arg(args, int)));
	else if (conversion == 'i')
		return (10);
	else if (conversion == 'u')
		return (10);
	else if (conversion == 'x')
		return (16);
	else if (conversion == 'X')
		return (16);
	else if (conversion == '%')
		return (1);
	else
		return (-1);
}
