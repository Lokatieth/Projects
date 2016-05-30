/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bluelet.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/26 23:15:35 by vbauguen          #+#    #+#             */
/*   Updated: 2016/05/27 09:54:58 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "bluelet.h"

void	ft_draw_bluelet(t_id *s, int x, int y)
{
	static int b[1200] = {BLUELET};

	mlx_image_put_pixel(s, x, y, b[(int)(fabsl(fmod(s->i * 20 *
		s->z_i, 999)))]);
}
