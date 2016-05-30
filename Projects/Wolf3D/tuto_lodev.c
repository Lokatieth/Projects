/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuto_lodev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:57:51 by vbauguen          #+#    #+#             */
/*   Updated: 2016/05/21 02:26:51 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

// effet bourre ; mlx_image_put_pixel(s, x, y, 0x0000ff * sqrt(x * x * y * y) / (105 * y * x));
				// mlx_image_put_pixel(s, x, W_Y - y + (3), 0x16B84E * sqrt(y * y * x) / 50 * x * y); 
/*
	Piur les textures : get_data_adress de l'image cree avec mlx xpm file to img, et en recuperer les infomation de la couleur de l image;


*/

int mouse_reaction_click(int button, t_id *s)
{
	int i;
	int x1;
	int y1;

	i = 0;
	if (button == 1)
	{
		printf("mdr\n");
		while (i < 7)
		{
			printf("connard\n");
			s->xpm = mlx_xpm_file_to_image(s->mlx, s->weapon[i], &x1, &y1);
			printf("connard\n");
			mlx_put_image_to_window(s->mlx, s->win, s->xpm, W_X / 2, W_Y);
			printf("connard\n");
			sleep(1);
			printf("connard\n");
			ft_recreate(s);
		}
	}


	return (0);
}

