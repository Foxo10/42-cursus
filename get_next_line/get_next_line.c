/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:37:19 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/02/11 14:49:45 by odiez-gu         ###   ########.fr       */
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

char	*generate_line(t_queue *queue)
{
	int			i;
	int			j;
	char		*line;
	t_buffer	*tmp;

	line = (char *)malloc(sizeof(char) * (count_to_newline(queue) + 1));
	if (line == NULL)
		return (NULL);
	tmp = queue->front;
	i = 0;
	while (tmp)
	{
		j = 0;
		while (tmp->content[j])
		{
			line[i++] = tmp->content[j];
			if (tmp->content[j] == '\n')
				break ;
		}
		if (i > 0 && line[i - 1] == '\n')
			break ;
		tmp = tmp->next;
	}
	line[i] = '\0';
	return (line);
}

// Cortar la cola para liberar lo viejo de golpe
void	rebuild_stash(t_queue *queue)
{
	t_buffer	*clean_node;

	// 1. Crear el nodo limpio con el sobrante del FINAL (rear)
	// Buscar el \n y copiar lo que hay después.
	clean_node = get_remains(queue->rear);
	// 2. Liberar TODO el stash antiguo de golpe
	free_stash(&(queue->front));
	// 3. Reiniciar la cola con el nodo limpio
	if (clean_node->content[0])
	{
		queue->front = clean_node;
		queue->rear = clean_node;
	}
	else
	{
		free(clean_node->content);
		free(clean_node);
		queue->front = NULL;
		queue->rear = NULL;
	}
}

char	*get_next_line(int fd)
{
	static t_queue	stash = {NULL, NULL};
	char			*line;

	// Initial validation
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free_stash(&(stash.front)), stash.rear = NULL, NULL);
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
