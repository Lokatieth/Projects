/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:12:15 by vbauguen          #+#    #+#             */
/*   Updated: 2016/03/17 15:39:28 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void ft_check_arg(char *s)
{
	if (ft_strcmp(s, "Mandelbrot") != 0 && ft_strcmp(s, "Julia") != 0)
	{
		ft_putendl("Usage : \t./fractol Mandelbrot\t./fractol Julia");
		exit(0);
	}
}