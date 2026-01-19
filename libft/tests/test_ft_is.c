/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_is.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:15:47 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/16 14:01:54 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static int	same_bool(int ft, int libc)
{
	if (ft == 0 && libc == 0)
		return (1);
	if (ft != 0 && libc != 0)
		return (1);
	return (0);
}

static int	check_and_print_ko(const char *name, int x, int ft, int libc)
{
	if (!same_bool(ft, libc))
	{
		printf("KO %s c=%4d -> ft=%d libc=%d\n", name, x, ft, libc);
		return (1);
	}
	return (0);
}

void	test_is(void)
{
	int	i;
	int	n;
	int	fails_alpha;
	int	fails_digit;
	int	fails_alnum;
	int	fails_ascii;
	int	fails_print;
	int	tests[] = {'A', 'Z', 'a', 'z', '@', '[', '`', '{', '0', '9', '/', ';',
			':', '-', '_', ' ', '\n', '\t', '\0', 31, 32, 126, 127, 128, 255,
			-1, -42};

	n = (int)(sizeof(tests) / sizeof(tests[0]));
	fails_alpha = 0;
	fails_digit = 0;
	fails_alnum = 0;
	fails_ascii = 0;
	fails_print = 0;
	printf("------ Test isalpha ------\n");
	i = 0;
	while (i < n)
	{
		fails_alpha += check_and_print_ko("isalpha", tests[i],
				ft_isalpha(tests[i]), isalpha((unsigned char)tests[i]));
		i++;
	}
	if (fails_alpha == 0)
		printf("OK: isalpha\n");
	printf("\n------ Test isdigit ------\n");
	i = 0;
	while (i < n)
	{
		fails_digit += check_and_print_ko("isdigit", tests[i],
				ft_isdigit(tests[i]), isdigit((unsigned char)tests[i]));
		i++;
	}
	if (fails_digit == 0)
		printf("OK: isdigit\n");
	printf("\n------ Test isalnum ------\n");
	i = 0;
	while (i < n)
	{
		fails_alnum += check_and_print_ko("isalnum", tests[i],
				ft_isalnum(tests[i]), isalnum((unsigned char)tests[i]));
		i++;
	}
	if (fails_alnum == 0)
		printf("OK: isalnum\n");
	printf("\n------ Test isascii ------\n");
	i = 0;
	while (i < n)
	{
		fails_ascii += check_and_print_ko("isascii", tests[i],
				ft_isascii(tests[i]), (tests[i] >= 0 && tests[i] <= 127));
		i++;
	}
	if (fails_ascii == 0)
		printf("OK: isascii\n");
	printf("\n------ Test isprint ------\n");
	i = 0;
	while (i < n)
	{
		fails_print += check_and_print_ko("isprint", tests[i],
				ft_isprint(tests[i]), isprint((unsigned char)tests[i]));
		i++;
	}
	if (fails_print == 0)
		printf("OK: isprint\n");
	printf("\n");
	if (fails_alpha + fails_digit + fails_alnum + fails_ascii
		+ fails_print == 0)
		printf("OK: all is* tests\n");
	else
		printf("KO: %d mismatches total\n", fails_alpha + fails_digit
			+ fails_alnum + fails_ascii + fails_print);
}
