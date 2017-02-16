/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 02:52:35 by vbauguen          #+#    #+#             */
/*   Updated: 2017/02/15 16:48:54 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

char *pad_leading(t_pf *s, char *str, char c, int len)
{
	char	*text;
	char	*result;
	char	*padding;
	int		start;
	int		textlen;

	int p_len = s->modulo_precision;
	int w_len = s->modulo_width;

	(void)c;
	// (void)str;
	// (void)len;
	// (void)s;
	text = ft_strdup(str);
	if (s->numeric && s->spec['+'])
		s->prefix = ft_str_replace("+", s->prefix, 0, 0);
	textlen = ft_strlen(s->prefix) + ft_strlen(str);
	if ((textlen + p_len) <= w_len && p_len > (textlen))
	{ 
		padding = ft_strnew(p_len - ft_strlen(str));
		ft_memset(padding, c, p_len - ft_strlen(str));
		text = ft_str_replace(padding, text, 0, 0);
		textlen += p_len - ft_strlen(str);
	}
	// else
	// {	
	// 	padding = ft_strnew(w_len - ft_strlen(str));
	// 	// printf("Padding = [%s], c = [%c], w_len = [%d], str_len = [%d]\n", padding, c, w_len , (int)ft_strlen(str));
	// 	ft_memset(padding, c, abs(w_len - (int)ft_strlen(str)));
	// 	text = ft_str_replace(padding, text, 0, 0);
	// 	textlen += w_len - ft_strlen(str);
	// }
	start = (s->spec['-'] ? 0 : len - textlen);
	result = ft_strnew(len);
	ft_memset(result, ' ', len);
	// ft_memset(result, , len);

	text = ft_str_replace(s->prefix, text, 0, 0);


	// printf("STR === [%s], start = [%d], len = %d, textlen = %d\n", text, start, len, textlen);
	result = ft_str_replace(text, result, start, textlen);



	// text = s->modulo_treatment;





	return (result);
}

char *treat_the_modulo(t_pf *s)
{
	char *result;
	char padding;
	int str_len;
	// int zero_flag;
	str_len = (s->modulo_width > s->modulo_precision ? s->modulo_width : s->modulo_precision);
	str_len = (ft_strlen(s->modulo_treatment) + ft_strlen(s->prefix) > (size_t)str_len ? ft_strlen(s->modulo_treatment) + ft_strlen(s->prefix): str_len);
	padding = (s->numeric ? '0' : ' ');
	// printf("Padding = [%c], preci = [%d], largeur = [%d], flag \'-\' = [%d]\n", padding, s->modulo_precision, s->modulo_width, s->spec['-']);

	// result = ft_strdup(s->modulo_treatment);
	result = pad_leading(s, s->modulo_treatment, padding, str_len);
	return (result);
}


// int main(void)
// {
// 	  	printf("==========================================\n");
// 	  	// printf("%%.10d = [%.10d]\n", 123);
// 	  	ft_printf("10.10d = \t\e[31m[%10.10d]\033[0m", 123);	printf("\t\e[32m[%10.10d]\033[0m\n", 123);
// 	  	ft_printf("-10.10d = \t\e[31m[%-10.10d]\033[0m", 123);	printf("\t\e[32m[%-10.10d]\033[0m\n", 123);
// 	  	printf("==========================================\n");
// 	  	ft_printf(" 5.10d = \t\e[31m[%5.10d]\033[0m", 123);	printf("\t\e[32m[%5.10d]\033[0m\n", 123);
// 		ft_printf("-5.10d = \t\e[31m[%-5.10d]\033[0m", 123); 	printf("\t\e[32m[%-5.10d]\033[0m\n", 123);
// 	  	printf("==========================================\n");
  		
//   		ft_printf(" 5.5d = \t\e[31m[%5.5d]\033[0m", 123);	printf("\t\e[32m[%5.5d]\033[0m\n", 123);
// 		ft_printf("-5.5d = \t\e[31m[%-5.5d]\033[0m", 123); 	printf("\t\e[32m[%-5.5d]\033[0m\n", 123);
// 	  	printf("==========================================\n");

// 	  	ft_printf("10.5d  = \t\e[31m[%10.5d]\033[0m", 123); 	printf("\t\e[32m[%10.5d]\033[0m\n", 123);
// 	  	ft_printf("-+10.5d  = \t\e[31m[%-+10.5d]\033[0m", 123);	printf("\t\e[32m[%-+10.5d]\033[0m\n", 123);
// 	  	printf("==========================================\n");
// 	  	// printf("%%010.10d = [%010.10d]\n", 123);

// 	  	ft_printf("%%");
// 	  	// printf("---------------------\n");
// 		// printf("%%s = [%s]\n", "Coucou les enfants");
// 	  	// printf("%%100s = [%100s]\n", "Coucou les enfants");
// 	  	// printf("%%.10s = [%.10s]\n", "Coucou les enfants");
// 	  	// printf("%%10.10s = [%10.10s]\n", "Coucou les enfants");
// 	  	// printf("%%10.10s = [%10.10s]\n", "Coucou les enfants");


// 	return (0);
// }	















 