void ft_get_img_addr(t_id *s)
{
	int i = 1;

	s->data = mlx_get_data_addr(s->xpm, &s->bit_per_pixel, &s->s_line,
		&s->endian);
	while (s->data && i < 1000)
	{
		printf("%c", s->data[i]);
	}
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
	if (keycode == 17 && s->map[(int)s->posX][(int)s->posY] == -1)
		ft_next_map(s);


	if (keycode == 12)
    {
      if(s->map[(int)(s->posX + s->dirX * 0.10)][(int)(s->posY)] == 0 ||
      	s->map[(int)(s->posX + s->dirX * 0.10)][(int)(s->posY)] == -1)
     	 	s->posX += s->dirX * 0.10;
      if(s->map[(int)(s->posX)][(int)(s->posY + s->dirY * 0.10)] == 0 ||
      	s->map[(int)(s->posX)][(int)(s->posY + s->dirY * 0.10)] == -1)
      		s->posY += s->dirY * 0.10;
      if(s->map[(int)(s->posX - s->dirY * 0.10)][(int)(s->posY)] == 0 ||
      	s->map[(int)(s->posX - s->dirY * 0.10)][(int)(s->posY)] == -1)
      	s->posX -= s->dirY * 0.10;
      if(s->map[(int)(s->posX)][(int)(s->posY + s->dirX * 0.10)] == 0 ||
      	s->map[(int)(s->posX)][(int)(s->posY + s->dirX * 0.10)] == -1)
      	s->posY += s->dirX * 0.10;
    }
    if (keycode == 14)
    {
    	if(s->map[(int)(s->posX + s->dirX * 0.15)][(int)(s->posY)] == 0 ||
      	s->map[(int)(s->posX + s->dirX * 0.15)][(int)(s->posY)] == -1)
     	 	s->posX += s->dirX * 0.15;
      	if(s->map[(int)(s->posX)][(int)(s->posY + s->dirY * 0.15)] == 0 ||
      	s->map[(int)(s->posX)][(int)(s->posY + s->dirY * 0.15)] == -1)
      		s->posY += s->dirY * 0.15;
      	if(s->map[(int)(s->posX + s->dirY * 0.15)][(int)(s->posY)] == 0 ||
      	s->map[(int)(s->posX + s->dirY * 0.15)][(int)(s->posY)] == -1)
      		s->posX += s->dirY * 0.15;
     	if(s->map[(int)(s->posX)][(int)(s->posY - s->dirX * 0.15)] == 0 ||
      	s->map[(int)(s->posX)][(int)(s->posY - s->dirX * 0.15)] == -1)
      		s->posY -= s->dirX * 0.15;
    }
	if (keycode == 126 || keycode == 13)
    {
      if(s->map[(int)(s->posX + s->dirX * 0.15)][(int)(s->posY)] == 0 ||
      	s->map[(int)(s->posX + s->dirX * 0.15)][(int)(s->posY)] == -1)
     	 	s->posX += s->dirX * 0.15;
      if(s->map[(int)(s->posX)][(int)(s->posY + s->dirY * 0.15)] == 0 ||
      	s->map[(int)(s->posX)][(int)(s->posY + s->dirY * 0.15)] == -1)
      		s->posY += s->dirY * 0.15;
    }
    if (keycode == 125 || keycode == 1)
    {
      if(s->map[(int)(s->posX - s->dirX * 0.15)][(int)(s->posY)] == 0 ||
      	s->map[(int)(s->posX - s->dirX * 0.15)][(int)(s->posY)] == -1)
      	s->posX -= s->dirX * 0.15;
      if(s->map[(int)(s->posX)][(int)(s->posY - s->dirY * 0.15)] == 0 ||
      	s->map[(int)(s->posX)][(int)(s->posY - s->dirY * 0.15)] == -1)
      	s->posY -= s->dirY * 0.15;
    }
    if (keycode == 0)
    {
      if(s->map[(int)(s->posX - s->dirY * 0.15)][(int)(s->posY)] == 0 ||
      	s->map[(int)(s->posX - s->dirY * 0.15)][(int)(s->posY)] == -1)
      	s->posX -= s->dirY * 0.15;
      if(s->map[(int)(s->posX)][(int)(s->posY + s->dirX * 0.15)] == 0 ||
      	s->map[(int)(s->posX)][(int)(s->posY + s->dirX * 0.15)] == -1)
      	s->posY += s->dirX * 0.15;
	}
	if (keycode == 2)
    {
     	if(s->map[(int)(s->posX + s->dirY * 0.15)][(int)(s->posY)] == 0 ||
      	s->map[(int)(s->posX + s->dirY * 0.15)][(int)(s->posY)] == -1)
      		s->posX += s->dirY * 0.15;
     	if(s->map[(int)(s->posX)][(int)(s->posY - s->dirX * 0.15)] == 0 ||
      	s->map[(int)(s->posX)][(int)(s->posY - s->dirX * 0.15)] == -1)
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
    ft_recreate(s);
	return (0);
}

int mouse_reaction(int x, int y, t_id *s)
{
	double angleRelX;
	(void)y;
	// if (y > 0 && y < W_Y)
	// 	s->decalY = 50 - 100 * ((double)y / (double)W_Y);
	angleRelX = 360 - ((x % W_X) * 360 / W_X);
	s->dirX = cos(angleRelX * PI / 180);
	s->dirY = sin(angleRelX * PI / 180);
	s->planeX = 0.66 * s->dirY;
	s->planeY = -0.66 * s->dirX;
    ft_recreate(s);
	return (0);
}

void ft_draw_vertical_line(int x, t_id *s)
{
	int y;
	// int i = 0;
	// int w = 0;

	if (s->map[s->mapX][s->mapY] == 1)
		s->color = 0xFF00FF;
	else if (s->map[s->mapX][s->mapY] == 2)
		s->color = 0xFFFF00;
	else if (s->map[s->mapX][s->mapY] == 3)
		s->color = 0xFF0000;
	else if (s->map[s->mapX][s->mapY] == 4)
		s->color = 0xFFFFFF;
	else if (s->map[s->mapX][s->mapY] == -1)
		s->color = 0x20214f;
	else
		s->color = 0x145236;

	if (s->side == 1)
		s->color = (s->color >> 1) & 8355711;
	y = s->drawStart;
	while (y < s->drawEnd)
	{
		mlx_image_put_pixel(s, x, y + s->decalY, s->color);
		y++;
	}
	// while (i < s->drawStart)
	// {
	// 	mlx_image_put_pixel(s, x, i + s->decalY, 0x16B8FF);
	// 	i++;
	// }
	// while (w < s->decalY)
	// {
	// 	mlx_image_put_pixel(s, x, w, 0x16B8FF);
	// 	w++;
	// }
	
	while (y < W_Y)
	{
		mlx_image_put_pixel(s, x, y + s->decalY, 0x169514);
		mlx_image_put_pixel(s, x, (W_Y - y) + s->decalY, 0x16B8FF); 
		y++;
	}
}

int ft_corps(t_id *s)
{
	int x = -1;
	int x1;
	int y1;
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
		ft_draw_vertical_line(x, s);
	}
	

	s->xpm = mlx_xpm_file_to_image(s->mlx, "Textures/weapon7.xpm", &x1, &y1);
	s->bpp = s->bit_per_pixel / 8;
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	mlx_put_image_to_window(s->mlx, s->win, s->xpm, W_X / 2 - 320, W_Y - 400);
	if (s->map[(int)s->posX][(int)s->posY] == -1)
	{
		s->teleport = mlx_xpm_file_to_image(s->mlx, "Textures/teleport_icon.xpm", &x2, &y2);
		mlx_put_image_to_window(s->mlx, s->win, s->teleport, W_X / 2 - 100, W_Y / 2 - 100);
	}
	return (0);
}

