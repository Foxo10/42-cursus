# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: odiez-gu <odiez-gu@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/01/14 19:42:00 by odiez-gu          #+#    #+#              #
#    Updated: 2026/01/23 14:35:20 by odiez-gu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -c -Wall -Wextra -Werror
CPPFLAGS = 	-I.

SRC = $(wildcard src/*.c)
MAND_OBJ = $(MAND_SRC:.c=.o)
HDR = src/libft.h
BONUS_SRC = $(wildcard src/*_bonus.c)
BONUS_OBJ = $(BONUS_SRC:.c=.o)
MAND_SRC = $(filter-out $(BONUS_SRC),$(SRC))
PIC_OBJ = $(MAND_OBJ:.o=.pic.o) $(BONUS_OBJ:.o=.pic.o)

all: $(NAME)

$(NAME): $(MAND_OBJ)
	ar rcs $(NAME) $(MAND_OBJ)

bonus: $(MAND_OBJ) $(BONUS_OBJ)
	ar rcs $(NAME) $(MAND_OBJ) $(BONUS_OBJ)

src/%.o: src/%.c $(HDR)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

src/%.pic.o: src/%.c $(HDR)
	$(CC) -Wall -Wextra -Werror $(CPPFLAGS) -fPIC -c $< -o $@


clean:
	rm -f $(MAND_OBJ) $(BONUS_OBJ) $(PIC_OBJ)

fclean: clean
	rm -f $(NAME) libft.so

re: fclean all

so: bonus $(PIC_OBJ)
	$(CC) -shared -o libft.so $(PIC_OBJ)

.PHONY: all clean fclean re so bonus