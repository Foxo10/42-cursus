/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 16:09:39 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/28 11:15:29 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>
#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// cc -Wall -Wextra -Werror -I. main.c libft.a -lbsd -o tester
// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./tester
static long	idx_or_minus1(const char *s, const char *p)
{
	long	idx;

	if (p == NULL)
		return (-1);
	idx = (long)(p - s);
	return (idx);
}

static void	print_bytes_8(const unsigned char *b)
{
	printf("%02X %02X %02X %02X %02X %02X %02X %02X\n", b[0], b[1], b[2], b[3],
		b[4], b[5], b[6], b[7]);
}

static void	print_list_str(t_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		printf("  [%d] \"%s\"\n", i, (char *)lst->content);
		lst = lst->next;
		i++;
	}
	printf("  [end] NULL\n");
}

static void	del_content(void *p)
{
	if (p != NULL)
		free(p);
}
static void	manual_clear(t_list **lst)
{
	t_list	*next;

	if (lst == NULL)
		return ;
	while (*lst != NULL)
	{
		next = (*lst)->next;
		del_content((*lst)->content);
		free(*lst);
		*lst = next;
	}
}

void	ft_test_is(void)
{
	int	tests_isalpha[] = {'A', 'Z', 'a', 'z', '0', '@', '[', '`', '{', -1};
	int	tests_isdigit[] = {'0', '5', '9', '/', ':', 'a', ' ', '\n', 127, -42};
	int	tests_isalnum[] = {'A', 'z', '0', '9', '@', '[', '`', '{', 127, -1};
	int	tests_isascii[] = {0, 1, 31, 32, 126, 127, 128, 255, -1, -42};
	int	tests_isprint[] = {31, 32, 33, 'A', 'z', '0', 126, 127, '\n', -1};
	int	i;
	int	c;

	printf("\n================ GRUPO: is ================\n");
	printf("isalpha:\n");
	i = 0;
	while (i < 10)
	{
		c = tests_isalpha[i];
		printf("c=%4d | ft=%d | libc=%d\n", c, ft_isalpha(c),
			isalpha((unsigned char)c));
		i++;
	}
	printf("\nisdigit:\n");
	i = 0;
	while (i < 10)
	{
		c = tests_isdigit[i];
		printf("c=%4d | ft=%d | libc=%d\n", c, ft_isdigit(c),
			isdigit((unsigned char)c));
		i++;
	}
	printf("\nisalnum:\n");
	i = 0;
	while (i < 10)
	{
		c = tests_isalnum[i];
		printf("c=%4d | ft=%d | libc=%d\n", c, ft_isalnum(c),
			isalnum((unsigned char)c));
		i++;
	}
	printf("\nisascii:\n");
	i = 0;
	while (i < 10)
	{
		c = tests_isascii[i];
		printf("c=%4d | ft=%d | libc=%d\n", c, ft_isascii(c),
			isascii((unsigned char)c));
		i++;
	}
	printf("\nisprint:\n");
	i = 0;
	while (i < 10)
	{
		c = tests_isprint[i];
		printf("c=%4d | ft=%d | libc=%d\n", c, ft_isprint(c),
			isprint((unsigned char)c));
		i++;
	}
}

void	ft_test_to(void)
{
	int	tests_toupper[] = {'a', 'z', 'm', 'A', 'Z', '0', '@', '[', '{', -1};
	int	tests_tolower[] = {'A', 'Z', 'M', 'a', 'z', '0', '@', '[', '{', -1};
	int	i;
	int	c;

	printf("\n================ GRUPO: to ================\n");
	printf("toupper:\n");
	i = 0;
	while (i < 10)
	{
		c = tests_toupper[i];
		printf("c=%4d | ft=%4d | libc=%4d\n", c, ft_toupper(c), toupper(c));
		i++;
	}
	printf("\ntolower:\n");
	i = 0;
	while (i < 10)
	{
		c = tests_tolower[i];
		printf("c=%4d | ft=%4d | libc=%4d\n", c, ft_tolower(c), tolower(c));
		i++;
	}
}

