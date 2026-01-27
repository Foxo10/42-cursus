/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:08:35 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/01/23 14:40:18 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Parámetros
	content: el contenido con el que se crea el nodo.
	Valor devuelto Un puntero al nuevo nodo
Descripción
	Reserva memoria (usando malloc(3)) y devuelve un
	nuevo nodo. La variable ‘content’ se inicializa con
	el contenido del parámetro ‘content’. Mientras que
	la variable ‘next’ se inicializa con NULL.
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