void	ft_initialisation(t_id *s)
{
	s->planeX = 0;
	s->planeY = 0.66 ;
	s->dirX = -1;
	s->dirY = 0;
	s->level = 0;
	s->img = mlx_new_image(s->mlx, W_X, W_Y);
	s->data = mlx_get_data_addr(s->img, &s->bit_per_pixel, &s->s_line,
			&s->endian);
	s->bpp = s->bit_per_pixel / 8;
	
	ft_corps(s);
}

void	mlx_image_put_pixel(t_id *s, int x, int y, int col)
{
	s->color = mlx_get_color_value(s->mlx, col);
	if (x > 0 && x < W_X && y - s->decalY > 0 && y - s->decalY < W_Y)
		*(unsigned int *)(s->data + ((int)s->bpp * x) +
				(s->s_line * y)) = col;
}

void	ft_first_creation(t_id *s)
{

	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, W_X, W_Y, WIN_NAME);
	ft_initialisation(s);

	mlx_mouse_hook (s->win, mouse_reaction_click, s);
	mlx_key_hook(s->win, key_reaction, s);
	mlx_hook(s->win, KeyPress, KeyPressMask, ft_movement, s);
	mlx_hook(s->win, MotionNotify, PointerMotionMask, mouse_reaction, s);
	mlx_loop(s->mlx);
}

int		*ft_parsing(char *str)
{
	int			*tab;
	int			i;
	static int	j;
	char		**char_to_int;

	// printf("%s\n", str);
	tab = (int *)malloc(sizeof(int) * ft_get_number_of_words(str, ' '));
	char_to_int = ft_strsplit(str, ' ');
	j = 0;
	i = -1;
	while (char_to_int[++i])
		tab[i] = ft_atoi(char_to_int[i]);
	return (tab);
}

void ft_recreate(t_id *s)
{
	if (s->img)
		mlx_destroy_image(s->mlx, s->img);
	s->img = mlx_new_image(s->img, W_X, W_Y);
	s->data = mlx_get_data_addr(s->img, &s->bit_per_pixel, &s->s_line,
		&s->endian);
	s->bpp = s->bit_per_pixel / 8;
	ft_corps(s);
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
	s.niveau = (char**)malloc(sizeof(char*) * 10);
	while (++i < 10)
		s.niveau[i] = (char*)malloc(sizeof(char) * 25);
	i = -1;
	s.weapon = (char**)malloc(sizeof(char*) * 10);
	
	s.niveau[1] = "Maps/niveau2";
	s.niveau[2] = "Maps/niveau3";
	s.niveau[3] = "Maps/niveau4";
	s.niveau[4] = "Maps/niveau5";
	
	s.weapon[0] = ft_strdup("textures/weapon1.xpm");
	s.weapon[1] = ft_strdup("textures/weapon2.xpm");
	s.weapon[2] = ft_strdup("textures/weapon3.xpm");
	s.weapon[3] = ft_strdup("textures/weapon4.xpm");
	s.weapon[4] = ft_strdup("textures/weapon5.xpm");
	s.weapon[5] = ft_strdup("textures/weapon6.xpm");
	s.weapon[6] = ft_strdup("textures/weapon7.xpm");


	if (argc != 4)
		return (0);

	ft_first_spawn(&s, argv);
	ft_first_creation(&s);
	return (0);
}
