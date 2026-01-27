/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:08:35 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/27 14:22:58 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Parameters
	content: The content with which the node is created.

Return value:
	A pointer to the new node

Description
	Allocates memory (using malloc(3)) and returns a
	new node. The variable ‘content’ is initialized with
	the content of the parameter ‘content’. While
	the variable ‘next’ is initialized with NULL.

*/

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node)
	{
		node->content = content;
		node->next = NULL;
	}
	return (node);
}
