/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuto.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:57:51 by vbauguen          #+#    #+#             */
/*   Updated: 2016/05/08 15:43:52 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"


int key_reaction(int keycode/*, t_id *param*/)
{
	if (keycode == 53)
		exit(0);
	// printf("%d\n", keycode);
	return (0);
}

int mouse_reaction(/*int button, int x, int y*/)
{
	// printf("%d\t%d\t%d\n", button, x, y);
	return (0);
}

int 	ft_find_next_ver(t_id *s, int i)
{

	if (s->map[(int)s->AyGrid][(int)s->AxGrid] != 0)
	{
		// printf(" Ver debut : Mur trouve en X = %d Y = %d lors de l'iteration numero %d\n\n\n", (int)s->AxGrid, (int)s->AyGrid, i);
		return (1);
	}
		s->BxPix = s->AxPix + i * s->V_Xa;
		s->ByPix = s->AyPix + i * s->V_Ya;
		s->BxGrid = s->BxPix / 64;
		s->ByGrid = s->ByPix / 64;
	// printf("Find next ver : Valeur de la case en {%d,%d} =%d\n", (int)s->BxGrid, (int)s->ByGrid, s->map[(int)s->ByGrid][(int)s->BxGrid]);
	if (s->map[s->ByGrid][s->BxGrid] != 0)
	{
		s->V_Ray_Lenght = sqrt(pow((s->Px - s->BxPix),2) + pow((s->Py - s->ByPix),2));
		// printf("Px = %lf\nPy = %lf\nBxPix = %d\nByPix = %d\nTaille du rayon = %lf\n",s->Px,s->Py, s->BxPix,s->ByPix, s->H_Ray_Lenght);

		// printf("Ver Mur trouve en X = %d Y = %d lors de l'iteration numero %d\n\n\n", s->BxGrid, s->ByGrid, i);
		return (1);
	}

	return (0);
}

int ft_raycasting_vertical_left(t_id *s)
{
	int i = 1;
	if ((s->Player_Angle <= 90 && s->Player_Angle >=0) || (s->Player_Angle > 270 && s->Player_Angle <= 360))
		s->V_Ya = 64 * tan(s->Player_Angle_Ver * PI / 180);
	else
		s->V_Ya = 64 * tan(s->Player_Angle * PI / 180);
	s->AxPix = floor(s->Px / 64) * 64 - 1;
	s->AyPix = s->Py + (s->Px - s->AxPix) * (s->V_Ya / 64);
	// printf("s->AyPix = s->Py + (s->Px - s->AxPix) * tan(s->Player_Angle * PI / 180)\n%d = %d + (%d - %d) * tan(%d * PI / 180)\n", (int)s->AyPix, (int)s->Py, (int)s->Px, (int)s->AxPix, (int)s->Player_Angle);
	s->AxGrid = floor(s->AxPix / 64);
	s->AyGrid = floor(s->AyPix / 64);
	s->V_Xa = -64;
	// printf(" Raycasting vertical : Valeur de la case en {%d,%d} =%d\n", (int)s->AxGrid, (int)s->AyGrid, s->map[(int)s->AyGrid][(int)s->AxGrid]);
	while (ft_find_next_ver(s, i) != 1)
		i++;

	return (0);
}

int ft_raycasting_vertical_right(t_id *s)
{
	int i = 1;
	s->V_Ya = 64 * tan(s->Player_Angle_Ver * PI / 180);
	s->AxPix = floor(s->Px / 64) * 64 + 64;
	s->AyPix = s->Py + (s->Px - s->AxPix) * (s->V_Ya / 64);
	// printf("s->AyPix = s->Py + (s->Px - s->AxPix) * tan(s->Player_Angle * PI / 180)\n%d = %d + (%d - %d) * tan(%d * PI / 180)\n", (int)s->AyPix, (int)s->Py, (int)s->Px, (int)s->AxPix, (int)s->Player_Angle);
	s->AxGrid = floor(s->AxPix / 64);
	s->AyGrid = floor(s->AyPix / 64);
	s->V_Xa = 64;
	// printf(" Raycasting vertical : Valeur de la case en {%d,%d} =%d\n", (int)s->AxGrid, (int)s->AyGrid, s->map[(int)s->AyGrid][(int)s->AxGrid]);
	while (ft_find_next_ver(s, i) != 1)
		i++;

	return (0);
}

