/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 13:19:41 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/13 13:29:16 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlen(const char *s);

void	test_ft_strlen(void)
{
	int			i;
	const char	*tests[] = {"", "a", "42urduliz", "a b!@", "qwer\0fd\t:+{}",
			"qwer\nfd\t:+{}"};

	i = 0;
	printf("------ Test strlen ------\n");
	while (i < (int)(sizeof(tests) / sizeof(tests[0])))
	{
		printf("c=%4s -> %ld\n", tests[i], ft_strlen(tests[i]));
		i++;
	}
}
