/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 03:45:50 by vbauguen          #+#    #+#             */
/*   Updated: 2017/02/11 09:39:33 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


int ft_printf(const char *format, ...)
{
	t_pf structure;

	va_start(structure.args, format);
	init_structure(&structure);
	get_params(ft_strdup(format), &structure, 0);
	va_end(structure.args);
	ft_putstr(structure.modif);
	return (ft_strlen(structure.modif));
}

int parse_modulo(char *str, t_pf *s, int i, int j)
{
	int k;
	int l;
	char *result;

	i += 1;
	result = (char*)malloc(sizeof(char) * 32);
	s->params = (char**)malloc(sizeof(char*) * j);
 	l = 0;
 	ft_bzero(result, 32);
	while (str[i] && l < 32)
	{
		k = 0;
		result[l] = str[i];
		if (ft_strchr(FLAGS, str[i]) == NULL && ft_strchr(WIDTH, str[i]) == NULL && 
			ft_strchr(PRECISION, str[i]) == NULL && ft_strchr(SUBSPECIFIERS, str[i]) == NULL)
			break ;
		i++;
		l++;
	}
	validity_of_parameters(result, s);
	free(result);
	return (i);
}

int validity_of_parameters(char *result, t_pf *s)
{
	int i;

	i = 0;
	check_flags(result, &i, s);
	check_width(result, &i, s);
	check_precision(result, &i, s);
	check_subspecifier(result, &i, s);


	if ((int)result[i] >= 0 && (int)result[i] < 128)
		s->spec[(int)result[i]] = 1;

	// int debug = 1;
	int debug = 0;
	if (debug)
	{
		printf("\033[0;34m------------------------------------------\033[0m\n");
		printf("Full modulo = \033[0;32m%s\033[0m\n", result);
		printf("Specifier = %c\n", result[i]);
		printf("----------FlAGS ----------\n");
		if (s->spec['0'])
			printf("'0' = %d\n", s->spec['0']);
		if (s->spec['-'])
			printf("'-' = %d\n", s->spec['-']);
		if (s->spec['+'])
			printf("'+' = %d\n", s->spec['+']);
		if (s->spec['#'])
			printf("'#' = %d\n", s->spec['#']);
		if (s->spec[' '])
			printf("' ' = %d\n", s->spec[' ']);
		printf("--------------------------\n");
		if (s->modulo_width)
			printf("modulo_width = \033[1;36m%d\033[0m\n", s->modulo_width);
		if (s->modulo_precision == -1)
			printf("modulo_precision = \033[1;35m%s\033[0m\n", "doesn't exist");
		else
			printf("modulo_precision = \033[1;35m%d\033[0m\n", s->modulo_precision);
		printf("----------SUBSPECIFIERS ----------\n");
		if (s->spec['l'])
		printf("'l' = %d\n", s->spec['l']);
		if (s->spec['j'])
		printf("'j' = %d\n", s->spec['j']);
		if (s->spec['z'])
		printf("'z' = %d\n", s->spec['z']);
		if (s->spec['h'])
		printf("'h' = %d\n", s->spec['h']);
		printf("\033[0;34m------------------------------------------\033[0m\n");
	}
	return 1;
}