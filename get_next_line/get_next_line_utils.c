/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:37:37 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/02/11 15:01:20 by odiez-gu         ###   ########.fr       */
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

size_t	count_to_newline(t_queue *queue)
{
	size_t		i;
	size_t		len;
	t_buffer	*tmp;

	if (!queue || !queue->front)
		return (0);
	len = 0;
	tmp = queue->front;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i])
		{
			len++;
			if (tmp->content[i] == '\n')
				return (len);
			i++;
		}
		tmp = tmp->next;
	}
	return (len);
}

t_buffer	*get_remains(t_buffer *rear)
{
	t_buffer	*clean_node;
	int			len;
	int			i;

	i = 0;
	while (rear->content[i] && rear->content[i] != '\n')
		i++;
	if (rear->content[i] == '\n')
		i++;
	clean_node = malloc(sizeof(t_buffer));
	if (!clean_node)
	{
		free(clean_node);
		return (NULL);
	}
	len = 0;
	while (rear->content[i + len])
		len++;
	clean_node->content = (char *)malloc(sizeof(char) * (len + 1));
	len = 0;
	while (rear->content[i])
		clean_node->content[len++] = rear->content[i++];
	clean_node->content[len] = '\0';
	clean_node->next = NULL;
	return (clean_node);
}

void		free_stash(t_buffer *front);
