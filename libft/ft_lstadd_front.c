/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:27:04 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/27 14:19:57 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Parameters
	lst: the memory address of a pointer to the
	first node of a list.

	new: a pointer to the node to be added to the beginning
	of the list.

Description

	Adds the node 'new' to the beginning of the list 'lst'.
	New becomes a pointer to the first element of the linked list.
	The head becomes a pointer to new.

new, lst->[t1 -> t2 -> t3]

lst->[new -> t1 -> t2 -> t3]

*/

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
