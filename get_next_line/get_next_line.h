/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 15:38:01 by odiez-gu          #+#    #+#             */
/*   Updated: 2026/02/10 17:52:45 by odiez-gu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_buffer
{
	char			*content;
	struct s_buffer	*next;
}					t_buffer;

typedef struct s_queue
{
	t_buffer		*front;
	t_buffer		*rear;
}					t_queue;

/* 1. Lee del FD y gestiona la cola (usa gnl_lstadd_back) */
void				fill_stash(int fd, t_queue *queue);

/* 2. Añade un nuevo nodo al final de la cola actualizando el 'rear' */
void				gnl_lstadd_back(t_queue *queue, char *content);

/* 3. Crea el string final a devolver extrayendo datos desde 'front' */
char				*generate_line(t_queue *queue);

/* 4. Libera los nodos consumidos y gestiona el contenido tras el '\n' */
void				rebuild_stash(t_queue *queue);

/* 5. Utilidades para calcular longitudes y buscar el '\n' en el nodo 'rear' */
int					found_newline(t_buffer *last_node);
size_t				count_to_newline(t_queue *queue);
t_buffer			*ft_create_node(char *buffer, int bytes_read);

#endif
