NAME = libftprintf.a
# NAME = printf


SRCSPATH = srcs/

INCLUDES = includes/

LIBFT_INCLUDES = libft/

SRCS =	main.c \
		xipodux.c \
		param_struct.c \
		modulo_majdou_s.c \
		get_params.c \
		parse_and_check.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_itoa_base.c \
		ft_memset.c \
		ft_putstr.c \
		ft_str_replace.c \
		ft_strchr.c \
		ft_strjoinopt.c \
		ft_strjoin.c \
		ft_size_int.c \
		ft_strlen.c \
		ft_strnew.c \
		ft_strtolower.c \
		ft_isdigit.c \
		ft_isspace.c \
		ft_memcpy.c \
		ft_strdup.c \
		ft_strrev.c \
		ft_tolower.c \



SRC = $(addprefix $(SRCSPATH), $(SRCS))

WFLAGS = -Wall -Werror -Wextra

LFLAGS =

CC = gcc

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o: %.c
	$(CC) -c $(WFLAGS) -I $(LIBFT_INCLUDES) -I $(INCLUDES) $< -o $@

# $(NAME) : $(OBJ)
# #	make -C libft
# 	$(CC) -o $(NAME) $(OBJ) $(WFLAGS) $(LFLAGS) -I $(INCLUDES)

# Compil libft.a


$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME) 

exec: fclean $(NAME)
#	make -C libft
	$(CC) -o $(NAME) $(OBJ) $(WFLAGS) $(LFLAGS) -I $(INCLUDES) -g
	./libftprintf.a

clean :
	rm -rf $(OBJ)
	make -C libft clean

fclean : clean
	rm -f $(NAME)
	# make -C libft fclean

re : fclean all

.PHONY: all clean fclean re



