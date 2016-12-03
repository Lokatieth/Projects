/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:22:12 by vbauguen          #+#    #+#             */
/*   Updated: 2016/12/03 11:53:05 by vbauguen         ###   ########.fr       */
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


# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdarg.h>
# include <stdio.h>


typedef struct		s_printf
{

	va_list 		args;
	char 			*precision_final;
	char 			*width_final;
	char 			*modif;
	char 			*initial;
	char 			*mod;
	char			**params;
	int 			spec[ARRAY_SIZE];
	int				modulo_width;
	int 			modulo_precision;
}					t_pf;


int 		ft_printf(const char *format, ...);
int 		count_flags(char *str);

#endif
