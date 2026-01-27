/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:34:41 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/27 14:22:06 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Parameters
	lst: a pointer to a node.
	f: the address of a pointer to a function used
	in the iteration of each element of the list.
	del: a pointer to a function used to remove
	the contents of a node, if necessary.

Description
	Iterates over the list 'lst' and applies the function 'f' to the
	contents of each node. Creates a resulting list
	by successively applying the function 'f' to each
	node. The function 'del' is used to remove
	the contents of a node if necessary.

*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*nnode;
	void	*content;

	if (lst == NULL || !f || !del)
		return (NULL);
	nlst = NULL;
	while (lst)
	{
		content = f(lst->content);
		nnode = ft_lstnew(content);
		if (nnode == NULL)
		{
			del(content);
			ft_lstclear(&nlst, del);
			return (NULL);
		}
		ft_lstadd_back(&nlst, nnode);
		lst = lst->next;
	}
	return (nlst);
}
