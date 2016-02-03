/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt_rounded_up.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 13:58:11 by vbauguen          #+#    #+#             */
/*   Updated: 2015/12/12 14:46:49 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt_rounded_up(int nb)
{
	int i;

	if (nb < 0)
		return (0);
	if (nb > 2147483647)
		return (0);
	while (1)
	{
		i = 0;
		while (i < nb)
		{
			if (i * i == nb)
				return (i);
			i++;
		}
		nb++;
	}
}
