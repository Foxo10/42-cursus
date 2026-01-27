/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 17:57:42 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/23 14:30:27 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Parámetros
	lst: el nodo a liberar.
	del: un puntero a la función utilizada para liberar
	el contenido del nodo.
Descripción
	Recibe como parámetro un nodo ‘lst’ y libera la
	memoria del contenido utilizando la función ‘del’
	dada como parámetro. También libera el nodo en sí
	mismo, pero no libera el siguiente nodo.
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}
