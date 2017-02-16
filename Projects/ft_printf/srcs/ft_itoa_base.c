/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 18:51:01 by vbauguen          #+#    #+#             */
/*   Updated: 2016/12/03 03:20:03 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <limits.h>

char	*ft_itoa_base(long long int number, unsigned int base)
{
	char					*str;
	int						j;
	unsigned long long int	nb_tmp;
	int						is_neg;

	j = 0;
	is_neg = (number < 0 ? 1 : 0);
	nb_tmp = (number < 0 ? -number : number);
	if ((str = ft_strnew(sizeof(long long int) * 8 + 1)) == NULL || base == 0)
		return (NULL);
	if (number == 0)
		return (ft_strdup("0"));
	while (nb_tmp > 0)
	{
		str[j++] = (nb_tmp % base)["0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"];
		nb_tmp = nb_tmp / base;
	}
	if (is_neg)
		str[j++] = '-';
	str[j] = '\0';
	return (ft_strrev(str));
}
