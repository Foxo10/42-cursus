/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:34:41 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/23 13:23:17 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Parámetros
	lst: un puntero a un nodo.
	f: la dirección de un puntero a una función usada
	en la iteración de cada elemento de la lista.
	del: un puntero a función utilizado para eliminar
	el contenido de un nodo, si es necesario.
Descripción
	Itera la lista ‘lst’ y aplica la función ‘f’ al
	contenido de cada nodo. Crea una lista resultante
	de aplicar sucesivamente la función ‘f’ a cada
	nodo. La función ‘del’ se utiliza para eliminar
	el contenido de un nodo si es necesario.
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
