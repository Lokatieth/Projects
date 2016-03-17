# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/26 11:26:20 by vbauguen          #+#    #+#              #
#    Updated: 2016/03/16 15:04:51 by vbauguen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf\

SRC =	main.c\
		ft_images.c\
		ft_bonus.c\
		ft_fdf_check.c\
# SRC = image.c\

OBJ = $(SRC:.c=.o)

GCCF = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)	
	make -C minilibx_macos re
	make -C libft re
	gcc -o $(NAME) $(OBJ) -L libft -lft -lmlx -framework OpenGL -framework Appkit


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
