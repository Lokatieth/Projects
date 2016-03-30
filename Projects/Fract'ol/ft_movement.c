/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 12:59:39 by vbauguen          #+#    #+#             */
/*   Updated: 2016/03/22 15:11:29 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"

void	ft_recreate_img(t_id *s)
{
	if (s->img)
		mlx_destroy_image(s->mlx, s->img);
	s->img = mlx_new_image(s->img, W_X, W_Y);
	s->data = mlx_get_data_addr(s->img, &s->bit_per_pixel, &s->s_line,
		&s->endian);
	s->bpp = s->bit_per_pixel / 8;
}

void ft_zoom(t_id *s, int keycode)
{
	if (keycode == 78)
	{
		s->zoom = s->zoom * 1.3;
		ft_recreate_img(s);
		ft_draw_mandelbrot(s);
	}
	if (keycode == 69)
	{
		s->zoom = s->zoom / 1.3;
		ft_recreate_img(s);
		ft_draw_mandelbrot(s);
	}
}

void ft_iteration_ten(t_id *s, int keycode)
{
	if (keycode == 116)
	{
		s->iter_max = s->iter_max + 10;
		ft_recreate_img(s);
		ft_draw_mandelbrot(s);
	}
	if (keycode == 121)
	{
		if (s->iter_max > 10)
			s->iter_max = s->iter_max - 10;
		ft_recreate_img(s);
		ft_draw_mandelbrot(s);
	}
}


void ft_iteration_digit(t_id *s, int keycode)
{
	if (keycode == 115)
	{
		s->iter_max = s->iter_max + 1;
		ft_recreate_img(s);
		ft_draw_mandelbrot(s);
	}
	if (keycode == 119)
	{
		if (s->iter_max > 1)
			s->iter_max = s->iter_max - 1;
		ft_recreate_img(s);
		ft_draw_mandelbrot(s);
	}
}