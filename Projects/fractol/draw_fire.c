/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fire.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 23:15:35 by vbauguen          #+#    #+#             */
/*   Updated: 2016/05/27 09:55:42 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "fire.h"

void	ft_draw_fire(t_id *s, int x, int y)
{
	static int fire[1200] = {FIRE};

	mlx_image_put_pixel(s, x, y, fire[(int)(fabsl(fmod(s->i * 20 *
		s->z_i, 999)))]);
}
