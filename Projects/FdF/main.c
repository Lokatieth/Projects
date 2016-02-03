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

void ft_drawline(int tab[2][2], t_id *s)
{
	int x;

	double dx = tab[1][0] - tab[0][0];
	double dy = tab[1][1] - tab[0][1];
	double m = dy/dy;
	double y = tab[0][1];

	x = tab[0][0];
	while (x <= tab[1][0])
	{
		mlx_pixel_put(s->mlx, s->win, x, (int)(y + 0.5), 0x00FF0000);
		y += m;
		x++;
	}
}

int key_reaction(int keycode, t_id *param)
{
	int tab[2][2] = { { 550, 550 }, {100, 100} }; 	//on doit pouvoir recuperer [j][i] au lieu de [2][2] lors de la lecture du fichier
	int y;											// i etant le nombre de colonnes et j le nomre de lignes
	int x;

	if (keycode == 53)
		exit(0);
	if (keycode == 49)
		ft_drawline(tab, param);
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