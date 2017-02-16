/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:22:12 by vbauguen          #+#    #+#             */
/*   Updated: 2017/02/15 15:50:48 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define SPECIFIERS "sSpdDioOuUxXcC%"
# define SUBSPECIFIERS "hjlz"
# define WIDTH "123456789"
# define PRECISION "123456789."
# define FLAGS "+- 0#"
# define ARRAY_SIZE 128
# define RED \033[0;31m
# define GREEN \033[0;32m
# define ORANGE \033[0;33m
# define BLUE \033[0;34m
# define PURPLE \033[0;35m
# define CYAN \033[0;36m
# define GRAY \033[0;37m
# define LCYAN \033[1;36m
# define LPURPLE \033[1;35m
# define NC \033[0m

# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_printf
{
	va_list		args;
	char		*modulo_treatment;
	char		*precision_final;
	char		*width_final;
	char		*modif;
	char		*initial;
	char		*mod;
	char 		*prefix;
	char		**params;
	int			numeric;
	int			modulo_width;
	int			modulo_precision;
	int			spec[ARRAY_SIZE];
	
}				t_pf;

int				ft_isspace(int c);
int				ft_isdigit(int c);
int				ft_printf(const char *format, ...);
void			octal_treatment(t_pf *s);
void			hexadecimal_treatment(t_pf *s);
void			pointer_treatment(t_pf *s);
void			integer_treatment(t_pf *s);
void			string_treatment(t_pf *s);
void			long_treatment(t_pf *s);
void			char_treatment(t_pf *s);
void			modulo_treatment(t_pf *s);
void			get_params(char *str, t_pf *s, int i);
void			init_structure(t_pf *s);
void			reset_params(t_pf *s);
int				validity_of_parameters(char *result, t_pf *s);
int				parse_modulo(char *str, t_pf *s, int i, int j);
char			*initial_changes(t_pf *s, char *result);
char			*treat_the_modulo(t_pf *s);
int				after_flags(char *str, int *i);
void			check_width(char *str, int *i, t_pf *s);
void			check_subspecifier(char *str, int *i, t_pf *s);
void			check_flags(char *str, int *i, t_pf *s);
void			check_precision(char *str, int *i, t_pf *s);
int				count_flags(char *str);

#endif
