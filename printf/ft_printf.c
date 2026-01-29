/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:24:02 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/29 19:29:42 by odiez-gu         ###   ########.fr       */
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
	int		result_ft;
	int		result_og;
	char	*null_str;

	printf("\n========== NO %% ==========\n");
	result_ft = ft_printf("ft: hello my name is Laura and i'm 23 years old\n");
	printf("ft_printf -> %d \n", result_ft);
	result_og = printf("pf: hello my name is Laura and i'm 23 years old\n");
	printf("printf -> %d \n", result_og);
	printf("\n========== %%c ==========\n");
	result_ft = ft_printf("ft: char = [%c]\n", 'A');
	printf("ft_printf -> %d \n", result_ft);
	result_og = printf("pf: char = [%c]\n", 'A');
	printf("printf -> %d \n", result_og);
	result_ft = ft_printf("ft: char = [%c]\n", '\0');
	printf("ft_printf -> %d \n", result_ft);
	result_og = printf("pf: char = [%c]\n", '\0');
	printf("printf -> %d \n", result_og);
	printf("\n========== %%s ==========\n");
	result_ft = ft_printf("ft: str = [%s]\n", "laura");
	printf("ft_printf  -> %d \n", result_ft);
	result_og = printf("pf: str = [%s]\n", "laura");
	printf("printf -> %d \n", result_og);
	result_ft = ft_printf("ft: empty_str = [%s]\n", "");
	printf("ft_printf  -> %d \n", result_ft);
	result_og = printf("pf: empty_str = [%s]\n", "");
	printf("printf -> %d \n", result_og);
	null_str = NULL;
	result_ft = ft_printf("ft: null_str = [%s]\n", null_str);
	printf("ft_printf  -> %d \n", result_ft);
	result_og = printf("pf: null_str = [%s]\n", null_str);
	printf("printf -> %d \n", result_og);
	printf("\n========== %%d ==========\n");
	result_ft = ft_printf("ft: d1=%d d2=%d d3=%d\n", -2030, 123456789, 0);
	printf("ft_printf -> %d\n", result_ft);
	result_og = printf("pf: d1=%d d2=%d d3=%d\n", -2030, 123456789, 0);
	printf("printf    -> %d\n", result_og);
	return (0);
}
