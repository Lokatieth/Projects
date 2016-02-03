# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 11:26:20 by vbauguen          #+#    #+#              #
#    Updated: 2016/02/01 20:07:52 by vbauguen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mlx\

SRC =	main.c\

OBJ = $(SRC:.c=.o)

GCCF = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)	
	make -C minilibx_macros re
	make -C libft re
	gcc -o $(NAME) $(OBJ) -L libft -lft


%.o: %.c libft/libft.h
	gcc -c $(GCCF) -I libft/ $< -o $@

.PHONY: clean fclean re

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
