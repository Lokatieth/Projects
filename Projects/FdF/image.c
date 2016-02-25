/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 09:09:13 by vbauguen          #+#    #+#             */
/*   Updated: 2016/02/25 15:34:42 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// void ft_display_points(t_id *s)
// {	
// 	int i;
// 	int j;
// 	int x;
// 	int y;
// 	int hor_dist;
// 	int ver_dist;
// 	double dy;
// 	int color;

// 	dy = 4;
// 	j = 0;
// 	i = 0;
// 	hor_dist = (WIN_WIDTH - 2 * WIDTH_MARGIN) / s->k;
// 	ver_dist = (WIN_HEIGHT - 2 * HEIGHT_MARGIN) / s->i;
// 	printf("hauteur de la fenetre  = %d\n", WIN_HEIGHT);
// 	printf("hauteur du tableau d'int  = %d\n", s->i);
// 	printf("intervalle vertical entre deux points = %d\n\n", ver_dist);

// 	printf("largeur de la fenetre  = %d\n", WIN_WIDTH);
// 	printf("largeur du tableau d'int  = %d\n", s->k);
// 	printf("intervalle horizontal entre deux points = %d\n", hor_dist);

// 	y = ver_dist + HEIGHT_MARGIN;
// 	j = 0;
// 	while (j < s->i)
// 	{
// 		x = hor_dist + WIDTH_MARGIN;
// 		i = 0;
// 		while (i < s->k)
// 		{	
// 			if (s->map[j][i] > 5 || s->map[j][i + 1] > 5)
// 				color = 0x00FF0000;
// 			else
// 				color = 0x00FFFFFF;
// 			if (x <= WIN_WIDTH - hor_dist - WIDTH_MARGIN)
// 				ft_bresenham(x, y - s->map[j][i] * dy, x + hor_dist, y - s->map[j][i + 1] * dy, s, color);
// 			}
// 			if (y <= WIN_HEIGHT - ver_dist - HEIGHT_MARGIN)
// 				ft_bresenham(x, y - s->map[j][i] * dy, x, y + s->map[j][i + 1] * dy + ver_dist, s, color);
// 			// if (j + 1 < s->i && y <= WIN_HEIGHT - ver_dist  - HEIGHT_MARGIN && x <= WIN_WIDTH - hor_dist - WIDTH_MARGIN)
// 				// ft_bresenham(x, y - s->map[j][i] * dy, x + hor_dist, y - s->map[j + 1][i + 1] * dy + ver_dist, s, 0x00FFFFFF);
// 			x = x + hor_dist;
// 			i++;
// 		}
// 		y = y + ver_dist;
// 		j++;
// 	}



// }

void ft_bresenham(int x0, int y0, int x1, int y1, t_id *s, int color)
{
	s->dx = ft_abs(x1 - x0);
	s->dy = ft_abs(y1 - y0);
	s->sx = x0 < x1 ? 1 : -1;
	s->sy = y0 < y1 ? 1 : -1;
	s->err = (s->dx > s->dy ? s->dx : -s->dy) / 2;
	while (1)
	{
 	   mlx_pixel_put(s->mlx, s->win, x0, y0, color);
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

	if (keycode == 53)
		exit(0);
	if (keycode == 49)
		// ft_display_points(param);
		printf("Bpp = %d, s_line = %d, endian = %d\n", param->bpp, param->s_line, param->endian);
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


int main(int argc, char **argv)
{
	t_id s;
	int fd;
	char *line;
	// int i;
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
	s.img = mlx_new_image(s.mlx, 4/5 * WIN_WIDTH, 4/5 * WIN_HEIGHT);
	s.data = mlx_get_data_addr(s.img, &s.bpp, &s.s_line, &s.endian);

	mlx_key_hook(s.win, key_reaction, &s);
	mlx_loop(s.mlx);
	return (0);
}



// *(unsigned int *)(s->data + bpp * x /+- size_line * y) = s->color



// s.color = mlx_get_color_value (s.mlx, 0x00FFFF);



