int ft_raycasting_vertical(t_id *s)
{
	if ((s->Player_Angle <= 90 && s->Player_Angle >=0) || (s->Player_Angle > 270 && s->Player_Angle <= 360))
	{
		s->Player_Angle_Ver = 360 - s->Player_Angle;
		ft_raycasting_vertical_right(s);
	}
	if (s->Player_Angle > 90 && s->Player_Angle <= 270)
		ft_raycasting_vertical_left(s);
	return (0);
}

int 	ft_find_next_hor(t_id *s, int i)
{
	if (s->map[(int)s->AyGrid][(int)s->AxGrid] != 0)
	{
		if (s->Player_Angle >= 180 && s->Player_Angle < 360)
			s->H_Ray_Lenght = fabs(s->Px - s->CxPix) / cos(s->Player_Angle_Hor);
		else
			s->H_Ray_Lenght = fabs(s->Px - s->CxPix) / cos(s->Player_Angle);
		// printf("Hor : Mur trouve en X = %d Y = %d lors de l'iteration numero %d\n\n\n", (int)s->AxGrid, (int)s->AyGrid, i);
		return (1);
	}
		s->CxPix = s->AxPix + i * s->H_Xa;
		s->CyPix = s->AyPix + i * s->H_Ya;
		s->CxGrid = s->CxPix / 64;
		s->CyGrid = s->CyPix / 64;
	// printf("Find next hor : Valeur de la case en {%d,%d} =%d\n", (int)s->CxGrid, (int)s->CyGrid, s->map[(int)s->CyGrid][(int)s->CxGrid]);
	if (s->map[s->CyGrid][s->CxGrid] != 0)
	{
		s->H_Ray_Lenght = sqrt(pow((s->Px - s->CxPix),2) + pow((s->Py - s->CyPix),2));
		// printf("Px = %lf\nPy = %lf\nCxPix = %d\nCyPix = %d\nTaille du rayon = %lf\n",s->Px,s->Py, s->CxPix,s->CyPix, s->H_Ray_Lenght);
		// printf("Mur trouve en X = %d Y = %d\n\n\n", s->CxGrid, s->CyGrid);
		return (1);
	}

	return (0);
}

int ft_raycasting_horizontal_180_to_360(t_id *s)
{
	int i = 1;

	s->AyPix = floor(s->Py / 64) * 64 + 64;
	s->AxPix = s->Px + (s->Py - s->AyPix) / tan(s->Player_Angle_Hor * PI / 180);
	s->AyGrid = floor(s->AyPix / 64);
	s->AxGrid = floor(s->AxPix / 64);
	// printf("%d\n", (int)s->AxGrid);
	s->H_Ya = 64;
	s->H_Xa = floor(64 / tan(s->Player_Angle_Hor * PI / 180));
	// printf("Raycasting horizontal : Valeur de la case en {%d,%d} =%d\n", (int)s->AxGrid, (int)s->AyGrid, s->map[(int)s->AyGrid][(int)s->AxGrid]);
	// s->H_Ray_Lenght = fabs(s->Px - s->AxPix) / cos(s->Player_Angle);
	while (ft_find_next_hor(s, i) != 1)
		i++;

	return (0);
}

int ft_raycasting_horizontal_0_to_180(t_id *s)
{
	int i = 1;

	s->AyPix = floor(s->Py / 64) * 64 - 1;
	s->AxPix = s->Px + (s->Py - s->AyPix) / tan(s->Player_Angle * PI / 180);
	s->AyGrid = floor(s->AyPix / 64);
	s->AxGrid = floor(s->AxPix / 64);
	s->H_Ya = -64;
	s->H_Xa = floor(64 / tan(s->Player_Angle * PI / 180));
	// printf("Raycasting horizontal : Valeur de la case en {%d,%d} =%d\n", (int)s->AxGrid, (int)s->AyGrid, s->map[(int)s->AyGrid][(int)s->AxGrid]);
	s->H_Ray_Lenght = fabs(s->Px - s->AxPix) / cos(s->Player_Angle);
	while (ft_find_next_hor(s, i) != 1)
		i++;
	return (0);
}

