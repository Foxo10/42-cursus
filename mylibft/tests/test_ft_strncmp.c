/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:34:09 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/13 17:50:56 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	test_ft_strncmp(void)
{
	int	result;

	printf("------ Test strncmp ------\n");
	// Caso 1: n = 0 (siempre 0)
	result = ft_strncmp("abc", "xyz", (size_t)0);
	printf("s1=%s, s2=%s, n=%zu -> result=%d\n", "abc", "xyz", (size_t)0,
		result);
	// Caso 2: strings iguales (n exacto)
	result = ft_strncmp("42urduliz", "42urduliz", (size_t)9);
	printf("s1=%s, s2=%s, n=%zu -> result=%d\n", "42urduliz", "42urduliz",
		(size_t)9, result);
	// Caso 3: strings iguales (n mayor que longitud)
	result = ft_strncmp("abc", "abc", (size_t)10);
	printf("s1=%s, s2=%s, n=%zu -> result=%d\n", "abc", "abc", (size_t)10,
		result);
	// Caso 4: difieren antes de n
	result = ft_strncmp("abc", "abz", (size_t)3);
	printf("s1=%s, s2=%s, n=%zu -> result=%d\n", "abc", "abz", (size_t)3,
		result);
	// Caso 5: difieren justo en el límite (n=2 igual, n=3 diferente)
	result = ft_strncmp("abC", "abD", (size_t)2);
	printf("s1=%s, s2=%s, n=%zu -> result=%d\n", "abC", "abD", (size_t)2,
		result);
	result = ft_strncmp("abC", "abD", (size_t)3);
	printf("s1=%s, s2=%s, n=%zu -> result=%d\n", "abC", "abD", (size_t)3,
		result);
	// Caso 6: prefijo (una termina antes)
	result = ft_strncmp("ab", "abc", (size_t)3);
	printf("s1=%s, s2=%s, n=%zu -> result=%d\n", "ab", "abc", (size_t)3,
		result);
	result = ft_strncmp("abc", "ab", (size_t)3);
	printf("s1=%s, s2=%s, n=%zu -> result=%d\n", "abc", "ab", (size_t)3,
		result);
	// Caso 7: diferencia por carácter especial / espacio
	result = ft_strncmp("a ", "a!", (size_t)2);
	printf("s1=%s, s2=%s, n=%zu -> result=%d\n", "a ", "a!", (size_t)2, result);
	// Caso 8: comparar cuando hay '\0' dentro (se para en '\0')
	result = ft_strncmp("a\0b", "a\0c", (size_t)3);
	printf("s1=a\\0b, s2=a\\0c, n=%zu -> result=%d\n", (size_t)3, result);
}
