/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 09:09:13 by vbauguen          #+#    #+#             */
/*   Updated: 2016/03/16 15:27:52 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_bresenham(t_id *s, int col)
{
	s->dx = ft_abs(s->x1 - s->x0);
	s->dy = ft_abs(s->y1 - s->y0);
	s->sx = s->x0 < s->x1 ? 1 : -1;
	s->sy = s->y0 < s->y1 ? 1 : -1;
	s->err = (s->dx > s->dy ? s->dx : -s->dy) / 2;
	while (1)
	{
		mlx_image_put_pixel(s, s->x0, s->y0, col);
		if (s->x0 == s->x1 && s->y0 == s->y1)
			break ;
		s->e2 = s->err;
		if (s->e2 > -s->dx)
		{
			s->err = s->err - s->dy;
			s->x0 = s->x0 + s->sx;
		}
		if (s->e2 < s->dy)
		{
			s->err = s->err + s->dx;
			s->y0 = s->y0 + s->sy;
		}
	}
}

int		key_reaction(int keycode, t_id *param)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69 || keycode == 78)
		ft_zoom(param, keycode);
	if (keycode == 124 || keycode == 123)
		ft_move_hor(param, keycode);
	if (keycode == 126 || keycode == 125)
		ft_move_ver(param, keycode);
	if (keycode == 116 || keycode == 121)
		ft_leveling(param, keycode);
	if (keycode == 43 || keycode == 47)
		ft_horizontal_shift(param, keycode);
	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
	return (0);
}

int		*ft_parsing(char *str)
{
	int			*tab;
	int			i;
	static int	j;
	char		**char_to_int;

	tab = (int *)malloc(sizeof(int) * ft_get_number_of_words(str, ' '));
	char_to_int = ft_strsplit(str, ' ');
	j = 0;
	i = -1;
	while (char_to_int[++i])
		tab[i] = ft_atoi(char_to_int[i]);
	return (tab);
}

void	mlx_image_put_pixel(t_id *s, int x, int y, int col)
{
	s->color = mlx_get_color_value(s->mlx, col);
	if (x > 0 && x < W_X && y > 0 && y < W_Y)
		*(unsigned int *)(s->data + ((int)s->bpp * x) +
				(s->s_line * y)) = s->color;
}

int		main(int argc, char **argv)
{
	t_id	s;
	int		fd;
	char	*line;

	(void)argc;
	if (ft_fdf_check(argv[1]) == 0)
		ft_error();
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
	ft_first_creation(s);
	return (0);
}
