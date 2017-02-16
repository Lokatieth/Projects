/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modulo_majdou_s.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 02:53:40 by vbauguen          #+#    #+#             */
/*   Updated: 2017/02/11 08:19:32 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	string_treatment(t_pf *s)
{
	char		*str;
	wchar_t		*wc;

	s->spec['+'] = 0;
	s->spec[' '] = 0;
	s->spec['#'] = 0;
	s->spec['0'] = 0;
	s->numeric = 0;
	if (s->spec['s'])
	{
		str = va_arg(s->args, char *);
		s->modulo_treatment = ft_strdup(str);
	}
	else
	{
		wc = va_arg(s->args, wchar_t *);
		s->modulo_treatment = ft_strdup((char *)wc);
	}
}

void	long_treatment(t_pf *s)
{
	long int		i;

	i = va_arg(s->args, long int);
	s->spec['#'] = 0;
	s->numeric = 1;
	if (s->spec['D'])
		s->modulo_treatment = ft_strdup(ft_itoa_base((int)i, 10));
	else if (s->spec['U'])
		s->modulo_treatment = ft_strdup(ft_itoa_base((unsigned int)i, 10));
	else if (s->spec['O'])
		s->modulo_treatment = ft_strdup(ft_itoa_base((unsigned int)i, 8));
}

void	char_treatment(t_pf *s)
{
	char		*str;
	char		c;

	s->spec['#'] = 0;
	s->numeric = 0;
	if (s->spec['c'])
		c = va_arg(s->args, int);
	else
		c = va_arg(s->args, wchar_t);
	str = ft_strnew(1);
	str[0] = c;
	s->modulo_treatment = ft_strdup(str);
}

void	modulo_treatment(t_pf *s)
{
	s->numeric = 0;
	s->modulo_treatment = ft_strdup("%");
}
