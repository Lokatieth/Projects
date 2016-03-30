/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 12:11:41 by vbauguen          #+#    #+#             */
/*   Updated: 2016/03/30 12:47:35 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


void    ft_initialization(t_id *s)
{
    s->x1 = -2.1;
    s->x2 = 0.6;
    s->y1 = -1.2;
    s->y2 = 1.2;
    s->iter_max = 50;
    s->zoom = 1;
    s->oldx1 = s->x1;
    s->oldy1 = s->y1;
    s->img = mlx_new_image(s->mlx, W_X, W_Y);
    s->data = mlx_get_data_addr(s->img, &s->bit_per_pixel, &s->s_line,
            &s->endian);
    s->bpp = s->bit_per_pixel / 8;
}

int rgb_d(int red, int green, int blue)
{
    int rest;

    rest = 0;
    if (red < 256 && red >= 0 && green < 256 && green >= 0 && blue < 256 && blue >= 0)
        rest = blue + 256 * green + 256 * 256 * red;
    return (rest);
}

void ft_draw_mandelbrot(t_id *s)
{
	
	int x;
	int y;

	for (x = 0; x < W_X; x++)
	{
    	for (y = 0; y < W_Y; y++)
    	{
        	s->c_r = (x * (s->x2-s->x1) / W_X + s->x1) * s->zoom;
        	s->c_i = (y * (s->y2-s->y1) / W_Y + s->y1) * s->zoom;
        	s->z_r = 0;
        	s->z_i = 0;
        	s->i = 0;

        	do
        	{
            	double tmp = s->z_r;
            	s->z_r = s->z_r*s->z_r - s->z_i*s->z_i + s->c_r;
            	s->z_i = 2*s->z_i*tmp + s->c_i;
            	s->i = s->i+1;
            }
        	while (s->z_r*s->z_r + s->z_i*s->z_i < 4 && s->i < s->iter_max);

        	if (s->i == s->iter_max)
            	mlx_image_put_pixel(s, x, y, 0x000000);
        	else
                mlx_image_put_pixel(s, x, y , s->i * rgb_d(0,255,200)/s->iter_max);

    	}
	}
    mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);

}
