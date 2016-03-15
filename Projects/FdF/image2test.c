/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image2test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 09:09:13 by vbauguen          #+#    #+#             */
/*   Updated: 2016/03/15 09:18:34 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


void ft_display_ver(t_id *s)
{	
	int i;
	int j;
	int ct;

	j = 0;
	i = 0;
	ct = 0;

	while (j < (s->nl - 1))
	{
		i = 0;
		while (i < s->nc)
		{
			s->x0 = W_X/2-(s->nc/2*s->dp)+(i*s->dp)+decalx;
			s->y0 = W_Y/2-(s->nl/2*s->dp)+(j*s->dp)+decaly;
			s->x1 = W_X/2-(s->nc/2*s->dp)+(i*s->dp)+decalx;
			s->y1 = W_Y/2-(s->nl/2*s->dp)+((j+1)*s->dp)+decaly;
			ft_bresenham(s);
			i++;
		}
		j++;
	}
}
void ft_display_hor(t_id *s)
{	
	int i;
	int j;
	int ct;

	j = 0;
	i = 0;
	ct = 0;
	while (j < s->nl)
	{
		i = 0;
		while (i < (s->nc - 1))
		{
			
			s->x0 = W_X/2-(s->nc/2*s->dp)+(i*s->dp);
			s->y0 = W_Y/2-(s->nl/2*s->dp)+(j*s->dp);
			s->x1 = W_X/2-(s->nc/2*s->dp)+((i+1)*s->dp);
			s->y1 = W_Y/2-(s->nl/2*s->dp)+(j*s->dp);
			ft_bresenham(s); 
			i++;
		}
		j++;
	}
}

void ft_bresenham(t_id *s)
{
	s->dx = ft_abs(s->x1 - s->x0);
	s->dy = ft_abs(s->y1 - s->y0);
	s->sx = s->x0 < s->x1 ? 1 : -1;
	s->sy = s->y0 < s->y1 ? 1 : -1;
	s->err = (s->dx > s->dy ? s->dx : -s->dy) / 2;
	while (1)
	{	
 	   	mlx_image_put_pixel(s, s->x0, s->y0);
    	if (s->x0 == s->x1 && s->y0 == s->y1)
    		break;
   		s->e2 = s->err;
    	if (s->e2 > -s->dx)
    	{
    		s->err-= s->dy;
    		s->x0+= s->sx;
    	}
    	if (s->e2 < s->dy)
    	{
    		s->err+= s->dx;
    		s->y0+= s->sy; 
    	}
	}
}

int key_reaction(int keycode, t_id *param)
{
	param->dp = 25;
	if (keycode == 53)
		exit(0);
	if (keycode == 49)
	{
		param->img = mlx_new_image(param->img, W_X, W_Y);
		param->data = mlx_get_data_addr(param->img, &param->bit_per_pixel, &param->s_line, &param->endian);
		param->bpp = param->bit_per_pixel / 8;
		ft_display_hor(param);
		ft_display_ver(param);
	}
	if (keycode == 69)
	{
		mlx_destroy_image(param->mlx, param->img);
		param->img = mlx_new_image(param->img, W_X, W_Y);
		param->data = mlx_get_data_addr(param->img, &param->bit_per_pixel, &param->s_line, &param->endian);
		param->bpp = param->bit_per_pixel / 8;
		param->dp = param->dp + 5;
		ft_display_ver(param);
		ft_display_hor(param);
	}
	if (keycode == 78)
	{
		mlx_destroy_image(param->mlx, param->img);
		param->img = mlx_new_image(param->img, W_X, W_Y);
		param->data = mlx_get_data_addr(param->img, &param->bit_per_pixel, &param->s_line, &param->endian);
		param->bpp = param->bit_per_pixel / 8;
		param->dp = param->dp - 5;
		ft_display_ver(param);
		ft_display_hor(param);
	}
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
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

	if (x > 0 && x <= W_X && y > 0 && y <= W_Y)
		*(unsigned int *)(s->data + ((int)s->bpp * x) + (s->s_line * y)) = s->color;
}

int main(int argc, char **argv)
{
	t_id s;
	int fd;
	char *line;
	(void)argc;

	fd = open(argv[1], O_RDONLY);
	s.nl = 0;

	while ((get_next_line(fd, &line)) > 0) 
				++s.nl;
	s.map = (int **)malloc(sizeof(int *) * s.nl);
	s.nl = 0;
	close(fd);
	fd = open(argv[1], O_RDONLY);
	while ((get_next_line(fd, &line)) > 0)
	{	
		s.map[s.nl] = ft_parsing(line);
		s.nc = (int)ft_get_number_of_words(line, ' ');
		s.nl++;
	}
	s.mlx = mlx_init();
	s.win = mlx_new_window(s.img, W_X, W_Y, WIN_NAME);
	

	mlx_key_hook(s.win, key_reaction, &s);
	mlx_loop(s.mlx);
	return (0);
}



