void	ft_test_atoi(void)
{
	int	i;

	const char *tests[] = {
		"", /* empty */
		"0",
		"   42", /* leading spaces */
		"   -42",
		"+123",
		"000123", /* leading zeros */
		"42abc",  /* stops at non-digit */
		"abc42",  /* starts with non-digit */
		"--42",   /* double sign */
		"+-42"    /* mixed signs */
	};
	printf("atoi:\n");
	i = 0;
	while (i < 10)
	{
		printf("s=\"%s\" | ft=%d | libc=%d\n", tests[i], ft_atoi(tests[i]),
			atoi(tests[i]));
		i++;
	}
}

void	ft_test_str(void)
{
	char	dst_ft[20];
	char	dst_ref[20];
	size_t	r_ft;
	size_t	r_rf;

	printf("\n================ GRUPO: str ================\n");
	/* ===================== strlen ===================== */
	printf("strlen:\n");
	printf("s=\"\" | ft=%zu | libc=%zu\n", ft_strlen(""), strlen(""));
	printf("s=\"a\" | ft=%zu | libc=%zu\n", ft_strlen("a"), strlen("a"));
	printf("s=\"42\" | ft=%zu | libc=%zu\n", ft_strlen("42"), strlen("42"));
	printf("s=\"lorem\" | ft=%zu | libc=%zu\n", ft_strlen("lorem"),
		strlen("lorem"));
	printf("s=\"lorem ipsum\" | ft=%zu | libc=%zu\n", ft_strlen("lorem ipsum"),
		strlen("lorem ipsum"));
	printf("s=\"0123456789\" | ft=%zu | libc=%zu\n", ft_strlen("0123456789"),
		strlen("0123456789"));
	/* ===================== strlcpy ===================== */
	printf("\nstrlcpy:\n");
	{
		strcpy(dst_ft, "ORIG");
		strcpy(dst_ref, "ORIG");
		r_ft = ft_strlcpy(dst_ft, "42urduliz", 0);
		r_rf = strlcpy(dst_ref, "42urduliz", 0);
		printf("src=\"42urduliz\" size=0 | ft_ret=%zu ref_ret=%zu | ft_dst=\"%s\" ref_dst=\"%s\"\n",
			r_ft, r_rf, dst_ft, dst_ref);
		strcpy(dst_ft, "ORIG");
		strcpy(dst_ref, "ORIG");
		r_ft = ft_strlcpy(dst_ft, "HelloWorld", 1);
		r_rf = strlcpy(dst_ref, "HelloWorld", 1);
		printf("src=\"HelloWorld\" size=1 | ft_ret=%zu ref_ret=%zu | ft_dst=\"%s\" ref_dst=\"%s\"\n",
			r_ft, r_rf, dst_ft, dst_ref);
		strcpy(dst_ft, "ORIG");
		strcpy(dst_ref, "ORIG");
		r_ft = ft_strlcpy(dst_ft, "HelloWorld", 5);
		r_rf = strlcpy(dst_ref, "HelloWorld", 5);
		printf("src=\"HelloWorld\" size=5 | ft_ret=%zu ref_ret=%zu | ft_dst=\"%s\" ref_dst=\"%s\"\n",
			r_ft, r_rf, dst_ft, dst_ref);
		strcpy(dst_ft, "ORIG");
		strcpy(dst_ref, "ORIG");
		r_ft = ft_strlcpy(dst_ft, "HelloWorld", 11);
		r_rf = strlcpy(dst_ref, "HelloWorld", 11);
		printf("src=\"HelloWorld\" size=11 | ft_ret=%zu ref_ret=%zu | ft_dst=\"%s\" ref_dst=\"%s\"\n",
			r_ft, r_rf, dst_ft, dst_ref);
		strcpy(dst_ft, "ORIG");
		strcpy(dst_ref, "ORIG");
		r_ft = ft_strlcpy(dst_ft, "", 5);
		r_rf = strlcpy(dst_ref, "", 5);
		printf("src=\"\" size=5 | ft_ret=%zu ref_ret=%zu | ft_dst=\"%s\" ref_dst=\"%s\"\n",
			r_ft, r_rf, dst_ft, dst_ref);
		strcpy(dst_ft, "ORIG");
		strcpy(dst_ref, "ORIG");
		r_ft = ft_strlcpy(dst_ft, "ABC", 2);
		r_rf = strlcpy(dst_ref, "ABC", 2);
		printf("src=\"ABC\" size=2 | ft_ret=%zu ref_ret=%zu | ft_dst=\"%s\" ref_dst=\"%s\"\n",
			r_ft, r_rf, dst_ft, dst_ref);
	}
	/* ===================== strlcat ===================== */
	printf("\nstrlcat:\n");
	{
		strcpy(dst_ft, "HOLA");
		strcpy(dst_ref, "HOLA");
		r_ft = ft_strlcat(dst_ft, " MUNDO", 3);
		r_rf = strlcat(dst_ref, " MUNDO", 3);
		printf("dst=\"HOLA\" src=\" MUNDO\" size=3 | ft_ret=%zu ref_ret=%zu | ft_dst=\"%s\" ref_dst=\"%s\"\n",
			r_ft, r_rf, dst_ft, dst_ref);
		strcpy(dst_ft, "");
		strcpy(dst_ref, "");
		r_ft = ft_strlcat(dst_ft, "MUNDO", 4);
		r_rf = strlcat(dst_ref, "MUNDO", 4);
		printf("dst=\"\" src=\"MUNDO\" size=4 | ft_ret=%zu ref_ret=%zu | ft_dst=\"%s\" ref_dst=\"%s\"\n",
			r_ft, r_rf, dst_ft, dst_ref);
		strcpy(dst_ft, "Hi");
		strcpy(dst_ref, "Hi");
		r_ft = ft_strlcat(dst_ft, "1234", 10);
		r_rf = strlcat(dst_ref, "1234", 10);
		printf("dst=\"Hi\" src=\"1234\" size=10 | ft_ret=%zu ref_ret=%zu | ft_dst=\"%s\" ref_dst=\"%s\"\n",
			r_ft, r_rf, dst_ft, dst_ref);
		strcpy(dst_ft, "ABC");
		strcpy(dst_ref, "ABC");
		r_ft = ft_strlcat(dst_ft, "DEF", 0);
		r_rf = strlcat(dst_ref, "DEF", 0);
		printf("dst=\"ABC\" src=\"DEF\" size=0 | ft_ret=%zu ref_ret=%zu | ft_dst=\"%s\" ref_dst=\"%s\"\n",
			r_ft, r_rf, dst_ft, dst_ref);
		strcpy(dst_ft, "ABC");
		strcpy(dst_ref, "ABC");
		r_ft = ft_strlcat(dst_ft, "DEF", 6);
		r_rf = strlcat(dst_ref, "DEF", 6);
		printf("dst=\"ABC\" src=\"DEF\" size=6 | ft_ret=%zu ref_ret=%zu | ft_dst=\"%s\" ref_dst=\"%s\"\n",
			r_ft, r_rf, dst_ft, dst_ref);
		strcpy(dst_ft, "12345");
		strcpy(dst_ref, "12345");
		r_ft = ft_strlcat(dst_ft, "ZZZ", 5);
		r_rf = strlcat(dst_ref, "ZZZ", 5);
		printf("dst=\"12345\" src=\"ZZZ\" size=5 | ft_ret=%zu ref_ret=%zu | ft_dst=\"%s\" ref_dst=\"%s\"\n",
			r_ft, r_rf, dst_ft, dst_ref);
	}
	/* ===================== strncmp ===================== */
	printf("\nstrncmp:\n");
	printf("a=\"abc\" b=\"abc\" n=0 | ft=%d | libc=%d\n", ft_strncmp("abc",
			"abc", 0), strncmp("abc", "abc", 0));
	printf("a=\"abc\" b=\"abc\" n=3 | ft=%d | libc=%d\n", ft_strncmp("abc",
			"abc", 3), strncmp("abc", "abc", 3));
	printf("a=\"abc\" b=\"abd\" n=3 | ft=%d | libc=%d\n", ft_strncmp("abc",
			"abd", 3), strncmp("abc", "abd", 3));
	printf("a=\"abc\" b=\"ab\" n=3 | ft=%d | libc=%d\n", ft_strncmp("abc", "ab",
			3), strncmp("abc", "ab", 3));
	printf("a=\"ab\" b=\"abc\" n=3 | ft=%d | libc=%d\n", ft_strncmp("ab", "abc",
			3), strncmp("ab", "abc", 3));
	printf("a=\"abc\" b=\"abcX\" n=10 | ft=%d | libc=%d\n", ft_strncmp("abc",
			"abcX", 10), strncmp("abc", "abcX", 10));
	printf("a=\"abc\" b=\"abD\" n=2 | ft=%d | libc=%d\n", ft_strncmp("abc",
			"abD", 2), strncmp("abc", "abD", 2));
	printf("a=\"a\\0z\" b=\"a\\0y\" n=3 | ft=%d | libc=%d\n", ft_strncmp("a\0z",
			"a\0y", 3), strncmp("a\0z", "a\0y", 3));
	/* ===================== strchr ===================== */
	printf("\nstrchr:\n");
	printf("s=\"abcde\" c='a' | ft_idx=%ld | libc_idx=%ld\n",
		idx_or_minus1("abcde", ft_strchr("abcde", 'a')), idx_or_minus1("abcde",
			strchr("abcde", 'a')));
	printf("s=\"abcde\" c='e' | ft_idx=%ld | libc_idx=%ld\n",
		idx_or_minus1("abcde", ft_strchr("abcde", 'e')), idx_or_minus1("abcde",
			strchr("abcde", 'e')));
	printf("s=\"abcde\" c='z' | ft_idx=%ld | libc_idx=%ld\n",
		idx_or_minus1("abcde", ft_strchr("abcde", 'z')), idx_or_minus1("abcde",
			strchr("abcde", 'z')));
	printf("s=\"abcde\" c='\\0' | ft_idx=%ld | libc_idx=%ld\n",
		idx_or_minus1("abcde", ft_strchr("abcde", '\0')), idx_or_minus1("abcde",
			strchr("abcde", '\0')));
	printf("s=\"abcde\" c='b' | ft_idx=%ld | libc_idx=%ld\n",
		idx_or_minus1("abcde", ft_strchr("abcde", 'b')), idx_or_minus1("abcde",
			strchr("abcde", 'b')));
	printf("s=\"abcde\" c='d' | ft_idx=%ld | libc_idx=%ld\n",
		idx_or_minus1("abcde", ft_strchr("abcde", 'd')), idx_or_minus1("abcde",
			strchr("abcde", 'd')));
	printf("s=\"abcde\" c='c' | ft_idx=%ld | libc_idx=%ld\n",
		idx_or_minus1("abcde", ft_strchr("abcde", 'c')), idx_or_minus1("abcde",
			strchr("abcde", 'c')));
	/* ===================== strrchr ===================== */
	printf("\nstrrchr:\n");
	printf("s=\"abbcccbba\" c='a' | ft_idx=%ld | libc_idx=%ld\n",
		idx_or_minus1("abbcccbba", ft_strrchr("abbcccbba", 'a')),
		idx_or_minus1("abbcccbba", strrchr("abbcccbba", 'a')));
	printf("s=\"abbcccbba\" c='z' | ft_idx=%ld | libc_idx=%ld\n",
		idx_or_minus1("abbcccbba", ft_strrchr("abbcccbba", 'z')),
		idx_or_minus1("abbcccbba", strrchr("abbcccbba", 'z')));
	printf("s=\"abbcccbba\" c='\\0' | ft_idx=%ld | libc_idx=%ld\n",
		idx_or_minus1("abbcccbba", ft_strrchr("abbcccbba", '\0')),
		idx_or_minus1("abbcccbba", strrchr("abbcccbba", '\0')));
	printf("s=\"abbcccbba\" c='b' | ft_idx=%ld | libc_idx=%ld\n",
		idx_or_minus1("abbcccbba", ft_strrchr("abbcccbba", 'b')),
		idx_or_minus1("abbcccbba", strrchr("abbcccbba", 'b')));
	printf("s=\"abbcccbba\" c='c' | ft_idx=%ld | libc_idx=%ld\n",
		idx_or_minus1("abbcccbba", ft_strrchr("abbcccbba", 'c')),
		idx_or_minus1("abbcccbba", strrchr("abbcccbba", 'c')));
	printf("s=\"abbaccc\" c='a' | ft_idx=%ld | libc_idx=%ld\n",
		idx_or_minus1("abbaccc", ft_strrchr("abbaccc", 'a')),
		idx_or_minus1("abbaccc", strrchr("abbaccc", 'a')));
	printf("s=\"abbccc\" c='a' | ft_idx=%ld | libc_idx=%ld\n",
		idx_or_minus1("abbccc", ft_strrchr("abbccc", 'a')),
		idx_or_minus1("abbccc", strrchr("abbccc", 'a')));
	/* ===================== strnstr ===================== */
	printf("\nstrnstr:\n");
	printf("big=\"lorem ipsum dolor sit amet\" little=\"ipsum\" len=25 | ft_idx=%ld | bsd_idx=%ld\n",
		idx_or_minus1("lorem ipsum dolor sit amet",
			ft_strnstr("lorem ipsum dolor sit amet", "ipsum", 25)),
		idx_or_minus1("lorem ipsum dolor sit amet",
			strnstr("lorem ipsum dolor sit amet", "ipsum", 25)));
	printf("big=\"lorem ipsum dolor sit amet\" little=\"ipsum\" len=5 | ft_idx=%ld | bsd_idx=%ld\n",
		idx_or_minus1("lorem ipsum dolor sit amet",
			ft_strnstr("lorem ipsum dolor sit amet", "ipsum", 5)),
		idx_or_minus1("lorem ipsum dolor sit amet",
			strnstr("lorem ipsum dolor sit amet", "ipsum", 5)));
	printf("big=\"lorem ipsum dolor sit amet\" little=\"\" len=0 | ft_idx=%ld | bsd_idx=%ld\n",
		idx_or_minus1("lorem ipsum dolor sit amet",
			ft_strnstr("lorem ipsum dolor sit amet", "", 0)),
		idx_or_minus1("lorem ipsum dolor sit amet",
			strnstr("lorem ipsum dolor sit amet", "", 0)));
	printf("big=\"lorem ipsum\" little=\"lorem\" len=5 | ft_idx=%ld | bsd_idx=%ld\n",
		idx_or_minus1("lorem ipsum", ft_strnstr("lorem ipsum", "lorem", 5)),
		idx_or_minus1("lorem ipsum", strnstr("lorem ipsum", "lorem", 5)));
	printf("big=\"lorem ipsum\" little=\"ipsum\" len=11 | ft_idx=%ld | bsd_idx=%ld\n",
		idx_or_minus1("lorem ipsum", ft_strnstr("lorem ipsum", "ipsum", 11)),
		idx_or_minus1("lorem ipsum", strnstr("lorem ipsum", "ipsum", 11)));
	printf("big=\"\" little=\"a\" len=1 | ft_idx=%ld | bsd_idx=%ld\n",
		idx_or_minus1("", ft_strnstr("", "a", 1)), idx_or_minus1("", strnstr("",
				"a", 1)));
	printf("big=\"abc\" little=\"abcd\" len=10 | ft_idx=%ld | bsd_idx=%ld\n",
		idx_or_minus1("abc", ft_strnstr("abc", "abcd", 10)),
		idx_or_minus1("abc", strnstr("abc", "abcd", 10)));
}

