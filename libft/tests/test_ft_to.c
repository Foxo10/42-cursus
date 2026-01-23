/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_to.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 12:29:27 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/21 15:26:18 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	test_toupper(void)
{
	int		i;
	int		n_upper;
	int		tests_upper[] = {'A', 'Z', 'a', 'z', '@', '[', '`', '{', '0', '9',
				' ', '\n', '\t', '\0', 31, 126, 127, 128, 255, -1};
	char	case_name[32];
	int		x;
	int		ft;
	int		ref;
	int		ok;

	t_test_begin("toupper");
	n_upper = (int)(sizeof(tests_upper) / sizeof(tests_upper[0]));
	i = 0;
	while (i < n_upper)
	{
		x = tests_upper[i];
		ft = ft_toupper(x);
		ref = toupper(x);
		ok = (ft == ref);
		if (x >= 32 && x <= 126)
			snprintf(case_name, sizeof(case_name), "Caso '%c'", (char)x);
		else
			snprintf(case_name, sizeof(case_name), "Caso 0x%X (%d)",
				(unsigned int)x, x);
		t_case(ok, case_name);
		if (!ok)
			t_print_int_triplet(x, ft, ref);
		i++;
	}
}

static void	test_tolower(void)
{
	int		i;
	int		n_lower;
	int		tests_lower[] = {'A', 'Z', 'a', 'z', '@', '[', '`', '{', '0', '9',
				' ', '\n', '\t', '\0', 31, 126, 127, 128, 255, -1};
	char	case_name[32];
	int		x;
	int		ft;
	int		ref;
	int		ok;

	t_test_begin("tolower");
	n_lower = (int)(sizeof(tests_lower) / sizeof(tests_lower[0]));
	i = 0;
	while (i < n_lower)
	{
		x = tests_lower[i];
		ft = ft_tolower(x);
		ref = tolower(x);
		ok = (ft == ref);
		if (x >= 32 && x <= 126)
			snprintf(case_name, sizeof(case_name), "Caso '%c'", (char)x);
		else
			snprintf(case_name, sizeof(case_name), "Caso 0x%X (%d)",
				(unsigned int)x, x);
		t_case(ok, case_name);
		if (!ok)
			t_print_int_triplet(x, ft, ref);
		i++;
	}
	t_test_end();
}

void	test_to(void)
{
	test_tolower();
	test_toupper();
}
