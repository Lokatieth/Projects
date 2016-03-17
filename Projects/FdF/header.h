/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 20:48:17 by vbauguen          #+#    #+#             */
/*   Updated: 2016/03/17 13:13:25 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define BUFF_SIZE 30
# define W_Y 900
# define W_X 1200
# define WIN_NAME "FDF.42 t(*-*t)"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include <stdio.h>
# include "libft/libft.h"

typedef struct		s_id
{
	int				dp;
	double			bpp;
	int				bit_per_pixel;
	int				s_line;
	int				endian;
	char			*data;
	void			*img;
	void			*win;
	void			*mlx;
	int				**map;
	int				x0;
	int				x1;
	int				y1;
	int				y0;
	int				dx;
	int				dy;
	int				err;
	int				sy;
	int				sx;
	int				e2;
	int				nc;
	int				nl;
	unsigned int	color;
	int				decaly;
	int				decalx;
	double			decalz;
	double			slide;
	int				col;
}					t_id;

int					ft_fdf_check(char *str);
void				ft_first_creation(t_id s);
int					key_reaction(int keycode, t_id *param);
void				mlx_image_put_pixel(t_id *s, int x, int y, int col);
void				ft_zoom(t_id *param, int keycode);
void				ft_move_hor(t_id *param, int keycode);
void				ft_move_ver(t_id *param, int keycode);
void				ft_leveling(t_id *param, int keycode);
void				ft_horizontal_shift(t_id *param, int keycode);
void				ft_bresenham(t_id *s, int col);
void				ft_recreate_img(t_id *s);
void				ft_display_ver(t_id *s);
void				ft_display_hor(t_id *s);
void				ft_initialization(t_id *s);
void				ft_error();
void				ft_color_vertical(t_id *s, int i, int j);
void				ft_color_horizontal(t_id *s, int i, int j);

#endif
