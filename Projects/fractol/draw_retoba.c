/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_retoba.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 23:15:35 by vbauguen          #+#    #+#             */
/*   Updated: 2016/05/27 11:36:24 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "retoba.h"

void	ft_draw_retoba(t_id *s, int x, int y)
{
	static int retoba[1200] = {RETOBA};

	mlx_image_put_pixel(s, x, y, retoba[(int)(fabsl(fmod(s->i * 20 *
		s->z_i, 999)))]);
}
