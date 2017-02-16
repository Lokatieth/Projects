/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:24:00 by vbauguen          #+#    #+#             */
/*   Updated: 2016/12/03 03:27:03 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


char	*ft_strnew(size_t size)
{
	char					*newstr;
	unsigned long int		i;

	i = 0;
	newstr = (char*)malloc(sizeof(char) * (size + 1));
	if (newstr == NULL)
		return (NULL);
	ft_bzero(newstr, size + 1);
	return (newstr);
}
