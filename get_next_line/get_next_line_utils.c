/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:37:37 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/02/10 19:54:47 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_buffer	*ft_create_node(char *buffer, int bytes_read)
{
	t_buffer	*node;
	int			i;

	node = (t_buffer *)malloc(sizeof(t_buffer));
	if (!node)
		return (NULL);
	node->content = (char *)malloc(sizeof(char) * (bytes_read + 1));
	i = 0;
	while (i < bytes_read)
	{
		node->content[i] = buffer[i];
		i++;
	}
	node->content[i] = '\0';
	node->next = NULL;
	return (node);
}

int	found_newline(t_buffer *last_node)
{
	int	i;

	if (!last_node)
		return (0);
	i = 0;
	while (last_node->content[i])
	{
		if (last_node->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
