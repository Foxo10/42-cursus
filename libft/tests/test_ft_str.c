/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:01:14 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/16 15:22:45 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tester.h"

static int	check_and_print_ko_size(const char *name, const char *s, size_t ft,
		size_t ref)
{
	if (ft != ref)
	{
		printf("KO %s s=\"%s\" -> ft=%zu ref=%zu\n", name, s, ft, ref);
		return (1);
	}
	// printf("OK %s s=\"%s\" -> ft=%zu ref=%zu\n", name, s, ft, ref);
	return (0);
}

static int	check_strlcpy_case(const char *case_name, const char *src,
		const char *dst_init, size_t dstsize, const char *expected_dst)
{
	char	dst[32];
	size_t	ret;
	size_t	expected_ret;

	memset(dst, '#', sizeof(dst));
	strncpy(dst, dst_init, sizeof(dst) - 1);
	dst[sizeof(dst) - 1] = '\0';
	ret = ft_strlcpy(dst, src, dstsize);
	expected_ret = strlen(src);
	if (ret != expected_ret || strcmp(dst, expected_dst) != 0)
	{
		printf("KO strlcpy (%s) src=\"%s\" dstsize=%zu"
				"->ft_ret = %zu exp_ret = %zu\n",
				case_name,
				src,
				dstsize,
				ret,
				expected_ret);
		printf("   ft_dst =\"%s\"\n", dst);
		printf("   exp_dst=\"%s\"\n", expected_dst);
		return (1);
	}
	printf("OK strlcpy (%s) src=\"%s\" dstsize=%zu"
			"->ft_ret = %zu exp_ret = %zu\n",
			case_name,
			src,
			dstsize,
			ret,
			expected_ret);
	printf("   ft_dst =\"%s\"\n", dst);
	printf("   exp_dst=\"%s\"\n", expected_dst);
	return (0);
}

int	test_strlen(void)
{
	int			fails_strlen;
	const char	*tests[] = {"", "a", "hello", "42urduliz", "   ", "\t\n"};
	int			i;
	int			n;

	fails_strlen = 0;
	n = (int)(sizeof(tests) / sizeof(tests[0]));
	printf("\n------ Test strlen ------\n");
	i = 0;
	while (i < n)
	{
		fails_strlen += check_and_print_ko_size("strlen", tests[i],
				ft_strlen(tests[i]), strlen(tests[i]));
		i++;
	}
	if (fails_strlen == 0)
		printf("OK: strlen\n");
	return (fails_strlen);
}

int	test_strlcpy(void)
{
	int	fails_strlcpy;

	fails_strlcpy = 0;
	printf("\n------ Test strlcpy ------\n");
	/* dstsize = 0 -> NO cambia dst */
	fails_strlcpy += check_strlcpy_case("dstsize=0 (no cambia dst)",
			"42urduliz", "INIT", 0, "INIT");
	/* dstsize = 1 -> dst = "" */
	fails_strlcpy += check_strlcpy_case("dstsize=1 (solo \\0)", "42", "INIT", 1,
			"");
	/* truncado: dstsize=4 -> "abc" */
	fails_strlcpy += check_strlcpy_case("truncate", "abcdef", "INIT", 4, "abc");
	/* copia completa */
	fails_strlcpy += check_strlcpy_case("full copy", "lorem ipsum", "INIT", 20,
			"lorem ipsum");
	/* src vacío */
	fails_strlcpy += check_strlcpy_case("src empty", "", "INIT", 10, "");
	if (fails_strlcpy == 0)
		printf("OK: strlcpy\n");
	else
		printf("KO: %d mismatches\n", fails_strlcpy);
	return (fails_strlcpy);
}

void	test_str(void)
{
	int	fails;

	fails = 0;
	fails += test_strlen();
	fails += test_strlcpy();
	printf("\n");
	if (fails == 0)
		printf("OK: all str* tests\n");
	else
		printf("KO: %d mismatches total\n", fails);
}