void	ft_test_alloc(void)
{
	int				*fti;
	int				*lci;
	unsigned char	*ftuc;
	unsigned char	*lcuc;
	char			*ftc;
	char			*lcc;

	/* ===================== calloc ===================== */
	printf("\n================ GRUPO: alloc ================\n");
	printf("calloc:\n");
	{
		printf("[CASE] calloc 5 ints\n");
		fti = (int *)ft_calloc(5, sizeof(int));
		lci = (int *)calloc(5, sizeof(int));
		printf("ft ptr=%p | values=[%d %d %d %d %d]\n", (void *)fti, fti[0],
			fti[1], fti[2], fti[3], fti[4]);
		printf("lc ptr=%p | values=[%d %d %d %d %d]\n", (void *)lci, lci[0],
			lci[1], lci[2], lci[3], lci[4]);
		free(fti);
		free(lci);
	}
	{
		printf("\n[CASE] calloc 8 bytes\n");
		ftuc = (unsigned char *)ft_calloc(8, 1);
		lcuc = (unsigned char *)calloc(8, 1);
		printf("ft ptr=%p | bytes=%02X %02X %02X %02X %02X %02X %02X %02X\n",
			(void *)ftuc, ftuc[0], ftuc[1], ftuc[2], ftuc[3], ftuc[4], ftuc[5],
			ftuc[6], ftuc[7]);
		printf("lc ptr=%p | bytes=%02X %02X %02X %02X %02X %02X %02X %02X\n",
			(void *)lcuc, lcuc[0], lcuc[1], lcuc[2], lcuc[3], lcuc[4], lcuc[5],
			lcuc[6], lcuc[7]);
		free(ftuc);
		free(lcuc);
	}
	/* ===================== strdup ===================== */
	printf("\nstrdup:\n");
	{
		printf("[CASE] s=\"\"\n");
		ftc = ft_strdup("");
		lcc = strdup("");
		printf("ft=\"%s\" | lc=\"%s\"\n", ftc, lcc);
		free(ftc);
		free(lcc);
	}
	{
		printf("\n[CASE] s=\"42urduliz\"\n");
		ftc = ft_strdup("42urduliz");
		lcc = strdup("42urduliz");
		printf("ft=\"%s\" | lc=\"%s\"\n", ftc, lcc);
		free(ftc);
		free(lcc);
	}
	{
		printf("\n[CASE] s=\"lorem ipsum dolor sit amet\"\n");
		ftc = ft_strdup("lorem ipsum dolor sit amet");
		lcc = strdup("lorem ipsum dolor sit amet");
		printf("ft=\"%s\" | lc=\"%s\"\n", ftc, lcc);
		free(ftc);
		free(lcc);
	}
}

