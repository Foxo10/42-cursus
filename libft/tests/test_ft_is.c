/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_is.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:15:47 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/21 14:03:58 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static void	test_isalpha(void)
{
	int		i;
	int		n_alpha;
	int		tests_alpha[] = {'A', 'Z', 'a', 'z', '@', '[', '`', '{', '0', '9',
				' ', '\n', '\t', 31, 126, 127};
	char	case_name[32];
	int		x;
	int		ft;
	int		ref;
	int		ok;

	t_test_begin("isalpha");
	n_alpha = (int)(sizeof(tests_alpha) / sizeof(tests_alpha[0]));
	i = 0;
	while (i < n_alpha)
	{
		x = tests_alpha[i];
		ft = ft_isalpha(x);
		ref = isalpha((unsigned char)x);
		ok = t_same_bool(ft, ref);
		snprintf(case_name, sizeof(case_name), "Caso '%c'", (char)x);
		t_case(ok, case_name);
		if (!ok)
			t_print_int_triplet(x, ft, ref);
		i++;
	}
	t_test_end();
}

static void	test_isdigit(void)
{
	int		i;
	int		n_digit;
	int		tests_digit[] = {'0', '9', '5', '/', ':', 'A', 'z', ' ', '\n', '\t',
				31, 126, 127};
	char	case_name[32];
	int		x;
	int		ft;
	int		ref;
	int		ok;

	t_test_begin("isdigit");
	n_digit = (int)(sizeof(tests_digit) / sizeof(tests_digit[0]));
	i = 0;
	while (i < n_digit)
	{
		x = tests_digit[i];
		ft = ft_isdigit(x);
		ref = isdigit((unsigned char)x);
		ok = t_same_bool(ft, ref);
		snprintf(case_name, sizeof(case_name), "Caso '%c'", (char)x);
		t_case(ok, case_name);
		if (!ok)
			t_print_int_triplet(x, ft, ref);
		i++;
	}
	t_test_end();
}

static void	test_isalnum(void)
{
	int		i;
	int		n_alnum;
	int		tests_alnum[] = {'A', 'Z', 'a', 'z', '0', '9', '@', '[', '`', '{',
				'/', ':', '_', '+', '\t', '\n', 33, 126, 127};
	char	case_name[32];
	int		x;
	int		ft;
	int		ref;
	int		ok;

	t_test_begin("isalnum");
	n_alnum = (int)(sizeof(tests_alnum) / sizeof(tests_alnum[0]));
	i = 0;
	while (i < n_alnum)
	{
		x = tests_alnum[i];
		ft = ft_isalnum(x);
		ref = isalnum((unsigned char)x);
		ok = t_same_bool(ft, ref);
		snprintf(case_name, sizeof(case_name), "Caso '%c'", (char)x);
		t_case(ok, case_name);
		if (!ok)
			t_print_int_triplet(x, ft, ref);
		i++;
	}
	t_test_end();
}

static void	test_isascii(void)
{
	int		i;
	int		n_ascii;
	int		tests_ascii[] = {0, 1, 2, 9, 10, 31, 32, 65, 97, 126, 127, -1, -42,
				128, 129, 255, 256, 1024};
	char	case_name[32];
	int		x;
	int		ft;
	int		ref;
	int		ok;

	t_test_begin("isascii");
	n_ascii = (int)(sizeof(tests_ascii) / sizeof(tests_ascii[0]));
	i = 0;
	while (i < n_ascii)
	{
		x = tests_ascii[i];
		ft = ft_isascii(x);
		ref = isascii(x);
		ok = t_same_bool(ft, ref);
		snprintf(case_name, sizeof(case_name), "Caso '%c'", (char)x);
		t_case(ok, case_name);
		if (!ok)
			t_print_int_triplet(x, ft, ref);
		i++;
	}
	t_test_end();
}

static void	test_isprint(void)
{
	int		i;
	int		n_print;
	int		tests_print[] = {0, 9, 10, 13, 31, 32, 33, 'A', 'z', '0', '@', '[',
				'`', '{', 126, 127, 128, 255, -1};
	char	case_name[32];
	int		x;
	int		ft;
	int		ref;
	int		ok;

	t_test_begin("isprint");
	n_print = (int)(sizeof(tests_print) / sizeof(tests_print[0]));
	i = 0;
	while (i < n_print)
	{
		x = tests_print[i];
		ft = ft_isprint(x);
		ref = isprint((unsigned char)x);
		ok = t_same_bool(ft, ref);
		snprintf(case_name, sizeof(case_name), "Caso '%c'", (char)x);
		t_case(ok, case_name);
		if (!ok)
			t_print_int_triplet(x, ft, ref);
		i++;
	}
	t_test_end();
}

void	test_is(void)
{
	test_isalpha();
	test_isdigit();
	test_isalnum();
	test_isascii();
	test_isprint();
}
