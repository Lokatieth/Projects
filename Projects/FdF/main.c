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
#include "libft/libft.h"

int ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}



void ft_bresenham(int tab[2][2], t_id *s)
{
	s->x0 = tab[0][0];
	s->y0 = tab[0][1];
	s->x1 = tab[1][0];
	s->y1 = tab[1][1];
	s->dx = ft_abs(s->x1 - s->x0);
	s->dy = ft_abs(s->y1 - s->y0);
	s->sx = s->x0 < s->x1 ? 1 : -1;
	s->sy = s->y0 < s->y1 ? 1 : -1;
	s->err = (s->dx > s->dy ? s->dx : -s->dy) / 2;
	while (1)
	{
 	   mlx_pixel_put(s->mlx, s->win, s->x0, s->y0, 0x00FF00FF);
    	if (s->x0 == s->x1 && s->y0 == s->y1)
    		break;
   		s->e2 = s->err;
    	if (s->e2 > -s->dx)
    	{
    		s->err-= s->dy;
    		s->x0+= s->sx;
    	}
    	if (s->e2 < s->dy)
    	{
    		s->err+= s->dx;
    		s->y0+= s->sy; 
    	}
	}
}

int key_reaction(int keycode, t_id *param, int **map)
{
	int tab[2][2] = {{100, 100}, {1000, 100}}; 	//on doit pouvoir recuperer [j][i] au lieu de [2][2] lors de la lecture du fichier
	// int y;											// i etant le nombre de colonnes et j le nomre de lignes
	// int x;
	map = ft_parsing();
	if (keycode == 53)
		exit(0);
	if (keycode == 49)
		ft_bresenham(tab, param);
	return (0);	
}

void ft_print_int_2d_tab(int **map , int i)
{
	int j;
	int k;

	j = 0;
	k = 0;
	printf("Avant le premier while\n");
	while (k < i)
	{
		j = 0;
		printf("Avant le deuxieme while\n");
		while (j < i)
		{
			ft_putnbr(map[k][j]);
			ft_putchar(' ');
			j++;
		}
		printf("Apres le deuxieme while\n");
		ft_putendl("");
		k++;
	}

}

int **ft_parsing(char *str)
{
	int *tab;
	int i;
	static int j;
	char **char_to_int;
	int **map;

	tab = (int *)malloc(sizeof(int) * ft_get_number_of_words(str, ' '));
	char_to_int = ft_strsplit(str, ' ');
	j = 0;
	i = 0;

	map = (int **)malloc(sizeof(int *) * ft_get_number_of_lines(str));

	while (char_to_int[i])
	{
		tab[i] = ft_atoi(char_to_int[i]);
		// printf("%d ", ft_atoi(char_to_int[i]));
		i++;
	}
	map[j] = tab;
	j++;
	// k = 0;
	// l = 0;
	// while (k < i)
	// {	
	// 	while (l < i)
	// 	{
	// 		printf("%d ", map[k][l]);
	// 		l++;
	// 	}
	// 	k++;
	// }
	// printf("\n");


	// ft_print_int_2d_tab(map, i);
	return (map);
}


int main(int argc, char **argv)
{
	t_id *s;
	int fd;
	char *line;
	int i;
	(void)argc;
	int x;
	int y;

	x = 0;
	y = 0;	
	fd = open(argv[1], O_RDONLY);
	i = 0;
	while ((get_next_line(fd, &line)) > 0) 
	{	
		ft_parsing(line);
		++i;
	}
	// printf("Nombre total de tours : %d\n", i);


	s = (t_id*)malloc(sizeof(t_id));
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, 1200, 900, "42");

	y = 250;
	while (y < 650)
	{
		x = 300;
		while (x < 900)
		{
			mlx_pixel_put(s->mlx, s->win, x, y, 0x00FFFFFF);
			x++;
		}
		y++;	
	}



	mlx_key_hook(s->win, key_reaction, s);
	mlx_loop(s->mlx);
	return (0);
}