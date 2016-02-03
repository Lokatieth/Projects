/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 18:10:10 by darabi            #+#    #+#             */
/*   Updated: 2016/01/22 19:05:49 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"


// static void inc(int *p)
// {
// 	*p = *p + 1;
// 	return ;
// }

// static void inc_and_zero(int *p1, int *p2)
// {
// 	*p1 = 0;
// 	*p2 = *p2 + 1;
// 	return ;
// }

int		get_i(char **tetro)
{
	int		i;

	i = -1;
	while (tetro[0][++i] == '.')
		;
	return (tetro[0][i] - 'A');
}

int		ft_place(char **original_map, char **tetro, int y, int x)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!tetro)
		return (0);
	while (tetro[i])
	{
		while (tetro[i][j])
		{
			if (ft_isalpha(tetro[i][j]) == 1)
			{
				if (!original_map[y + i] || !original_map[y + i][x + j])
				{
					replace(original_map, get_i(tetro));
					// printf("jai brillament enleve le [%c]\n", 'A' + get_i(tetro));
					// ft_puttab(original_map);
					// ft_putchar(10);
					return (0);
				}
				if (original_map[y + i][x + j] == '.')
				{
					original_map[y + i][x + j] = tetro[i][j];
					//ft_puttab(original_map);
					//ft_putstr("\n");
				}
				else
				{
					replace(original_map, get_i(tetro));
					// printf("jai brillament enleve le [%c]\n", 'A' + get_i(tetro));
					// ft_puttab(original_map);
					// ft_putchar(10);
					return (0);
				}
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}

char **ft_place_rec(char **original_map, char **tetro, int y, int x)
{
		// 	if (y == 0 && x == 0)
		// {
		// 	printf("y = %d, x = %d\n", y, x);
		// 	ft_puttab(tetro);
		// 	ft_putstr("\n");
		// 	ft_puttab(original_map);
		// }
	// printf("y = %d, x = %d\n", y, x);
	if (!original_map[y][0])
		return (original_map);
	if (ft_place(original_map, tetro, y, x))
	{
		ft_putstr("TEST FIN 1\n");
		return (original_map);
	}
	else
		x++;
	if (!original_map[y][x] && !original_map[y + 1])
	{
		ft_putstr("TEST FIN 2\n");
		return (original_map);
	}
	if (!original_map[y][x])
	{
		y++;
		x = 0;
	}
	return(ft_place_rec(original_map, tetro, y, x));
}

int		check(char **tetro, char **map)
{
	int		i;
	int 	j;
	char	c;

	i = 0;
	j = 0;
	if (!tetro[1])
	{
		ft_putstr("Checking error \n");
		return(-1);
	}
	while (tetro[0][j] == '.')
		j++;
	c = tetro[0][j];
	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == c)
				return (1);
			j++;
		}
			i++;
		j = 0;
	}	
	ft_putstr("\nPiece non placee\n");
	return (0);
}

int		check_all(char ***tetro_tab, char **map)
{
	int i;

	i = 0;
	while (i < count(tetro_tab))
	{
		ft_putstr("\n");
		if (check(tetro_tab[i], map) != 1)
			return (0);
		i++;
	}
	return (1);
}

void	free_chrchr(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

char	**up_map(char **map)
{
	int i;
	int j;
	int nb;
	char **new_map;	

	i = 0;
	j = 0;
	j = ft_strlen(map[0]) + 1;
	free_chrchr(map);
	nb = j;
	new_map = (char **)malloc(sizeof(char *) * (j + 1));
	while (i < j)
	{
		new_map[i] = (char *)malloc(sizeof(char) * (j + 1));
		new_map[i] = to_point(new_map[i], nb);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}



int		backtracking(char **map, char ***tetro_tab, int i)
{
	int 	x;
	int 	y;
	// char	**tmp;

	y = 0;
	if (!tetro_tab[i])
		return (1);
	while (map[y])
	{
		x = 0;
		// ft_puttab(map);
		while (map[y][x])
		{
			if (ft_place(map, tetro_tab[i], y, x))
			{
				if (backtracking(map, tetro_tab, i + 1))
					return (1);
				else
				{
					replace(map, i);
					// printf("jai brillament enleve le [%c]\n", 'A' + i);
					// ft_puttab(map);
					// ft_putchar(10);
					// exit(0);
				}

			}
			// ft_puttab(map);
			// ft_putchar(10);
			++x;
		}
		++y;
	}
	return (0);
}