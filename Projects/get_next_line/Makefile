# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 11:26:20 by vbauguen          #+#    #+#              #
#    Updated: 2016/02/03 23:16:09 by vbauguen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

SRC = 	get_next_line.c main.c\

OBJ = $(SRC:.c=.o)

GCCF = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft re
	clang $(GCCF) -I libft/includes -o get_next_line.o -c get_next_line.c
	clang  $(GCCF) -I libft/includes -o main.o -c main.c
	clang -o $(NAME) $(OBJ) -I libft/includes -L libft/ -lft

%.o: %.c libft/libft.h
	gcc -c $(GCCF) -I libft/ $< -o $@

.PHONY: clean fclean re

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
