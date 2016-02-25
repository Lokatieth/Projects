/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 09:09:13 by vbauguen          #+#    #+#             */
/*   Updated: 2016/02/25 18:20:17 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void ft_display_points(t_id *s)
{	
	int i;
	int j;
	int x;
	int y;
	int hor_dist;
	int ver_dist;
	double dy;

	dy = 0.5;
	j = 0;
	i = 0;
	hor_dist = IMG_WIDTH / s->k;
	ver_dist = IMG_HEIGHT / s->i;
	// printf("hauteur de la fenetre  = %d\n", WIN_HEIGHT);
	// printf("hauteur du tableau d'int  = %d\n", s->i);
	// printf("intervalle vertical entre deux points = %d\n\n", ver_dist);

	// printf("largeur de la fenetre  = %d\n", WIN_WIDTH);
	// printf("largeur du tableau d'int  = %d\n", s->k);
	// printf("intervalle horizontal entre deux points = %d\n", hor_dist);

	y = ver_dist;
	j = 0;
	while (j < s->i)
	{
		x = hor_dist;
		i = 0;
		while (i < s->k)
		{	
			if (x <= IMG_WIDTH - hor_dist)
				ft_bresenham(x, y - s->map[j][i] * dy, x + hor_dist, y - s->map[j][i + 1] * dy, s);
			if (y <= IMG_HEIGHT - ver_dist)
				ft_bresenham(x, y - s->map[j][i] * dy, x, y + s->map[j][i + 1] * dy + ver_dist, s);
			// if (j + 1 < s->i && y <= WIN_HEIGHT - ver_dist  - HEIGHT_MARGIN && x <= WIN_WIDTH - hor_dist - WIDTH_MARGIN)
				// ft_bresenham(x, y - s->map[j][i] * dy, x + hor_dist, y - s->map[j + 1][i + 1] * dy + ver_dist, s, 0x00FFFFFF);
			x = x + hor_dist;
			i++;
		}
		y = y + ver_dist;
		j++;
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img, WIN_WIDTH / 10, WIN_HEIGHT / 10);



}

void ft_bresenham(int x0, int y0, int x1, int y1, t_id *s)
{
	s->dx = ft_abs(x1 - x0);
	s->dy = ft_abs(y1 - y0);
	s->sx = x0 < x1 ? 1 : -1;
	s->sy = y0 < y1 ? 1 : -1;
	s->err = (s->dx > s->dy ? s->dx : -s->dy) / 2;
	while (1)
	{
 	   	mlx_image_put_pixel(s, x0, y0);
    	if (x0 == x1 && y0 == y1)
    		break;
   		s->e2 = s->err;
    	if (s->e2 > -s->dx)
    	{
    		s->err-= s->dy;
    		x0+= s->sx;
    	}
    	if (s->e2 < s->dy)
    	{
    		s->err+= s->dx;
    		y0+= s->sy; 
    	}
	}
}

int key_reaction(int keycode, t_id *param)
{
	// int x;
	// int y;

	if (keycode == 53)
		exit(0);
	if (keycode == 49)
	{
		ft_display_points(param);
	}
	return (0);	
}

int *ft_parsing(char *str)
{
	int *tab;
	int i;
	static int j;
	char **char_to_int;

	tab = (int *)malloc(sizeof(int) * ft_get_number_of_words(str, ' '));
	char_to_int = ft_strsplit(str, ' ');
	j = 0;
	i = -1;
	while (char_to_int[++i])
		tab[i] = ft_atoi(char_to_int[i]);
	return (tab);
}

void mlx_image_put_pixel(t_id *s, int x, int y)
{	
	s->color = mlx_get_color_value (s->mlx, 0xFFFFFF);

	if (x > 0 && x <= IMG_WIDTH && y > 0 && y <= IMG_HEIGHT)
		*(unsigned int *)(s->data + ((int)s->bpp * x) + (s->s_line * y)) = s->color;
}

int main(int argc, char **argv)
{
	t_id s;
	int fd;
	char *line;
	(void)argc;
	int x;
	int y;

	x = 0;
	y = 0;	
	fd = open(argv[1], O_RDONLY);
	s.i = 0;

	while ((get_next_line(fd, &line)) > 0) 
				++s.i;
	s.map = (int **)malloc(sizeof(int *) * s.i);
	s.i = 0;
	close(fd);
	fd = open(argv[1], O_RDONLY);
	while ((get_next_line(fd, &line)) > 0)
	{	
		s.map[s.i] = ft_parsing(line);
		s.k = (int)ft_get_number_of_words(line, ' ');
		s.i++;
	}
	s.mlx = mlx_init();

	s.win = mlx_new_window(s.mlx, WIN_WIDTH, WIN_HEIGHT, WIN_NAME);

	s.img = mlx_new_image(s.mlx, WIN_WIDTH, WIN_HEIGHT);

	s.data = mlx_get_data_addr(s.img, &s.bit_per_pixel, &s.s_line, &s.endian);
	s.bpp = s.bit_per_pixel / 8;

	mlx_key_hook(s.win, key_reaction, &s);

	mlx_loop(s.mlx);

	return (0);
}



























