/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:57:42 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/27 14:20:48 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Parameters
	lst: the node to free.

	del: a pointer to the function used to free
	the node's contents.

Description
	Receives an 'lst' node as a parameter and frees the
	memory of its contents using the 'del' function
	given as a parameter. It also frees the node itself
	but does not free the next node.

*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
