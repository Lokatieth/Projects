/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:14:54 by vbauguen          #+#    #+#             */
/*   Updated: 2016/05/30 05:08:42 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF
# define WOLF
# define W_Y 800
# define W_X 1280
# define WIN_NAME "Wolf3d"
# define PI 3.14159265359
# define KeyPress 2
# define KeyPressMask (1L<<0)
# define PointerMotionMask (1L<<6)
# define MotionNotify 6
# define texWidth 64
# define texHeight 64

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include <stdio.h>
# include "libft/libft.h"
# include <math.h>


typedef struct		s_img
{
	int				width;
	int				height;
	char			*buffer;
}					t_img;

typedef struct		s_id
{
	int				texNum;
	double			wallX;
	int				texX;
	int				texY;
	t_img			*wall[10];
	int				display;
	char			**weapon;
	int 			drogue;
	int				level;
	char			**niveau;
	void 			**xpm;
	char			*gun;
	char			*base_wep;
	void			*teleport;
	// void			*gun;
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
	int				nl;
	int				nc;
	int				img_y;
	int				**map;
	double			dirX;
	double			dirY;
	double			Player_PosX;
	double			Player_PosY;
	double			posX;
	double			posY;
	double			planeX;
	double			planeY;
	int				mapHeight;
	int				mapWidth;
	double			cameraX;
	double			rayPosX;
	double			rayPosY;
	double			rayDirX;
	double			rayDirY;
	int				mapX;
	int				mapY;
	double			sideDistY;
	double			sideDistX;
	double			deltaDistX;
	double			perpWallDist;
	double			deltaDistY;
	int				stepX;
	int				stepY;
	int				hit;
	int				side;
	int				lineHeight;
	int				drawStart;
	int				drawEnd;
	int				decalY;
}					t_id;



void				mlx_image_put_pixel(t_id *s, int x, int y, int col);
int					ft_recreate(t_id *s);
int					*ft_parsing(char *str);
int					ft_corps(t_id *s);

#endif
