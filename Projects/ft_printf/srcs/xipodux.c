/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xipodux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 02:53:02 by vbauguen          #+#    #+#             */
/*   Updated: 2017/02/11 10:54:01 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	octal_treatment(t_pf *s)
{
	unsigned int i;


	s->prefix = s->spec['#'] ? ft_strdup("0") : ft_strdup("");
	s->spec['+'] = 0;
	s->numeric = 1;
	i = va_arg(s->args, unsigned int);
	s->modulo_treatment = ft_strdup(ft_itoa_base(i, 8));
}

void	hexadecimal_treatment(t_pf *s)
{
	unsigned int i;

	i = va_arg(s->args, unsigned int);
	s->spec['+'] = 0;
	s->numeric = 1;
	if (s->spec['x'])
	{
		s->modulo_treatment = ft_strdup(ft_strtolower(ft_itoa_base(i, 16)));
		s->prefix = s->spec['#'] ? ft_strdup("0x") : ft_strdup("");

	}
	else if (s->spec['X'])
	{
		s->prefix = s->spec['#'] ? ft_strdup("0X") : ft_strdup("");
		s->modulo_treatment = ft_strdup(ft_itoa_base(i, 16));
	}
}

void	integer_treatment(t_pf *s)
{
	int i;

	s->spec['#'] = 0;
	s->numeric = 1;
	i = va_arg(s->args, int);
	if (s->spec['i'] || s->spec['d'])
		s->modulo_treatment = ft_strdup(ft_itoa_base(i, 10));
	else if (s->spec['u'])
		s->modulo_treatment = ft_strdup(ft_itoa_base((unsigned int)i, 10));
}

void	pointer_treatment(t_pf *s)
{
	void *p;

	s->spec['#'] = 0;
	s->numeric = 1;
	p = va_arg(s->args, void *);
	s->prefix = ft_strdup("0x");
	s->modulo_treatment = ft_strdup(ft_strtolower(
		ft_itoa_base((unsigned long long int)p, 16)));
}
