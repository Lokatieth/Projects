/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 13:08:38 by vbauguen          #+#    #+#             */
/*   Updated: 2016/06/06 15:22:32 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}