# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 11:26:20 by vbauguen          #+#    #+#              #
#    Updated: 2017/02/11 03:40:11 by vbauguen         ###   ########.fr        #
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

OBJPATH = obj/

SRCSPATH = srcs/

SRCS =	main.c \
		xipodux.c \
		param_struct.c \
		modulo_majdou_s.c \
		get_params.c \
		parse_and_check \

SRC = $(addprefix $(SRCSPATH), $(SRCS))

OBJ = $(SRC:.c=.o)

GCCF = -Wall -Werror -Wextra 

CC = gcc

CFLAGS = -Wextra -Wall -Werror

all: $(NAME)

$(NAME): $(OBJ)	
	@make -C libft
# Compil Linux
	@# gcc -o $(NAME) $(OBJ) -L libft -lft -lm -march=native
# Compil MacOs
	@gcc -o $(NAME) $(OBJ) $(GCCF) -L libft -lft -lmlx 

$(OBJPATH)%.o: $(SRCSPATH)%.c libft/libft.h
	@gcc -c $(GCCF) -I libft/ $< -o $@

.PHONY: clean fclean re

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -rf $(NAME)
	@make -C libft fclean

re: fclean all
