/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_images.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:56:49 by vbauguen          #+#    #+#             */
/*   Updated: 2016/03/18 11:30:23 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_recreate_img(t_id *s)
{
	if (s->img)
		mlx_destroy_image(s->mlx, s->img);
	s->img = mlx_new_image(s->img, W_X, W_Y);
	s->data = mlx_get_data_addr(s->img, &s->bit_per_pixel, &s->s_line,
		&s->endian);
	s->bpp = s->bit_per_pixel / 8;
}

void	ft_display_ver(t_id *s)
{
	int i;
	int j;

	j = 0;
	while (j < (s->nl - 1))
	{
		i = 0;
		while (i < s->nc)
		{
			s->y0 = W_Y / 2 - (s->nl / 2 * s->dp) + (j * s->dp) + s->decaly
				- s->map[j][i] * s->decalz;
			s->y1 = W_Y / 2 - (s->nl / 2 * s->dp) + ((j + 1) * s->dp)
				+ s->decaly;
			s->x0 = W_X / 2 - (s->nc / 2 * s->dp) + (i * s->dp) + s->decalx
				+ s->slide * s->y0;
			s->x1 = W_X / 2 - (s->nc / 2 * s->dp) + (i * s->dp) + s->decalx
				+ s->slide * s->y1;
			ft_color_vertical(s, i, j);
			ft_bresenham(s, s->col);
			i++;
		}
		j++;
	}
}

void	ft_display_hor(t_id *s)
{
	int i;
	int j;

	j = 0;
	while (j < s->nl)
	{
		i = 0;
		while (i < (s->nc - 1))
		{
			s->y0 = W_Y / 2 - (s->nl / 2 * s->dp) + (j * s->dp) + s->decaly
				- s->map[j][i] * s->decalz;
			s->y1 = W_Y / 2 - (s->nl / 2 * s->dp) + (j * s->dp) + s->decaly
				- s->map[j][i + 1] * s->decalz;
			s->x0 = W_X / 2 - (s->nc / 2 * s->dp) + (i * s->dp) + s->decalx
				+ s->slide * s->y0;
			s->x1 = W_X / 2 - (s->nc / 2 * s->dp) + ((i + 1) * s->dp)
				+ s->decalx + s->slide * s->y1;
			ft_color_horizontal(s, i, j);
			ft_bresenham(s, s->col);
			i++;
		}
		j++;
	}
}

void	ft_initialization(t_id *s)
{
	s->dp = 25;
	s->decalz = 0.2;
	s->slide = 0.2;
	s->img = mlx_new_image(s->mlx, W_X, W_Y);
	s->data = mlx_get_data_addr(s->img, &s->bit_per_pixel, &s->s_line,
			&s->endian);
	s->bpp = s->bit_per_pixel / 8;
	ft_display_hor(s);
	ft_display_ver(s);
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
}

void	ft_first_creation(t_id s)
{
	s.mlx = mlx_init();
	s.win = mlx_new_window(s.mlx, W_X, W_Y, WIN_NAME);
	ft_initialization(&s);
	mlx_key_hook(s.win, key_reaction, &s);
	mlx_loop(s.mlx);
}
