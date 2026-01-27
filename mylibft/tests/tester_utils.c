/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 15:13:05 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/20 16:47:41 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static int			g_total_fails;
static int			g_test_fails;
static const char	*g_test_name;

void	t_all_begin(void)
{
	g_total_fails = 0;
	g_test_fails = 0;
	g_test_name = NULL;
}

int	t_all_end(void)
{
	printf("\n");
	if (g_total_fails == 0)
		printf(C_BOLD C_GREEN "ALL TESTS OK\n" C_RESET);
	else
		printf(C_BOLD C_RED "SOME TESTS KO (%d fails)\n" C_RESET,
			g_total_fails);
	return (g_total_fails);
}

void	t_test_begin(const char *name)
{
	g_test_name = name;
	g_test_fails = 0;
	printf("\n" C_CYAN "------ %s ------\n" C_RESET, name);
}

void	t_test_end(void)
{
	if (g_test_fails == 0)
		printf(C_GREEN "OK: %s\n" C_RESET, g_test_name);
	else
		printf(C_RED "KO: %s (%d fails)\n" C_RESET, g_test_name, g_test_fails);
	g_total_fails += g_test_fails;
}

int	t_case(int ok, const char *case_name)
{
	if (ok)
		printf(C_GREEN "[OK] " C_RESET "%s\n", case_name);
	else
	{
		printf(C_RED "[KO] " C_RESET "%s\n", case_name);
		g_test_fails++;
	}
	return (!ok);
}

/* para ctype: solo importa 0 vs no-0 */
int	t_same_bool(int ft, int ref)
{
	return ((ft == 0) == (ref == 0));
}

/* opcional: helper para imprimir x/ft/ref en KO */
void	t_print_int_triplet(int x, int ft, int ref)
{
	printf("   x=%d ft=%d ref=%d\n", x, ft, ref);
}
