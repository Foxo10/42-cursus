/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:37:19 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/02/10 18:27:50 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	fill_stash(int fd, t_queue *queue)
{
	int			bytes_read;
	char		buffer[BUFFER_SIZE + 1];
	t_buffer	*block;

	while (!found_newline(queue->rear))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return ;
		buffer[bytes_read] = '\0';
		block = ft_create_node(buffer, bytes_read);
		if (queue->front == NULL)
		{
			queue->front = block;
			queue->rear = block;
		}
		else
		{
			queue->rear->next = block;
			queue->rear = block;
		}
	}
}

char	*get_next_line(int fd)
{
	static t_queue	stash = {NULL, NULL};
	char			*line;

	// Initial validation
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (stash.front)
			free_stash(&(stash.front));
		stash.front = NULL;
		stash.rear = NULL;
		return (NULL);
	}
	// 1. Load stash (Reading)
	fill_stash(fd, &stash);
	if (stash.front == NULL)
		return (NULL);
	// 3. Generate the whole line from stash
	line = generate_line(&stash);
	// 4. Clean the used stash for the next call
	rebuild_stash(&stash);
	return (line);
}
