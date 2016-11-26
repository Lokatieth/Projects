# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 11:26:20 by vbauguen          #+#    #+#              #
#    Updated: 2016/06/04 15:13:59 by vbauguen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printftest\

SRC =	main.c\

OBJ = $(SRC:.c=.o)

GCCF =  -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)	
	make -C libft re
# Compil Linux
	gcc -o $(NAME) $(OBJ) -L libft -lft -lm -march=native
# Compil MacOs
	# @gcc -o $(NAME) $(OBJ) -L libft -lft -lmlx -framework OpenGL -framework Appkit -O3 -march=native


%.o: %.c libft/libft.h
	gcc -c $(GCCF) -I libft/ $< -o $@

.PHONY: clean fclean re

clean:
	@rm -rf $(OBJ)
	make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	make -C libft fclean

re: fclean all
