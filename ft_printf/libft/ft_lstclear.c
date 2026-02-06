/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:03:49 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/27 14:20:25 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parameters
	lst: the address of a pointer to a node.

	del: a pointer to the function used to
	delete the contents of a node.

Description
	Deletes and frees the given node 'lst' and all
	consecutive nodes of the same node, using the 'del' function
	and free(3).

	The pointer to the list must be NULL at the end.
*/

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = next;
	}
}
