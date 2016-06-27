/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:14:54 by vbauguen          #+#    #+#             */
/*   Updated: 2016/06/23 19:10:16 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define W_Y 400
# define W_X 400
# define TAILLE 400
# define WIN_NAME "Fractol"
# define POINTERMOTIONMASK (1L<<6)
# define MOTIONNOTIFY 6
# define PI 3.1415
# define KEYPRESS 2
# define KEYPRESSMASK (1L<<0)
# define ZOOMPX (x * (s->x2 - s->oldx1) / TAILLE + s->oldx1)
# define ZOOMPY (y * (s->y2 - s->oldy1) / TAILLE + s->oldy1)

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "minilibx_macos/mlx.h"
# include <stdio.h>
# include "libft/libft.h"
# include <math.h>

typedef struct					s_id
{
	int							int_color;
	int							ext_color;
	long double					bpp;
	int							bit_per_pixel;
	int							s_line;
	int							endian;
	char						*data;
	void						*img;
	void						*win;
	void						*mlx;
	int							color;
	int							img_x;
	int							img_y;
	long double					c_r;
	long double					c_r_base;
	long double					z_r_base;
	long double					z_i_base;
	long double					c_i;
	long double					c_i_base;
	long double					z_r;
	long double					z_i;
	int							i;
	long double					x1;
	long double					x2;
	long double					y1;
	long double					y2;
	long double					tmp;
	int							x;
	int							y;
	long double					zoom;
	int							it_max;
	long double					oldx1;
	long double					oldy1;
	int							fractale;
	int							it;
	int							decaly;
	int							decalx;
	int							mouse_movement;
}								t_id;

void							ft_check_arg(char *str, t_id *s, int argc);
void							ft_draw_mandelbrot(t_id *s);
void							ft_draw_julia(t_id *s);
void							ft_draw(t_id *s);
void							mlx_image_put_pixel(t_id *s, int x, int y,
								int col);
int								key_reaction(int keycode, t_id *param);
void							ft_next_fractale(t_id *s, int keycode);
void							ft_initialization_mandel(t_id *s);
void							ft_initialization_julia(t_id *s);
void							ft_iteration_ten(t_id *s, int keycode);
void							ft_iteration_digit(t_id *s, int keycode);
void							ft_recreate_img(t_id *s);
void							ft_first_creation(t_id *s);
int								ft_julia_mouse(int x, int y, t_id *s);
void							ft_initialization_burning_ship(t_id *s);
void							ft_initialization_custom1(t_id *s);
void							ft_initialization_julibalia(t_id *s);
void							ft_initialization_mandelibal(t_id *s);
void							ft_initialization_kalandra(t_id *s);
void							ft_initialization_root(t_id *s);
void							ft_draw_burning_ship(t_id *s);
void							ft_draw_custom1(t_id *s);
void							ft_draw_julibalia(t_id *s);
void							ft_draw_kalandra(t_id *s);
void							ft_draw_mandelibal(t_id *s);
void							ft_draw_root(t_id *s);
void							ft_draw_bluelet(t_id *s, int x, int y);
void							ft_draw_fire(t_id *s, int x, int y);
void							ft_draw_turgreen(t_id *s, int x, int y);
void							ft_draw_smoke(t_id *s, int x, int y);
void							ft_draw_retoba(t_id *s, int x, int y);
void							ft_draw_golsil(t_id *s, int x, int y);
void							ft_draw_tutobla(t_id *s, int x, int y);
void							ft_choose_interior(t_id *s, int x, int y);
void							ft_choose_exterior(t_id *s, int x, int y);
int								single_press(int keycode, t_id *param);
int								key_reaction(int keycode, t_id *param);
int								mouse_reaction(int button, int x, int y,
								t_id *s);

#endif
