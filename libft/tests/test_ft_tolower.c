/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 18:40:18 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/13 18:40:41 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_tolower(int c);

void	test_ft_tolower(void)
{
	int	tests[] = {'a', 'z', 'm', 'A', 'Z', 'M', '0', '9', '-', ' ', '\n', '\t',
			'\0', 31, 127, 128, -1};
	int	i;
	int	out;

	printf("------ Test tolower ------\n");
	i = 0;
	while (i < (int)(sizeof(tests) / sizeof(tests[0])))
	{
		out = ft_tolower(tests[i]);
		printf("in=%c", (char)tests[i]);
		printf(" (%d) -> out=%c (%d)\n", tests[i], (char)out, out);
		i++;
	}
}
