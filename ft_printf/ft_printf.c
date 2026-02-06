/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:24:02 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/02/06 18:06:06 by odiez-gu         ###   ########.fr       */
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
		if (format[i] == '%' && format[i + 1])
		{
			count += ft_print_conversion(format[i + 1], args);
			i += 2;
			continue ;
		}
		ft_putchar_fd(format[i], 1);
		i++;
		count++;
	}
	va_end(args);
	return (count);
}
/*int	main(void)
{
	int				result_ft;
	int				result_og;
	char			*null_str;
	unsigned int	u1;
	unsigned int	u2;
	unsigned int	u3;
	unsigned int	u4;
	int				x;
	void			*p1;
	void			*p2;
	void			*p3;

	x = 42;
	p1 = NULL;
	p2 = (void *)0x1234abcd;
	p3 = (void *)&x;
	null_str = NULL;
	u1 = 0;
	u2 = 42u;
	u3 = UINT_MAX;
	u4 = 4294967295u;
	printf("\n========== NO %% ==========\n");
	result_ft = ft_printf("ft: hello my name is Laura and i'm 23 years old\n");
	printf("ft_printf -> %d \n", result_ft);
	result_og = printf("pf: hello my name is Laura and i'm 23 years old\n");
	printf("printf    -> %d \n", result_og);
	printf("\n========== %%c ==========\n");
	result_ft = ft_printf("ft: char = [%c]\n", 'A');
	printf("ft_printf -> %d \n", result_ft);
	result_og = printf("pf: char = [%c]\n", 'A');
	printf("printf    -> %d \n", result_og);
	result_ft = ft_printf("ft: char = [%c]\n", '\0');
	printf("ft_printf -> %d \n", result_ft);
	result_og = printf("pf: char = [%c]\n", '\0');
	printf("printf    -> %d \n", result_og);
	printf("\n========== %%s ==========\n");
	result_ft = ft_printf("ft: str = [%s]\n", "laura");
	printf("ft_printf  -> %d \n", result_ft);
	result_og = printf("pf: str = [%s]\n", "laura");
	printf("printf    -> %d \n", result_og);
	result_ft = ft_printf("ft: empty_str = [%s]\n", "");
	printf("ft_printf  -> %d \n", result_ft);
	result_og = printf("pf: empty_str = [%s]\n", "");
	printf("printf    -> %d \n", result_og);
	result_ft = ft_printf("ft: null_str = [%s]\n", null_str);
	printf("ft_printf  -> %d \n", result_ft);
	result_og = printf("pf: null_str = [%s]\n", null_str);
	printf("printf    -> %d \n", result_og);
	printf("\n========== %%p ==========\n");
	result_ft = ft_printf("ft: p1 = [%p]\n", p1);
	printf("ft_printf -> %d\n", result_ft);
	result_og = printf("pf: p1 = [%p]\n", p1);
	printf("printf    -> %d\n", result_og);
	result_ft = ft_printf("ft: p2 = [%p]\n", p2);
	printf("ft_printf -> %d\n", result_ft);
	result_og = printf("pf: p2 = [%p]\n", p2);
	printf("printf    -> %d\n", result_og);
	result_ft = ft_printf("ft: p3 = [%p]\n", p3);
	printf("ft_printf -> %d\n", result_ft);
	result_og = printf("pf: p3 = [%p]\n", p3);
	printf("printf    -> %d\n", result_og);
	printf("\n========== %%d ==========\n");
	result_ft = ft_printf("ft: d1=%d d2=%d d3=%d\n", -2030, 123456789, 0);
	printf("ft_printf -> %d\n", result_ft);
	result_og = printf("pf: d1=%d d2=%d d3=%d\n", -2030, 123456789, 0);
	printf("printf    -> %d\n", result_og);
	result_ft = ft_printf("ft: d4=%d d5=%d\n", INT_MIN, INT_MAX);
	printf("ft_printf -> %d\n", result_ft);
	result_og = printf("pf: d4=%d d5=%d\n", INT_MIN, INT_MAX);
	printf("printf    -> %d\n", result_og);
	printf("\n========== %%i ==========\n");
	result_ft = ft_printf("ft: i1=%i i2=%i i3=%i\n", -2030, 123456789, 0);
	printf("ft_printf -> %d\n", result_ft);
	result_og = printf("pf: i1=%i i2=%i i3=%i\n", -2030, 123456789, 0);
	printf("printf    -> %d\n", result_og);
	printf("\n========== %%u ==========\n");
	result_ft = ft_printf("ft: u1=%u u2=%u u3=%u u4=%u\n", u1, u2, u3, u4);
	printf("ft_printf -> %d\n", result_ft);
	result_og = printf("pf: u1=%u u2=%u u3=%u u4=%u\n", u1, u2, u3, u4);
	printf("printf    -> %d\n", result_og);
	result_ft = ft_printf("ft: (neg as unsigned) = %u\n",
			(unsigned int)INT_MIN);
	printf("ft_printf -> %d\n", result_ft);
	result_og = printf("pf: (neg as unsigned) = %u\n", (unsigned int)INT_MIN);
	printf("printf    -> %d\n", result_og);
	printf("\n========== %%x / %%X ==========\n");
	result_ft = ft_printf("ft: u1=%x u2=%x u3=%x u4=%x\n", u1, u2, u3, u4);
	printf("ft_printf -> %d\n", result_ft);
	result_og = printf("pf: u1=%x u2=%x u3=%x u4=%x\n", u1, u2, u3, u4);
	printf("printf    -> %d\n", result_og);
	result_ft = ft_printf("ft: u1=%X u2=%X u3=%X u4=%X\n", u1, u2, u3, u4);
	printf("ft_printf -> %d\n", result_ft);
	result_og = printf("pf: u1=%X u2=%X u3=%X u4=%X\n", u1, u2, u3, u4);
	printf("printf    -> %d\n", result_og);
	printf("\n========== %%%% ==========\n");
	result_ft = ft_printf("ft: percent = [%%]\n");
	printf("ft_printf -> %d\n", result_ft);
	result_og = printf("pf: percent = [%%]\n");
	printf("printf    -> %d\n", result_og);
	printf("\n========== MIX ==========\n");
	result_ft = ft_printf("ft: c=%c s=%s p=%p d=%d i=%i u=%u x=%x X=%X %%\n",
			'Z', "hola", &x, -42, 42, 42u, 42u, 42u);
	printf("ft_printf -> %d\n", result_ft);
	result_og = printf("pf: c=%c s=%s p=%p d=%d i=%i u=%u x=%x X=%X %%\n", 'Z',
			"hola", &x, -42, 42, 42u, 42u, 42u);
	printf("printf    -> %d\n", result_og);
	result_ft = ft_printf("ft: c=%c%c s=%s%s p=%p%p d=%d%d i=%i%i "
							"u=%u%u x=%x%x X=%X%X %%%%\n",
							'Z',
							'a',
							"hola",
							"mundo",
							(void *)&x,
							(void *)p2,
							-42,
							0,
							42,
							10,
							42u,
							(unsigned int)4294967295u,
							42u,
							(unsigned int)-10,
							42u,
							INT_MIN);
	printf("ft_printf -> %d\n", result_ft);
	result_og = printf("pf: c=%c%c s=%s%s p=%p%p d=%d%d i=%i%i "
						"u=%u%u x=%x%x X=%X%X %%%%\n",
						'Z',
						'a',
						"hola",
						"mundo",
						(void *)&x,
						(void *)p2,
						-42,
						0,
						42,
						10,
						42u,
						(unsigned int)4294967295u,
						42u,
						(unsigned int)-10,
						42u,
						INT_MIN);
	printf("printf    -> %d\n", result_og);
	return (0);
}*/
