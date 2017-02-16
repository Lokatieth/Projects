/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 02:50:52 by vbauguen          #+#    #+#             */
/*   Updated: 2017/02/11 09:48:04 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void (*g_ptr_funct_tab[ARRAY_SIZE])(t_pf *s) = {
	['s'] = &string_treatment,
	['S'] = &string_treatment,
	['p'] = &pointer_treatment,
	['d'] = &integer_treatment,
	['i'] = &integer_treatment,
	['D'] = &long_treatment,
	['O'] = &long_treatment,
	['U'] = &long_treatment,
	['o'] = &octal_treatment,
	['u'] = &integer_treatment,
	['x'] = &hexadecimal_treatment,
	['X'] = &hexadecimal_treatment,
	['c'] = &char_treatment,
	['C'] = &char_treatment,
	['%'] = &modulo_treatment,
};

void	get_params(char *str, t_pf *s, int i)
{
	int j;
	int spec_end;

	j = 0;
	while (str[i++])
	{
		if (str[i] == '%')
			j++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			spec_end = parse_modulo(str, s, i, j);
			str[i] = '\0';
			s->modif = ft_strjoinopt(s->modif, str);
			if (ft_strchr(SPECIFIERS, str[spec_end]) != NULL)
			{
				g_ptr_funct_tab[(int)str[spec_end]](s);
				s->modulo_treatment = ft_strdup(treat_the_modulo(s));
				s->modif = ft_strjoinopt(s->modif, s->modulo_treatment);
				str += spec_end + 1;
			}
			else
				str += spec_end;
			i = 0;
			ft_bzero(s->spec, sizeof(int) * ARRAY_SIZE);
			reset_params(s);
		}
		else
			i++;
	}
	s->modif = ft_strjoinopt(s->modif, str);
}

void	init_structure(t_pf *s)
{
	int i;

	i = 0;
	while (i < 127)
	{
		s->spec[i] = 0;
		i++;
	}
	s->modif = ft_strdup("");
	// s->modulo_width = 0;
	// s->modulo_precision = -1;
	reset_params(s);
}

void	reset_params(t_pf *s)
{
	s->modulo_width = 0;
	s->modulo_precision = -1;
	s->numeric = 0;
	s->prefix = ft_strdup("");
}

int		after_flags(char *str, int *i)
{
	int k;

	k = 0;
	while (k < (int)ft_strlen(WIDTH))
	{
		if (str[*i] == WIDTH[k])
			return (1);
		k++;
	}
	return (0);
}
