# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/14 19:42:07 by odiez-gu          #+#    #+#              #
#    Updated: 2026/01/14 20:18:58 by odiez-gu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tester

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT = ../libft.a
TEST = $(wildcard *.c)
HDR = tester.h

OBJ = $(SRC:.c=.o) $(TEST:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
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

run: all
	./$(NAME)

.PHONY: all clean fclean re