/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:03:49 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/23 13:22:19 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Parámetros
	lst: la dirección de un puntero a un nodo.
	del: un puntero a la función utilizado para
	eliminar el contenido de un nodo.
Descripción
	Elimina y libera el nodo ‘lst’ dado y todos los
	consecutivos del mismo, utilizando la función ‘del’
	y free(3).
	Al final, el puntero a la lista debe ser NULL.
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
