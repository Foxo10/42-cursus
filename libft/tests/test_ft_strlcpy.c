/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 14:07:36 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/13 17:13:08 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);

void	test_ft_strlcpy(void)
{
	char	dst[10];
	size_t	result;

	printf("------ Test strlcpy ------\n");
	// Caso 1: dstsize = 0 (NO debería modificar dst)
	strcpy(dst, "asdfmovie");
	result = ft_strlcpy(dst, "42urduliz", (size_t)0);
	printf("src=%s, dst=%s, %zu -> \n", "42urduliz", "asdfmovie", (size_t)0);
	printf("dst=%s | result=%zu | size_src=%zu \n", dst, result,
		ft_strlen("42urduliz"));
	// Caso 2: src vacío (dst se vuelve "")
	strcpy(dst, "42urduliz");
	result = ft_strlcpy(dst, "", (size_t)9);
	printf("src=%s, dst=%s, %zu -> \n", "", "42urduliz", (size_t)9);
	printf("dst=%s | result=%zu | size_src=%zu \n", dst, result, ft_strlen(""));
	// Caso 3: dstsize = 1 (copia 0 chars y mete '\0')
	strcpy(dst, "asdfmovie");
	result = ft_strlcpy(dst, "ab", (size_t)1);
	printf("src=%s, dst=%s, %zu -> \n", "ab", "asdfmovie", (size_t)1);
	printf("dst=%s | result=%zu | size_src=%zu \n", dst, result,
		ft_strlen("ab"));
	// Caso 4: copia completa (cabe entero)
	strcpy(dst, "asdfmovie");
	result = ft_strlcpy(dst, "World!", (size_t)10);
	printf("src=%s, dst=%s, %zu -> \n", "World!", "asdfmovie", (size_t)10);
	printf("dst=%s | result=%zu | size_src=%zu \n", dst, result,
		ft_strlen("World!"));
	// Caso 5: truncado (dstsize menor que strlen(src)+1)
	strcpy(dst, "asdfmovie");
	result = ft_strlcpy(dst, "Hello, World!", (size_t)10);
	printf("src=%s, dst=%s, %zu -> \n", "Hello, World!", "asdfmovie",
		(size_t)10);
	printf("dst=%s | result=%zu | size_src=%zu \n", dst, result,
		ft_strlen("Hello, World!"));
}
