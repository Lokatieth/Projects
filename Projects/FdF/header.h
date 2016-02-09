/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 20:48:17 by vbauguen          #+#    #+#             */
/*   Updated: 2016/02/09 14:38:37 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define BUFF_SIZE 30
# define WIN_HEIGHT 900
# define WIN_LENGHT 1200
# define WIN_NAME "ALLEZ TOUS BOUFFER DES QUEUES BANDE DE GARGOUILLEURS DE BITE !"

# include <fcntl.h>
# include <unistd.h>
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