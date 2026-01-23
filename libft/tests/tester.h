/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:13:50 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/21 15:36:17 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTER_H
# define TESTER_H

# define C_RESET "\033[0m"
# define C_RED "\033[31m"
# define C_GREEN "\033[32m"
# define C_CYAN "\033[36m"
# define C_BOLD "\033[1m"

# include "../src/libft.h"
# include <ctype.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

void	t_all_begin(void);
int		t_all_end(void);
void	t_test_begin(const char *name);
void	t_test_end(void);
int		t_case(int ok, const char *case_name);
int		t_same_bool(int ft, int ref);
void	t_print_int_triplet(int x, int ft, int ref);

void	test_is(void);
void	test_to(void);
void	test_atoi(void);
// void	test_str(void);
// void	test_mem(void);

#endif
