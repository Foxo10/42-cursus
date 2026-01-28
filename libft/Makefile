# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/14 19:42:00 by odiez-gu          #+#    #+#              #
#    Updated: 2026/01/27 20:39:01 by odiez-gu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

HDR = libft.h

SRC_M = \
ft_atoi.c \
ft_memset.c \
ft_strlen.c \
ft_bzero.c \
ft_putchar_fd.c \
ft_strmapi.c \
ft_calloc.c \
ft_putendl_fd.c \
ft_strncmp.c \
ft_isalnum.c \
ft_putnbr_fd.c \
ft_strnstr.c \
ft_isalpha.c \
ft_putstr_fd.c \
ft_split.c \
ft_isascii.c \
ft_strchr.c \
ft_strrchr.c \
ft_strtrim.c \
ft_isdigit.c \
ft_strdup.c \
ft_substr.c \
ft_isprint.c \
ft_memchr.c \
ft_striteri.c \
ft_tolower.c \
ft_toupper.c \
ft_itoa.c \
ft_memcmp.c \
ft_strjoin.c \
ft_memcpy.c \
ft_strlcat.c \
ft_memmove.c \
ft_strlcpy.c

SRC_B = \
ft_lstnew.c \
ft_lstadd_front.c \
ft_lstsize.c \
ft_lstlast.c \
ft_lstadd_back.c \
ft_lstdelone.c \
ft_lstclear.c \
ft_lstiter.c \
ft_lstmap.c

OBJ_M = $(SRC_M:.c=.o)
OBJ_B = $(SRC_B:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_M) $(OBJ_B)
	ar rcs $(NAME) $(OBJ_M) $(OBJ_B)

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_M) $(OBJ_B)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
