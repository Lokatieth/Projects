/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:57:51 by vbauguen          #+#    #+#             */
/*   Updated: 2016/05/30 07:09:28 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

// effet bourre ; mlx_image_put_pixel(s, x, y, 0x0000ff * sqrt(x * x * y * y) / (105 * y * x));
				// mlx_image_put_pixel(s, x, W_Y - y + (3), 0x16B84E * sqrt(y * y * x) / 50 * x * y); 
int ft_rgb_shading(int color, int perc_opa)
{
	int r;
	int g;
	int b;

	b = color /	65536;
	g = (color - b * 65536) / 256;
	r = color - b * 65536 - g * 256;

	b = b * perc_opa / 100;	
	g = g * perc_opa / 100;	
	r = r * perc_opa / 100;

	return (b + 256 * g + 256 * 256 * r);
}

int 	getcolor(t_img *img, int x, int y, int fade)
{
	int color;
	int c;

	fade /= 8;
	c = (y * img->width + x) * 4;
	color = img->buffer[c];
	if (color == -120 && img->buffer[c + 1] == 0 && img->buffer[c + 2] == -104)
		return (256 * 256 * 256 + 256 * 256 + 256);
	color += img->buffer[c + 1] * 256;
	color += img->buffer[c + 2] * 256 * 256;
	return (color);
}

int mouse_reaction_click(int button, int x, int y, t_id *s)
{
	int i;

	i = 0;
	(void)x;
	(void)y;
	if (button == 1 || button == 4 || button == 5)
	{
			s->display++;
			ft_recreate(s);
	}
	return (0);
}


int ft_next_map(t_id *s)
{
	int		fd;
	char	*line;

	s->level++;
	s->posX = 3;
	s->posY = 3;

	fd = open(s->niveau[s->level], O_RDONLY);
	s->nl = 0;
	while ((get_next_line(fd, &line)) > 0)
		++s->nl;
	s->map = (int **)malloc(sizeof(int *) * s->nl);
	s->nl = 0;
	close(fd);
	fd = open(s->niveau[s->level], O_RDONLY);
	while ((get_next_line(fd, &line)) > 0)
	{
		s->map[s->nl] = ft_parsing(line);
		s->nc = ft_get_number_of_words(line, ' ');
		s->nl++;
	}
	close(fd);
	ft_corps(s);
	return (0);
}

int ft_movement(int keycode, t_id *s)
{	

	if (keycode == 36)
	{
		printf("Position X du joueur = %d\n", (int)s->posX);
		printf("Position Y du joueur = %d\n", (int)s->posY);
	}
	if (keycode == 17 && s->map[(int)s->posX][(int)s->posY] == 5)
		ft_next_map(s);


	if (keycode == 12)
    {
      if(s->map[(int)(s->posX + s->dirX * 0.10)][(int)(s->posY)] == 0 ||
      	s->map[(int)(s->posX + s->dirX * 0.10)][(int)(s->posY)] == 5)
     	 	s->posX += s->dirX * 0.10;
      if(s->map[(int)(s->posX)][(int)(s->posY + s->dirY * 0.10)] == 0 ||
      	s->map[(int)(s->posX)][(int)(s->posY + s->dirY * 0.10)] == 5)
      		s->posY += s->dirY * 0.10;
      if(s->map[(int)(s->posX - s->dirY * 0.10)][(int)(s->posY)] == 0 ||
      	s->map[(int)(s->posX - s->dirY * 0.10)][(int)(s->posY)] == 5)
      	s->posX -= s->dirY * 0.10;
      if(s->map[(int)(s->posX)][(int)(s->posY + s->dirX * 0.10)] == 0 ||
      	s->map[(int)(s->posX)][(int)(s->posY + s->dirX * 0.10)] == 5)
      	s->posY += s->dirX * 0.10;
    }
    if (keycode == 14)
    {
    	if(s->map[(int)(s->posX + s->dirX * 0.15)][(int)(s->posY)] == 0 ||
      	s->map[(int)(s->posX + s->dirX * 0.15)][(int)(s->posY)] == 5)
     	 	s->posX += s->dirX * 0.15;
      	if(s->map[(int)(s->posX)][(int)(s->posY + s->dirY * 0.15)] == 0 ||
      	s->map[(int)(s->posX)][(int)(s->posY + s->dirY * 0.15)] == 5)
      		s->posY += s->dirY * 0.15;
      	if(s->map[(int)(s->posX + s->dirY * 0.15)][(int)(s->posY)] == 0 ||
      	s->map[(int)(s->posX + s->dirY * 0.15)][(int)(s->posY)] == 5)
      		s->posX += s->dirY * 0.15;
     	if(s->map[(int)(s->posX)][(int)(s->posY - s->dirX * 0.15)] == 0 ||
      	s->map[(int)(s->posX)][(int)(s->posY - s->dirX * 0.15)] == 5)
      		s->posY -= s->dirX * 0.15;
    }
	if (keycode == 126 || keycode == 13)
    {
      if(s->map[(int)(s->posX + s->dirX * 0.15)][(int)(s->posY)] == 0 ||
      	s->map[(int)(s->posX + s->dirX * 0.15)][(int)(s->posY)] == 5)
     	 	s->posX += s->dirX * 0.15;
      if(s->map[(int)(s->posX)][(int)(s->posY + s->dirY * 0.15)] == 0 ||
      	s->map[(int)(s->posX)][(int)(s->posY + s->dirY * 0.15)] == 5)
      		s->posY += s->dirY * 0.15;
    }
    if (keycode == 125 || keycode == 1)
    {
      if(s->map[(int)(s->posX - s->dirX * 0.15)][(int)(s->posY)] == 0 ||
      	s->map[(int)(s->posX - s->dirX * 0.15)][(int)(s->posY)] == 5)
      	s->posX -= s->dirX * 0.15;
      if(s->map[(int)(s->posX)][(int)(s->posY - s->dirY * 0.15)] == 0 ||
      	s->map[(int)(s->posX)][(int)(s->posY - s->dirY * 0.15)] == 5)
      	s->posY -= s->dirY * 0.15;
    }
    if (keycode == 0)
    {
      if(s->map[(int)(s->posX - s->dirY * 0.15)][(int)(s->posY)] == 0 ||
      	s->map[(int)(s->posX - s->dirY * 0.15)][(int)(s->posY)] == 5)
      	s->posX -= s->dirY * 0.15;
      if(s->map[(int)(s->posX)][(int)(s->posY + s->dirX * 0.15)] == 0 ||
      	s->map[(int)(s->posX)][(int)(s->posY + s->dirX * 0.15)] == 5)
      	s->posY += s->dirX * 0.15;
	}
	if (keycode == 2)
    {
     	if(s->map[(int)(s->posX + s->dirY * 0.15)][(int)(s->posY)] == 0 ||
      	s->map[(int)(s->posX + s->dirY * 0.15)][(int)(s->posY)] == 5)
      		s->posX += s->dirY * 0.15;
     	if(s->map[(int)(s->posX)][(int)(s->posY - s->dirX * 0.15)] == 0 ||
      	s->map[(int)(s->posX)][(int)(s->posY - s->dirX * 0.15)] == 5)
      		s->posY -= s->dirX * 0.15;
	}
	if (keycode == 123)
    {
      double oldDirX = s->dirX;
      s->dirX = s->dirX * cos(0.04) - s->dirY * sin(0.04);
      s->dirY = oldDirX * sin(0.04) + s->dirY * cos(0.04);
      double oldPlaneX = s->planeX;
      s->planeX = s->planeX * cos(0.04) - s->planeY * sin(0.04);
      s->planeY = oldPlaneX * sin(0.04) + s->planeY * cos(0.04);
	}
	if (keycode == 124)
    {
      double oldDirX = s->dirX;
      s->dirX = s->dirX * cos(-0.04) - s->dirY * sin(-0.04);
      s->dirY = oldDirX * sin(-0.04) + s->dirY * cos(-0.04);
      double oldPlaneX = s->planeX;
      s->planeX = s->planeX * cos(-0.04) - s->planeY * sin(-0.04);
      s->planeY = oldPlaneX * sin(-0.04) + s->planeY * cos(-0.04);
	}
    ft_recreate(s);
    return (0);
}

int key_reaction(int keycode, t_id *s)
{
	if (keycode == 53)
		exit(0);
	(void)s;
    ft_recreate(s);
	return (0);
}

int mouse_reaction(int x, int y, t_id *s)
{
	double angleRelX;
	(void)y;
	if (y > 0 && y < W_Y)
		s->decalY = 150 - 300 * ((double)y / (double)W_Y);
	angleRelX = 360 - ((x % W_X) * 360 / W_X);
	s->dirX = cos(angleRelX * PI / 180);
	s->dirY = sin(angleRelX * PI / 180);
	s->planeX = 0.66 * s->dirY;
	s->planeY = -0.66 * s->dirX;
    ft_recreate(s);
	return (0);
}

// void ft_draw_vertical_line(int x, t_id *s)
// {
// 	int y;
// 	// int i = 0;
// 	// int w = 0;

// 	if (s->map[s->mapX][s->mapY] == 1)
// 		s->color = 0xFF00FF;
// 	else if (s->map[s->mapX][s->mapY] == 2)
// 		s->color = 0xFFFF00;
// 	else if (s->map[s->mapX][s->mapY] == 3)
// 		s->color = 0xFF0000;
// 	else if (s->map[s->mapX][s->mapY] == 4)
// 		s->color = 0xFFFFFF;
// 	else if (s->map[s->mapX][s->mapY] == 5)
// 		s->color = 0x20214f;
// 	else
// 		s->color = 0x145236;

// 	if (s->side == 1)
// 		s->color = (s->color >> 1) & 8355711;
// 	y = s->drawStart;
// 	while (y < s->drawEnd)
// 	{
// 		mlx_image_put_pixel(s, x, y + s->decalY, s->color);
// 		y++;
// 	}
	
// 	while (y < W_Y)
// 	{
// 		mlx_image_put_pixel(s, x, y + s->decalY, 0x169514);
// 		mlx_image_put_pixel(s, x, (W_Y - y) + s->decalY, 0x16B8FF); 
// 		y++;
// 	}
// }

int ft_corps(t_id *s)
{
	int x = -1;
	int x2;
	int y2;

	while (++x < W_X) 
	{
		s->cameraX = 2 * x / (double)W_X - 1;
		s->rayPosX = s->posX;
		s->rayPosY = s->posY;
		s->rayDirX = s->dirX + s->planeX * s->cameraX;
		s->rayDirY = s->dirY + s->planeY * s->cameraX;

		s->mapX = (int)s->rayPosX;
		s->mapY = (int)s->rayPosY;

		s->deltaDistX =  sqrt(1 + (s->rayDirY * s->rayDirY) / (s->rayDirX * s->rayDirX));
		s->deltaDistY =  sqrt(1 + (s->rayDirX * s->rayDirX) / (s->rayDirY * s->rayDirY));

		s->hit = 0;

		if (s->rayDirX < 0)
		{
			s->stepX = -1;
			s->sideDistX = (s->rayPosX - s->mapX) * s->deltaDistX;
		}
		else
		{
			s->stepX = 1;
			s->sideDistX = (s->mapX + 1.0 - s->rayPosX) * s->deltaDistX;
		}
		if (s->rayDirY < 0)
		{
			s->stepY = -1;
			s->sideDistY = (s->rayPosY - s->mapY) * s->deltaDistY;
		}
		else
		{
			s->stepY = 1;
			s->sideDistY = (s->mapY + 1.0 - s->rayPosY) * s->deltaDistY;
		}
		while (s->hit == 0)
		{
			if (s->sideDistX < s->sideDistY)
			{
				s->sideDistX += s->deltaDistX;
				s->mapX += s->stepX;
				s->side = 0;
			}
			else
			{
				s->sideDistY += s->deltaDistY;
				s->mapY += s->stepY;
				s->side = 1;
			}
			if (s->map[s->mapX][s->mapY] > 0 || s->map[s->mapX][s->mapY] == -1)
				s->hit = 1;
		}
		if (s->side == 0)
			s->perpWallDist = (s->mapX - s->rayPosX + (1 - s->stepX) / 2) / s->rayDirX;
		else
			s->perpWallDist = (s->mapY - s->rayPosY + (1 - s->stepY) / 2) / s->rayDirY;

		s->lineHeight = (int)(W_Y / s->perpWallDist);

		s->drawStart = -s->lineHeight / 2 + W_Y / 2;
		if (s->drawStart < 0)
			s->drawStart = 0;
		s->drawEnd = s->lineHeight / 2 + W_Y / 2;
		if (s->drawEnd >= W_Y)
			s->drawEnd = W_Y - 1;

		s->texNum = s->map[s->mapX][s->mapY] - 1;
		if (s->side ==0)
			s->wallX = s->rayPosY + s->perpWallDist * s->rayDirY;
		else
			s->wallX = s->rayPosX + s->perpWallDist * s->rayDirX;
		s->wallX -= floor((s->wallX));

		s->texX = (int)(s->wallX * (double)texWidth);
		if (s->side == 0 && s->rayDirX > 0)
			s->texX = texWidth - s->texX - 1;
		if (s->side == 1 && s->rayDirY < 0)
			s->texX = texWidth - s->texX - 1;

		for (int y = s->drawStart; y < s->drawEnd; y++)
		{
			int d = y * 256 - W_Y * 128 + s->lineHeight * 128;
			s->texY = ((d * texHeight) / s->lineHeight) / 256;
			int colo = getcolor(s->wall[s->texNum], s->texX, s->texY, 0);

			// if (s->side == 1)
				colo = (colo >> 1) & 8355711;
				// colo = ft_rgb_shading(colo, 150);
			mlx_image_put_pixel(s, x, y + s->decalY, colo);
		}
		double floorXWall, floorYWall;

		if (s->side == 0 && s->rayDirX > 0)
		{
			floorXWall = s->mapX;
			floorYWall = s->mapY + s->wallX;
		}
		else if (s->side == 0 && s->rayDirX < 0)
		{
			floorXWall = s->mapX + 1.0;
			floorYWall = s->mapY + s->wallX;
		}
		else if (s->side == 1 && s->rayDirY > 0)
		{
			floorXWall = s->mapX + s->wallX;
			floorYWall = s->mapY;
		}
		else
		{
			floorXWall = s->mapX + s->wallX;
			floorYWall = s->mapY + 1.0;
		}
		double distWall, distPlayer, currentDist;

    	distWall = s->perpWallDist;
    	distPlayer = 0.0;

      	if (s->drawEnd < 0)
      		s->drawEnd = W_Y;
      	for(int y = s->drawEnd + 1; y < W_Y - s->decalY; y++)
      	{
      		int floor_color;
      		int ceiling_color;

        	currentDist = W_Y / (2.0 * y - W_Y); //you could make a small lookup table for this instead
        	double weight = (currentDist - distPlayer) / (distWall - distPlayer);

        	double currentFloorX = weight * floorXWall + (1.0 - weight) * s->posX;
        	double currentFloorY = weight * floorYWall + (1.0 - weight) * s->posY;

        	int floorTexX, floorTexY;
        	floorTexX = (int)(currentFloorX * texWidth) % texWidth;
        	floorTexY = (int)(currentFloorY * texHeight) % texHeight;


        	floor_color = getcolor(s->wall[1], floorTexX, floorTexY, 64);
        	floor_color = (floor_color >> 1) & 8355711;

        	ceiling_color = getcolor(s->wall[5], floorTexX, floorTexY, 64);

        	mlx_image_put_pixel(s, x, y + s->decalY, floor_color);
        	// mlx_image_put_pixel(s, x, + s->decalY + W_Y - y, ceiling_color);
		}
		for(int y = s->drawEnd + 1; y - s->decalY < W_Y; y++)
      	{
      		int floor_color;
      		int ceiling_color;

        	currentDist = W_Y / (2.0 * y - W_Y); //you could make a small lookup table for this instead
        	double weight = (currentDist - distPlayer) / (distWall - distPlayer);

        	double currentFloorX = weight * floorXWall + (1.0 - weight) * s->posX;
        	double currentFloorY = weight * floorYWall + (1.0 - weight) * s->posY;

        	int floorTexX, floorTexY;
        	floorTexX = (int)(currentFloorX * texWidth) % texWidth;
        	floorTexY = (int)(currentFloorY * texHeight) % texHeight;


        	floor_color = getcolor(s->wall[1], floorTexX, floorTexY, 64);
        	floor_color = (floor_color >> 1) & 8355711;

        	ceiling_color = getcolor(s->wall[5], floorTexX, floorTexY, 64);

        	// mlx_image_put_pixel(s, x, y + s->decalY, floor_color);
        	mlx_image_put_pixel(s, x, + s->decalY + W_Y - y, ceiling_color);
		}
	}	
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	mlx_put_image_to_window(s->mlx, s->win, s->xpm[s->display % 7], W_X / 2, W_Y - (125 + ((s->display % 7) * 15)));

	if (s->map[(int)s->posX][(int)s->posY] == 5)
	{
		s->teleport = malloc(sizeof(void*));
		s->teleport = mlx_xpm_file_to_image(s->mlx, "Textures/teleport_icon.xpm", &x2, &y2);
		mlx_put_image_to_window(s->mlx, s->win, s->teleport, W_X / 2 - 100, W_Y / 2 - 100);
	}
	return (0);

}

void	ft_initialisation(t_id *s)
{
	int x;
	int y;
	int width;
	int height;
	s->display = 0;
	s->planeX = 0;
	s->planeY = 0.66 ;
	s->dirX = -1;
	s->dirY = 0;
	s->level = 0;
	s->img = mlx_new_image(s->mlx, W_X, W_Y);
	s->data = mlx_get_data_addr(s->img, &s->bit_per_pixel, &s->s_line,
			&s->endian);
	s->bpp = s->bit_per_pixel / 8;
	s->xpm = (void**)malloc(sizeof(void*) * 10);
	s->xpm[0] = mlx_xpm_file_to_image(s->mlx, s->weapon[0], &x, &y);
	s->xpm[1] = mlx_xpm_file_to_image(s->mlx, s->weapon[1], &x, &y);
	s->xpm[2] = mlx_xpm_file_to_image(s->mlx, s->weapon[2], &x, &y);
	s->xpm[3] = mlx_xpm_file_to_image(s->mlx, s->weapon[3], &x, &y);
	s->xpm[4] = mlx_xpm_file_to_image(s->mlx, s->weapon[4], &x, &y);
	s->xpm[5] = mlx_xpm_file_to_image(s->mlx, s->weapon[5], &x, &y);
	s->xpm[6] = mlx_xpm_file_to_image(s->mlx, s->weapon[6], &x, &y);
	s->wall[0] = mlx_xpm_file_to_image(s->mlx, "Textures/bluestone.xpm", &width, &height);
	s->wall[1] = mlx_xpm_file_to_image(s->mlx, "Textures/mossy.xpm", &width, &height);
	s->wall[2] = mlx_xpm_file_to_image(s->mlx, "Textures/eagle.xpm", &width, &height);
	s->wall[3] = mlx_xpm_file_to_image(s->mlx, "Textures/greystone.xpm", &width, &height);
	s->wall[4] = mlx_xpm_file_to_image(s->mlx, "Textures/teleport_64.xpm", &width, &height);
	s->wall[5] = mlx_xpm_file_to_image(s->mlx, "Textures/wood.xpm", &width, &height);
	s->wall[6] = mlx_xpm_file_to_image(s->mlx, "Textures/mdr.xpm", &width, &height);
	s->wall[7] = mlx_xpm_file_to_image(s->mlx, "Textures/ben.xpm", &width, &height);
	ft_corps(s);
}

void	mlx_image_put_pixel(t_id *s, int x, int y, int col)
{
	s->color = mlx_get_color_value(s->mlx, col);
	// if (x > 0 && x < W_X && y > 0 && y < W_Y)
		*(unsigned int *)(s->data + ((int)s->bpp * x) +
				(s->s_line * y)) = col;
}

void	ft_first_creation(t_id *s)
{
	mlx_mouse_hook (s->win, mouse_reaction_click, s);
	mlx_key_hook(s->win, key_reaction, s);
	mlx_hook(s->win, KeyPress, KeyPressMask, ft_movement, s);
	mlx_hook(s->win, MotionNotify, PointerMotionMask, mouse_reaction, s);
	// mlx_loop_hook(s->mlx, ft_recreate, s);
	mlx_loop(s->mlx);
}

int		*ft_parsing(char *str)
{
	int			*tab;
	int			i;
	char		**char_to_int;

	tab = (int *)malloc(sizeof(int) * ft_get_number_of_words(str, ' '));
	char_to_int = ft_strsplit(str, ' ');
	i = -1;
	while (char_to_int[++i])
		tab[i] = ft_atoi(char_to_int[i]);
	return (tab);
}

int ft_recreate(t_id *s)
{
	if (s->img)
		mlx_destroy_image(s->mlx, s->img);
	s->img = mlx_new_image(s->mlx, W_X, W_Y);
	s->data = mlx_get_data_addr(s->img, &s->bit_per_pixel, &s->s_line,
		&s->endian);
	s->bpp = s->bit_per_pixel / 8;
	ft_corps(s);
	return (1);
}

void ft_first_spawn(t_id *s, char **argv)
{
	int		fd;
	char	*line;

	
	s->posX = ft_atoi(argv[2]);
	s->posY = ft_atoi(argv[3]);

	fd = open(argv[1], O_RDONLY);
	s->nl = 0;
	while ((get_next_line(fd, &line)) > 0)
		++s->nl;
	s->map = (int **)malloc(sizeof(int *) * s->nl);
	s->nl = 0;
	close(fd);
	fd = open(argv[1], O_RDONLY);
	while ((get_next_line(fd, &line)) > 0)
	{
		s->map[s->nl] = ft_parsing(line);
		s->nc = ft_get_number_of_words(line, ' ');
		s->nl++;
	}
	close(fd);
	s->posX = ft_atoi(argv[2]);
	s->posY = ft_atoi(argv[3]);
	if (s->posX > s->nl || s->posY > s->nc)
	{
		ft_putstr("Position de spawn incorrecte\n");
		exit(0);
	}
}

int		main(int argc, char **argv)
{
	t_id	s;
	int i;

	i = -1;
	s.niveau = (char**)ft_memalloc(sizeof(char*) * 10);
	while (++i < 10)
		s.niveau[i] = (char*)ft_memalloc(sizeof(char) * 25);
	i = -1;
	s.weapon = (char**)ft_memalloc(sizeof(char*) * 10);
	s.mlx = mlx_init();
	s.win = mlx_new_window(s.mlx, W_X, W_Y, WIN_NAME);	
	s.niveau[1] = "Maps/niveau2";
	s.niveau[2] = "Maps/niveau3";
	s.niveau[3] = "Maps/niveau4";
	s.niveau[4] = "Maps/niveau5";
	
	s.weapon[0] = ft_strdup("Textures/weapon1.xpm");
	s.weapon[1] = ft_strdup("Textures/weapon2.xpm");
	s.weapon[2] = ft_strdup("Textures/weapon3.xpm");
	s.weapon[3] = ft_strdup("Textures/weapon4.xpm");
	s.weapon[4] = ft_strdup("Textures/weapon5.xpm");
	s.weapon[5] = ft_strdup("Textures/weapon6.xpm");
	s.weapon[6] = ft_strdup("Textures/weapon7.xpm");


	if (argc != 4)
		return (0);

	ft_first_spawn(&s, argv);
	ft_initialisation(&s);
	ft_first_creation(&s);
	return (0);
}
