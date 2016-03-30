/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:10:57 by vbauguen          #+#    #+#             */
/*   Updated: 2016/03/30 11:53:46 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_image_put_pixel(t_id *s, int x, int y, int col)
{
	s->color = mlx_get_color_value(s->mlx, col);
	if (x > 0 && x < W_X && y > 0 && y < W_Y)
		*(unsigned int *)(s->data + ((int)s->bpp * x) +
				(s->s_line * y)) = s->color;
}



int	mouse_reaction(int button, int x, int y, t_id *s)
{
	if (button == 1)
	{
		s->oldx1 = s->x1;
		s->x1 = (x * (s->x2 - s->oldx1) / TAILLE + s->oldx1) - ((s->x2 - s->oldx1) / 4);
		s->x2 = (x * (s->x2 - s->oldx1) / TAILLE + s->oldx1) + ((s->x2 - s->oldx1) / 4);
		s->oldy1 = s->y1;
		s->y1 = (y * (s->y2 - s->oldy1) / TAILLE + s->oldy1) - ((s->y2 - s->oldy1) / 4);
		s->y2 = (y * (s->y2 - s->oldy1) / TAILLE + s->oldy1) + ((s->y2 - s->oldy1) / 4);
		ft_recreate_img(s);
		ft_draw_mandelbrot(s);
	}
 	if (button == 2)
	{
		s->x1 = s->oldx1;
		s->y1 = s->oldy1;
		ft_recreate_img(s);
		ft_draw_mandelbrot(s);
	}

 	return (0);
}

void	ft_first_creation(t_id *s)
{
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, W_X, W_Y, WIN_NAME);
	ft_initialization(s);
	ft_draw_mandelbrot(s);
	mlx_mouse_hook (s->win, mouse_reaction, s);
	mlx_key_hook(s->win, key_reaction, s);
	mlx_loop(s->mlx);
}

int		key_reaction(int keycode, t_id *param)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 69 || keycode == 78)
		ft_zoom(param, keycode);
	if (keycode == 116 || keycode == 121)
		ft_iteration_ten(param, keycode);
	if (keycode == 115 || keycode == 119)
		ft_iteration_digit(param, keycode);
	// printf("%d\n", keycode);

	mlx_put_image_to_window(param->mlx, param->win, param->img, 0, 0);
	return (0);
}

int main(int argc, char **argv)
{
	t_id *s;

	s = (t_id*)malloc(sizeof(t_id) * 100);
	if (argc != 2)
		return (0);
	ft_check_arg(argv[1]);
	ft_first_creation(s);

	return (0);
}



// int	mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);
// {
// 
// }
// 
// int	mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(), void *param);