int ft_raycasting_horizontal(t_id *s)
{
	if (s->Player_Angle >= 0 && s->Player_Angle < 180)
		ft_raycasting_horizontal_0_to_180(s);
	if (s->Player_Angle >= 180 && s->Player_Angle < 360)
	{
		s->Player_Angle_Hor = 180 + (360 - s->Player_Angle);
		ft_raycasting_horizontal_180_to_360(s);
	}
	return (0);
}

void	ft_initialisation(t_id *s)
{
	s->Player_Height = 32;
	s->Player_Angle = 45;
	if (s->Player_Angle == 0)
		s->Player_Angle = 1;
	// printf("ANGLE DU JOUEUR = %d\n", (int)s->Player_Angle);
	s->Player_PosX = 1;
	s->Player_PosY = 6;
	s->Wall_Height = 64;
	s->Proj_P_Center_X = W_X / 2;
	s->Proj_P_Center_Y = W_Y / 2;
	s->Player_FoV = 66;
	s->Player_Dist_to_Plane = s->Proj_P_Center_X / tan(s->Player_FoV/2 * PI / 180);
	s->Angle_bet_Rays = s->Player_FoV / W_X;
	s->Py = ((s->Player_PosY) * 64) + 32;
	s->Px = ((s->Player_PosX) * 64) + 32;
	s->img = mlx_new_image(s->mlx, W_X, W_Y);
	s->data = mlx_get_data_addr(s->img, &s->bit_per_pixel, &s->s_line,
			&s->endian);
	s->bpp = s->bit_per_pixel / 8;
	// printf("Position du joueur et valeur de la case de depart situe en {%d,%d} = [%d]\n", (int)s->Player_PosX, (int)s->Player_PosY, s->map[(int)s->Player_PosY][(int)s->Player_PosX]);
}

void	mlx_image_put_pixel(t_id *s, int x, int y, int col)
{
	s->color = mlx_get_color_value(s->mlx, col);
	if (x > 0 && x < W_X && y > 0 && y < W_Y)
		*(unsigned int *)(s->data + ((int)s->bpp * x) +
				(s->s_line * y)) = col;
}

void	ft_draw_vert(t_id *s, int x)
{
	double y;
	double projected_slice;
	ft_raycasting_horizontal(s);
	// ft_raycasting_vertical(s);
	s->Ray_Lenght = fmax(s->H_Ray_Lenght, s->V_Ray_Lenght);
	projected_slice = 64 * s->Ray_Lenght / 255 ;
	// // printf("H_Ray_Lenght = %lf\n", s->H_Ray_Lenght);
	y = s->Proj_P_Center_Y - projected_slice / 2;
	while (y < s->Proj_P_Center_Y + projected_slice/2)
	{
		// if (x > 0 && x < W_X && y > 0 && y < W_Y)
	// 		mlx_image_put_pixel(s, x, y, 0xFF0000);
		x++;
		y++;
	}
	// mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
}

void	ft_first_creation(t_id *s)
{
	int x;
	
	x = 1;
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, W_X, W_Y, WIN_NAME);
	// mlx_mouse_hook (s->win, mouse_reaction, s);
	ft_initialisation(s);
	double y = s->Player_Angle + 30;
	s->Player_Angle = s->Player_Angle - 30;
	// while (x < W_X)
	while (s->Player_Angle < y && x < W_X)
	{

		printf("s->Player_Angle = %lf, y = %lf\n",s->Player_Angle,y);
		ft_draw_vert(s, x);
		printf("x = %d\n", x);
		s->Player_Angle = s->Player_Angle + s->Angle_bet_Rays;
		printf("s->Player_Angle_bet = %lf\n\n",s->Angle_bet_Rays);
		x++;
	}
	mlx_key_hook(s->win, key_reaction, s);
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


int		main(int argc, char **argv)
{
	t_id	s;
	int		fd;
	char	*line;

	if (argc != 2)
		return (0);
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
		s.nl++;
	}
	ft_first_creation(&s);
	return (0);
}
