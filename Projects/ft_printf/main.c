#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>



void octal_treatment(t_pf *s)
{
	unsigned int i;

	i = va_arg(s->args, unsigned int);
	s->modif = ft_strjoinopt(s->modif, ft_itoa_base(i, 8));
}

void hexadecimal_treatment(t_pf *s)
{
	unsigned int i;

	i = va_arg(s->args, unsigned int);



	if (s->spec['#'] && i)
		s->modif = ft_strjoinopt(s->modif, "0x");
	if (s->spec['x'])
		s->modif = ft_strjoinopt(s->modif, ft_strtolower(ft_itoa_base(i, 16)));
	else if (s->spec['X'])
		s->modif = ft_strjoinopt(s->modif, ft_itoa_base(i, 16));
}

void integer_treatment(t_pf *s)
{
	int i;

	i = va_arg(s->args, int);
	if (s->spec['i'] || s->spec['d'])
		s->modif = ft_strjoinopt(s->modif, ft_itoa_base(i, 10));
	else if (s->spec['u'])
		s->modif = ft_strjoinopt(s->modif, ft_itoa_base((unsigned int)i, 10));

}

void string_treatment(t_pf *s)
{
	char *str;
	wchar_t *wc;

	if (s->spec['s'])
	{
		str = va_arg(s->args, char *);
		s->modif = ft_strjoinopt(s->modif, str);
	}
	else
	{
		wc = va_arg(s->args, wchar_t *);
		s->modif = ft_strjoinopt(s->modif, (char *)wc);
	}
}

void pointer_treatment(t_pf *s)
{
	void *p;

	p = va_arg(s->args, void *);
	s->modif = ft_strjoinopt(s->modif,"0x");
	s->modif = ft_strjoinopt(s->modif, ft_strtolower(ft_itoa_base((unsigned long long int)p, 16)));	
}

void long_treatment(t_pf *s)
{
	long int i;

	i = va_arg(s->args, long int);

	if (s->spec['D'])
		s->modif = ft_strjoinopt(s->modif, ft_itoa_base((int)i, 10));
	else if (s->spec['U'])
		s->modif = ft_strjoinopt(s->modif, ft_itoa_base((unsigned int)i, 10));
	else if (s->spec['O'])
		s->modif = ft_strjoinopt(s->modif, ft_itoa_base((unsigned int)i, 8));
}

void char_treatment(t_pf *s)
{
	char *str;
	char c;

	if (s->spec['c'])
		c = va_arg(s->args, int);
	else
		c = va_arg(s->args, wchar_t);
	str = ft_strnew(1);
	str[0] = c;
	s->modif = ft_strjoinopt(s->modif, str);
}

void modulo_treatment(t_pf *s)
{
	s->modif = ft_strjoinopt(s->modif, "%");
}

void (*ptr_funct_tab[ARRAY_SIZE])(t_pf *s) = {
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

void check_precision(char *str, int *i, t_pf *s)
{
	if (str[*i] == '.')
	{
		++*i;
		s->modulo_precision = ft_atoi(str + *i);
		*i += ft_size_int(s->modulo_precision);
	}
}

int after_flags(char *str, int *i)
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

void check_flags(char *str, int *i, t_pf *s)
{
	char *n;
	int car;

	car = 0;
	while (str[*i])
	{
		if ((n = ft_strchr(FLAGS, str[*i])))
		{
			s->spec[(int)*n] = 1;
			car = 0;
			++*i;
		}
		else
			break;
	}
}

void check_subspecifier(char *str, int *i, t_pf *s)
{
	char *n;
	int car;

	car = 0;
	while (str[*i])
	{
		if ((n = ft_strchr(SUBSPECIFIERS, str[*i])))
		{
			if ((str[*i] == 'h' && str[*i - 1] == 'h') || (str[*i] == 'l' && str[*i - 1] == 'l'))
				s->spec[(int)*n] = 2;
			else
				s->spec[(int)*n] = 1;
			car = 0;
			++*i;
		}
		else
			break;
	}
}

void check_width(char *str, int *i, t_pf *s)
{
	s->modulo_width = ft_atoi(str + *i);
	if (s->modulo_width)
		*i += ft_size_int(s->modulo_width);
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
	if (s->modulo_precision)
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
	printf("------------------------------------------\n");

	return 1;
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



void get_params(char *str, t_pf *s, int i)
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
				// if (s->spec)
				ptr_funct_tab[(int)str[spec_end]](s);
				str += spec_end + 1;
			}
			else
				str += spec_end;
			i = 0;
			ft_bzero(s->spec, sizeof(int) * ARRAY_SIZE);
		}
		else
			i++;
	}
	s->modif = ft_strjoinopt(s->modif, str);
}

void init_structure(t_pf *s)
{
	int i;

	i = 0;
	while (i < 127)
	{
		s->spec[i] = 0;
		i++;
	}
	s->modif = ft_strdup("");
	s->modulo_width = 0;
	s->modulo_precision = 0;
}

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

int main(void)
{
	// ft_printf("Ceci est un specifier sans rien : \033[0;31m%d\033[0m\n" , 10);
	// ft_printf("Ceci est un specifier avec flag : \033[0;31m%+d\033[0m\n" , 10);
	// ft_printf("Ceci est un specifier avec flag et preci: \033[0;31m%+.2d\033[0m\n" , 10);
	// ft_printf("Ceci est un specifier avec largeur de champ : \033[0;31m%24d\033[0m\n" , 10);
	// ft_printf("Ceci est un specifier avec largeur de champ et flags: \033[0;31m%+24d\033[0m\n" , 10);
	// ft_printf("Ceci est un specifier avec largeur de champ et preci : \033[0;31m%9.2d\033[0m\n" , 10);
	// ft_printf("Ceci est un specifier avec largeur de champ, preci et flags : \033[0;31m%+- 265.356hhd\033[0m\n" , 10);
	ft_printf("{%#x}", 10);
	printf("{%#x}", 10);
	return (0);
}	
