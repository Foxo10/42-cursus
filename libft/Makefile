# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/14 19:42:00 by odiez-gu          #+#    #+#              #
#    Updated: 2026/01/15 20:44:35 by odiez-gu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -c -Wall -Wextra -Werror
CPPFLAGS = 	-I.

SRC = $(wildcard src/*.c)
OBJ = $(SRC:.c=.o)
HDR = src/libft.h

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

src/%.o: src/%.c $(HDR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re