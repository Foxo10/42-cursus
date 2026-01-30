/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 17:40:22 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/30 20:10:46 by odiez-gu         ###   ########.fr       */
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

int	ft_print_ptr(void *p)
{
	int				count;
	unsigned long	address;

	if (!p)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd("0x", 1);
	count = 2;
	address = (unsigned long)p;
	count += ft_putnbr_base_ul(address, "0123456789abcdef");
	return (count);
}

int	ft_print_conversion(char conversion, va_list args)
{
	if (conversion == 'c')
		return (ft_print_c(va_arg(args, int)));
	else if (conversion == 's')
		return (ft_print_str(va_arg(args, char *)));
	else if (conversion == 'p')
		return (ft_print_ptr(va_arg(args, void *)));
	else if (conversion == 'd' || conversion == 'i')
		return (ft_print_nbr(va_arg(args, int)));
	else if (conversion == 'u')
		return (ft_putnbr_base_ul(va_arg(args, unsigned int), "0123456789"));
	else if (conversion == 'x')
		return (ft_putnbr_base_ul(va_arg(args, unsigned int),
				"0123456789abcdef"));
	else if (conversion == 'X')
		return (ft_putnbr_base_ul(va_arg(args, unsigned int),
				"0123456789ABCDEF"));
	else if (conversion == '%')
		return (ft_print_c('%'));
	else
		return (ft_print_c(conversion));
}
