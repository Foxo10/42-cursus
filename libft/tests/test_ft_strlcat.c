/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 17:16:35 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/13 17:16:45 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);

void	test_ft_strlcat(void)
{
	char	dst[20];
	size_t	result;

	printf("------ Test strlcat ------\n");
	// Caso 1: dstsize = 0 (NO debería modificar dst)
	strcpy(dst, "asdfmovie");
	result = ft_strlcat(dst, "42", (size_t)0);
	printf("src=%s, dst=%s, %zu -> \n", "42", "asdfmovie", (size_t)0);
	printf("dst=%s | result=%zu | size_dst=%zu | size_src=%zu\n", dst, result,
		ft_strlen("asdfmovie"), ft_strlen("42"));
	// Caso 2: src vacío (dst no cambia)
	strcpy(dst, "42urduliz");
	result = ft_strlcat(dst, "", (size_t)20);
	printf("src=%s, dst=%s, %zu -> \n", "", "42urduliz", (size_t)20);
	printf("dst=%s | result=%zu | size_dst=%zu | size_src=%zu\n", dst, result,
		ft_strlen("42urduliz"), ft_strlen(""));
	// Caso 3: dst vacío (equivalente a copiar src si hay espacio)
	strcpy(dst, "");
	result = ft_strlcat(dst, "World!", (size_t)20);
	printf("src=%s, dst=%s, %zu -> \n", "World!", "", (size_t)20);
	printf("dst=%s | result=%zu | size_dst=%zu | size_src=%zu\n", dst, result,
		ft_strlen(""), ft_strlen("World!"));
	// Caso 4: copia completa (hay espacio suficiente para concatenar todo)
	strcpy(dst, "as");
	result = ft_strlcat(dst, "df", (size_t)20);
	printf("src=%s, dst=%s, %zu -> \n", "df", "as", (size_t)20);
	printf("dst=%s | result=%zu | size_dst=%zu | size_src=%zu\n", dst, result,
		ft_strlen("as"), ft_strlen("df"));
	// Caso 5: truncado (dstsize pequeño, concatena parcialmente)
	// dst="asdfmovie" (8) y dstsize=10 -> solo caben 1 char + '\0'
	strcpy(dst, "asdfmovie");
	result = ft_strlcat(dst, "42urduliz", (size_t)10);
	printf("src=%s, dst=%s, %zu -> \n", "42urduliz", "asdfmovie", (size_t)10);
	printf("dst=%s | result=%zu | size_dst=%zu | size_src=%zu\n", dst, result,
		ft_strlen("asdfmovie"), ft_strlen("42urduliz"));
	// Caso 6: dstsize = strlen(dst) + 1 (no puede añadir nada, pero es válido)
	strcpy(dst, "asdfmovie");
	result = ft_strlcat(dst, "42", (size_t)9);
	printf("src=%s, dst=%s, %zu -> \n", "42", "asdfmovie", (size_t)9);
	printf("dst=%s | result=%zu | size_dst=%zu | size_src=%zu\n", dst, result,
		ft_strlen("asdfmovie"), ft_strlen("42"));
	// Caso 7: dstsize <= strlen(dst) (NO añade nada, retorno especial)
	strcpy(dst, "asdfmovie");
	result = ft_strlcat(dst, "42", (size_t)5);
	printf("src=%s, dst=%s, %zu -> \n", "42", "asdfmovie", (size_t)5);
	printf("dst=%s | result=%zu | size_dst=%zu | size_src=%zu\n", dst, result,
		ft_strlen("asdfmovie"), ft_strlen("42"));
}
