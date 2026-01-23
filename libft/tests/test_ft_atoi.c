/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_atoi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 15:31:50 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/21 15:36:34 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

void	test_atoi(void)
{
	int		i;
	int		n;
	char	case_name[64];
	int		ft;
	int		ref;
	int		ok;

	const char *tests[] = {
		"",          /* vacío */
		"0",         /* cero */
		"42",        /* normal */
		"-42",       /* negativo */
		"+42",       /* positivo con + */
		"   42",     /* espacios delante */
		"\t\n  -42", /* whitespace mixto */
		"00042",     /* ceros delante */
		"-00042",    /* signo + ceros */
		"42abc",     /* corta al no-dígito */
		"   42abc",  /* spaces + corta */
		"abc42",     /* empieza no numérico -> 0 */
		"+",         /* solo signo -> 0 */
		"-",         /* solo signo -> 0 */
		"   ",       /* solo espacios -> 0 */
		"  + 42",    /* signo separado -> 0 */
		"--42",      /* doble signo -> 0 */
		"+-42"       /* signos raros -> 0 */
	};
	t_test_begin("atoi");
	n = (int)(sizeof(tests) / sizeof(tests[0]));
	i = 0;
	while (i < n)
	{
		snprintf(case_name, sizeof(case_name), "Caso \"%s\"", tests[i]);
		ft = ft_atoi(tests[i]);
		ref = atoi(tests[i]);
		ok = (ft == ref);
		t_case(ok, case_name);
		if (!ok)
			printf("   s=\"%s\" ft=%d ref=%d\n", tests[i], ft, ref);
		i++;
	}
	t_test_end();
}
