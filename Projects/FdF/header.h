/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 20:48:17 by vbauguen          #+#    #+#             */
/*   Updated: 2016/02/25 18:20:24 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define BUFF_SIZE 30
# define WIN_HEIGHT 900
# define IMG_HEIGHT WIN_HEIGHT * 4 / 5
# define WIN_WIDTH 1200
# define IMG_WIDTH WIN_WIDTH * 4 / 5
# define WIN_NAME "FDF.42 t(*-*t)"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include <stdio.h>
# include "libft/libft.h"


typedef struct	s_id
{
	double bpp;
	int bit_per_pixel;
	int s_line;
	int endian;
	char *data;
	void *img;
	void *win;
	void *mlx;
	int **map;
	int x0;
	int x1;
	int y1;
	int y0;
	int dx;
	int dy;
	int err;
	int sy;
	int sx;
	int e2;
	int k;
	int i;
	unsigned int color;
}				t_id;


void mlx_image_put_pixel(t_id *s, int x, int y);

void ft_bresenham(int x0, int y0, int x1, int y1, t_id *s);


#endif