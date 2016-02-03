# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 11:26:20 by vbauguen          #+#    #+#              #
#    Updated: 2016/01/19 18:55:24 by vbauguen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC =	verification.c\
	ft_stick_verif.c\
	ft_to_letters.c\
	ft_print_grid.c\
	ft_place.c\
	ft_tab_func.c\
	ft_bigger_tab.c\
	upleft.c\
	
OBJ = $(SRC:.c=.o)

GCCF = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
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
