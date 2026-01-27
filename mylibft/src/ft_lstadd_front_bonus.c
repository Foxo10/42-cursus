/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:27:04 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/23 13:22:21 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Parámetros
	lst: la dirección de memoria de un puntero al
	primer nodo de una lista.
	new: un puntero al nodo que se añade al principio
	de la lista.
Descripción
	Añade el nodo ‘new’ al principio de la lista ‘lst’.

New pasa a apuntar al primer elemento de la linked list.
El head pasa a apuntar a new

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
