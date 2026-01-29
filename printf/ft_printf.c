/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:24:02 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/29 18:48:52 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int	ft_printf(char const *format, ...)
{
	int		count;
	int		i;
	va_list	args;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count += ft_print_conversion(format[i + 1], args);
			i += 2;
		}
		ft_putchar_fd(format[i], 1);
		i++;
		count++;
	}
	va_end(args);
	return (count);
}
/*
• %c para imprimir un solo carácter.
• %s para imprimir una cadena de caracteres (como se define por defecto en C).
• %p el puntero void * dado como argumento se imprime en formato hexadecimal.
• %d para imprimir un número decimal (base 10).
• %i para imprimir un entero en base 10.
• %u para imprimir un número decimal (base 10) sin signo.
• %x para imprimir un número hexadecimal (base 16) en minúsculas.
• %X para imprimir un número hexadecimal (base 16) en mayúsculas.
• % % para imprimir el símbolo del porcentaje.
*/

int	main(void)
{
	int	result;

	result = ft_printf("hello my name is Laura and i'm 23 years old\n");
	printf("ft_printf -> %d \n", result);
	result = printf("hello my name is Laura and i'm 23 years old\n");
	printf("printf -> %d \n", result);
	result = ft_printf("hello my name is %s\n", "laura");
	printf("ft_printf -> %d \n", result);
	result = printf("hello my name is %s\n", "laura");
	printf("printf -> %d \n", result);
	result = ft_printf("i'm %d years old\n", -2030);
	printf("ft_printf -> %d \n", result);
	result = printf("i'm %d years old\n", -2030);
	printf("printf -> %d \n", result);
	result = ft_printf("i'm %d years old\n", 12345689);
	printf("ft_printf -> %d \n", result);
	result = printf("i'm %d years old\n", 12345689);
	printf("printf -> %d \n", result);
	return (0);
}
