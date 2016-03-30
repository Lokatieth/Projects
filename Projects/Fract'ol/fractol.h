/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:14:54 by vbauguen          #+#    #+#             */
/*   Updated: 2016/03/30 11:51:15 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define W_Y 1600
# define W_X 1600
# define TAILLE 1600	
# define WIN_NAME "Fractol"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include <stdio.h>
# include "libft/libft.h"

typedef struct		s_id
{
	double			bpp;
	int				bit_per_pixel;
	int				s_line;
	int				endian;
	char			*data;
	void			*img;
	void			*win;
	void			*mlx;
	int				color;
	int 			img_x;
	int				img_y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	int 			i;
	double 			x1;
	double 			x2;
	double 			y1;
	double 			y2;
	double 			tmp;
	int 			x;
	int 			y;
	double 			zoom;
	int 			iter_max;
	double			oldx1;
	double			oldy1;
}					t_id;

void				ft_check_arg(char *s);
void 				ft_julia(t_id *s);
void 				ft_draw_mandelbrot(t_id *s);
void				mlx_image_put_pixel(t_id *s, int x, int y, int col);
int					key_reaction(int keycode, t_id *param);
void 				ft_zoom(t_id *s, int keycode);
void 				ft_initialization(t_id *s);
void 				ft_iteration_ten(t_id *s, int keycode);
void 				ft_iteration_digit(t_id *s, int keycode);
void				ft_recreate_img(t_id *s);


#endif
