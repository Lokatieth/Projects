/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 02:58:48 by vbauguen          #+#    #+#             */
/*   Updated: 2017/02/11 08:13:58 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	check_precision(char *str, int *i, t_pf *s)
{
	if (str[*i] == '.')
	{
		++*i;
		s->modulo_precision = ft_atoi(str + *i);
		*i += ft_size_int(s->modulo_precision);
	}
}

void	check_flags(char *str, int *i, t_pf *s)
{
	char	*n;
	int		car;

	car = 0;
	while (str[*i])
	{
		if ((n = ft_strchr(FLAGS, str[*i])))
		{
			s->spec[(int)*n] = 1;
			if (s->spec['0'] == 1)
				s->numeric = 1;
			car = 0;
			++*i;
		}
		else
			break ;
	}
}

void	check_subspecifier(char *str, int *i, t_pf *s)
{
	char	*n;
	int		car;

	car = 0;
	while (str[*i])
	{
		if ((n = ft_strchr(SUBSPECIFIERS, str[*i])))
		{
			if ((str[*i] == 'h' && str[*i - 1] == 'h')
				|| (str[*i] == 'l' && str[*i - 1] == 'l'))
				s->spec[(int)*n] = 2;
			else
				s->spec[(int)*n] = 1;
			car = 0;
			++*i;
		}
		else
			break ;
	}
}

void	check_width(char *str, int *i, t_pf *s)
{
	s->modulo_width = ft_atoi(str + *i);
	if (s->modulo_width)
		*i += ft_size_int(s->modulo_width);
}
