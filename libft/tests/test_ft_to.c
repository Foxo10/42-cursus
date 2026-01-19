/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_to.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:29:27 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/16 14:02:01 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static int	check_and_print_ko(const char *name, int x, int ft, int libc)
{
	if (ft != libc)
	{
		printf("KO %s c=%4d -> ft=%d libc=%d\n", name, x, ft, libc);
		return (1);
	}
	return (0);
}

void	test_to(void)
{
	int	i;
	int	fails_lower;
	int	fails_upper;
	int	tests[] = {'A', 'Z', 'a', 'z', '@', '[', '`', '{', '0', '9', '/', ';',
			':', '-', '_', ' ', '\n', '\t', '\0', 31, 32, 126, 127, 128, 255};
	int	n;

	n = (int)(sizeof(tests) / sizeof(tests[0]));
	fails_lower = 0;
	printf("\n------ Test tolower ------\n");
	i = 0;
	while (i < n)
	{
		fails_lower += check_and_print_ko("tolower", tests[i],
				ft_tolower(tests[i]), tolower((unsigned char)tests[i]));
		i++;
	}
	if (fails_lower == 0)
		printf("OK: tolower\n");
	else
		printf("KO: %d mismatches\n", fails_lower);
	fails_upper = 0;
	printf("\n------ Test toupper ------\n");
	i = 0;
	while (i < n)
	{
		fails_upper += check_and_print_ko("toupper", tests[i],
				ft_toupper(tests[i]), toupper((unsigned char)tests[i]));
		i++;
	}
	if (fails_upper == 0)
		printf("OK: toupper\n");
	else
		printf("KO: %d mismatches\n", fails_upper);
	printf("\n");
	if (fails_upper + fails_lower == 0)
		printf("OK: all to* tests\n");
	else
		printf("KO: %d mismatches total\n", fails_lower + fails_upper);
}