void	ft_test_mem(void)
{
	unsigned char	ftb[8];
	unsigned char	lcb[8];

	printf("\n================ GRUPO: mem ================\n");
	/* ===================== bzero ===================== */
	printf("bzero:\n");
	{
		memset(ftb, 'X', 8);
		memset(lcb, 'X', 8);
		ft_bzero(ftb, 4);
		bzero(lcb, 4);
		printf("[CASE] bzero 4 bytes of \"XXXXXXXX\" (8 bytes)\n");
		printf("ft : ");
		print_bytes_8(ftb);
		printf("lc : ");
		print_bytes_8(lcb);
		printf("memcmp(ft, lc)=%d\n", memcmp(ftb, lcb, 8));
	}
	/* ===================== memset ===================== */
	printf("\nmemset:\n");
	{
	}
	/* ===================== memcpy ===================== */
	printf("\nmemcpy:\n");
	{
	}
	/* ===================== memmove (overlap) ===================== */
	printf("\nmemmove:\n");
	{
	}
	/* ===================== memchr ===================== */
	printf("\nmemchr:\n");
	{
	}
	/* ===================== memcmp ===================== */
	printf("\nmemcmp:\n");
}

void	ft_test_lst(void)
{
	t_list	*lst;
	t_list	*n1;
	t_list	*n2;
	char	*c;

	printf("\n================ lst ================\n");
	/* ================= ft_lstnew ================= */
	printf("\nft_lstnew:\n");
	{
		c = strdup("A");
		lst = ft_lstnew(c);
		printf("[CASE] new(\"A\")\n");
		printf("node_ptr=%p (expected not NULL)\n", (void *)lst);
		if (lst != NULL)
			print_list_str(lst);
		manual_clear(&lst);
	}
	/* ================= ft_lstadd_front ================= */
	printf("\nft_lstadd_front:\n");
	{
		lst = NULL;
		n1 = ft_lstnew(strdup("B"));
		n2 = ft_lstnew(strdup("C"));
		ft_lstadd_front(&lst, n2);
		ft_lstadd_front(&lst, n1);
		printf("[CASE] start NULL, add_front \"C\", add_front \"B\"\n");
		print_list_str(lst);
		printf("expected order:\n  [0] \"B\"\n  [1] \"C\"\n");
		manual_clear(&lst);
		lst = NULL;
		n1 = ft_lstnew(strdup("A"));
		ft_lstadd_front(&lst, n1);
		printf("\n[CASE] add_front on empty list \"A\"\n");
		print_list_str(lst);
		printf("expected order:\n  [0] \"A\"\n");
		manual_clear(&lst);
	}
	printf("\nft_lstsize:\n");
	{
		lst = NULL;
		printf("[CASE] size(NULL) = %d (expected 0)\n", ft_lstsize(lst));
		ft_lstadd_front(&lst, ft_lstnew(strdup("A")));
		ft_lstadd_front(&lst, ft_lstnew(strdup("B")));
		ft_lstadd_front(&lst, ft_lstnew(strdup("C")));
		printf("[CASE] size(3 nodes) = %d (expected 3)\n", ft_lstsize(lst));
		print_list_str(lst);
		manual_clear(&lst);
	}
}

int	main(void)
{
	ft_test_is();
	ft_test_to();
	ft_test_str();
	printf("\n================ GRUPO: atoitoa ================\n");
	ft_test_atoi();
	ft_test_alloc();
	ft_test_mem();
	ft_test_lst();
	return (0);
}
