/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_replace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 10:55:17 by vbauguen          #+#    #+#             */
/*   Updated: 2017/02/11 10:55:51 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static char *ft_str_insert(char *str, char *dest, int start)
{
	char *result;
	int str_l;
	int dest_l;


	dest_l = ft_strlen(dest);
	if (start > dest_l || start < 0)
		return (dest);
	str_l = ft_strlen(str);
	result = ft_strnew(str_l + dest_l + 1);
	result = ft_memcpy(result, dest, start);
	result += start;
	dest += start;
	result = ft_memcpy(result, str, str_l);
	result += str_l;
	result = ft_memcpy(result, dest, dest_l - start);
	result[str_l + dest_l] = 0;	
	result -= (start + str_l);
	return(result);
}

char *ft_str_replace(char *str, char *dest, int start, int len)
{
	char *result;
	int str_l;
	int dest_l;

	dest_l = ft_strlen(dest);
	if (start + len > dest_l || len < 0 || start < 0)
		return (dest);
	str_l = ft_strlen(str);
	result = ft_strnew(str_l + dest_l - len + 1);
	result = ft_memcpy(result, dest, start);
	result += start;
	dest += start + len;
	result = ft_memcpy(result, dest, dest_l);
	result = ft_str_insert(str, result - start, start);
	return (result);
}
