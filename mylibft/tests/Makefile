# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/14 19:42:07 by odiez-gu          #+#    #+#              #
#    Updated: 2026/01/22 14:37:02 by odiez-gu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tester

CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3 -I.

LIBFT = ../libft.a
TEST = $(wildcard *.c)
HDR = tester.h

OBJ = $(SRC:.c=.o) $(TEST:.c=.o)

VGFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ) $(HDR) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C .. all clean

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean 
	rm -f $(NAME)

re: fclean all

run: all clean
	./$(NAME)

vg: all clean
	valgrind $(VGFLAGS) ./$(NAME)

.PHONY: all clean fclean re