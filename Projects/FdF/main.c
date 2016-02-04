/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 09:09:13 by vbauguen          #+#    #+#             */
/*   Updated: 2016/02/02 10:08:12 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "header.h"
#include "mlx.h"
#include <stdio.h>

void ft_Bresenham(t_id *s)
{	
	// printf("tab[0][0] , aka XO = %d\n", tab[0][0]);
	// printf("tab[0][1] , aka Y0 = %d\n", tab[0][1]);
	// printf("tab[1][0] , aka X1 = %d\n", tab[1][0]);
	// printf("tab[1][1] , aka Y1 = %d\n", tab[1][1]);

	float dx, dy, p;
	int i, x, y, xend;

	s->x1 = 500;
	s->x2 = 250;
	s->y1 = 500;
	s->y2 = 100;
	dx = s->x2 - s->x1;
	dy = s->y2 - s->y1;
	p = 2 * dy - dx;
	if (s->x1 > s->x2)
	{
		x = s->x2;
		y = s->y2;
		xend = s->x1;
	}
	else 
	{
		x = s->x1;
		y = s->y1;
		xend = s->x2;
	}
	mlx_pixel_put(s->mlx, s->win, x, y, 0x00FF0000);
	while (x < xend)
	{
		if (p < 0)
		{
			x++;
			mlx_pixel_put(s->mlx, s->win, x, y, 0x00FF0000);
			p = p + (2 * dy);
		}
		else
		{
			x++;
			y++;
			mlx_pixel_put(s->mlx, s->win, x, y, 0x00FF0000);
			p = p + (2 * dy) - (2 * dx);
		}
	}


}
int key_reaction(int keycode, t_id *param)
{
	int tab[2][2] = {{600, 450}, {600, 200}}; 	//on doit pouvoir recuperer [j][i] au lieu de [2][2] lors de la lecture du fichier
	int y;											// i etant le nombre de colonnes et j le nomre de lignes
	int x;

	if (keycode == 53)
		exit(0);
	if (keycode == 49)
		ft_Bresenham(param);
	return (0);	
}

int main()
{
	t_id *s;
	int y;
	int x;

	s = (t_id*)malloc(sizeof(t_id));
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, 1200, 900, "42");

	y = 250;
	while (y < 650)
	{
		x = 300;
		while (x < 900)
		{
			mlx_pixel_put(s->mlx, s->win, x, y, 0x00000000);
			x++;
		}
		y++;	
	}



	mlx_key_hook(s->win, key_reaction, s);
	mlx_loop(s->mlx);
}