/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 20:48:17 by vbauguen          #+#    #+#             */
/*   Updated: 2016/02/10 11:51:54 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define BUFF_SIZE 30
# define WIN_HEIGHT 900
# define HEIGHT_MARGIN WIN_HEIGHT / 5
# define WIN_LENGHT 1200
# define LENGHT_MARGIN WIN_LENGHT / 5
# define WIN_NAME "FDF.42 t(*-*t)"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include <stdio.h>
# include "libft/libft.h"


typedef struct	s_id
{
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
}				t_id;

void ft_bresenham(int x0, int y0, int x1, int y1, t_id *s, int color);


#endif