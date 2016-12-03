# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 11:26:20 by vbauguen          #+#    #+#              #
#    Updated: 2016/12/01 01:28:27 by vbauguen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED=\033[0;31m
GREEN=\033[0;32m
ORANGE=\033[0;33m
BLUE=\033[0;34m
PURPLE=\033[0;35m
CYAN=\033[0;36m
GRAY=\033[0;37m
LCYAN=\033[1;36m
LPURPLE=\033[1;35m
NC=\033[0m

NAME = printftest\

SRC =	main.c\

OBJ = $(SRC:.c=.o)

GCCF = -Wall -Werror -Wextra 

all: $(NAME)
	@echo  "${GREEN}Make completed${NC}"

$(NAME): $(OBJ)	
	@make -C libft
# Compil Linux
	@# gcc -o $(NAME) $(OBJ) -L libft -lft -lm -march=native
# Compil MacOs
	@gcc -o $(NAME) $(OBJ) -L libft -lft -lmlx -framework OpenGL -framework Appkit -O3 -march=native

%.o: %.c libft/libft.h
	@gcc -c $(GCCF) -I libft/ $< -o $@

.PHONY: clean fclean re

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
