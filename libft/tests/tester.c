/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 13:42:13 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/21 15:27:31 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

int	main(void)
{
	t_all_begin();
	test_is();
	test_to();
	test_atoi();
	// test_str();
	// test_mem();
	// test_split();
	return (t_all_end());
}
