/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darabi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/19 19:49:27 by darabi            #+#    #+#             */
/*   Updated: 2015/12/19 19:49:31 by darabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	***ft_bigger_tab(char **tetro_tab, int nb_tetro)
{
	char	***bigger_tab;
	int		i;
	int		j;

	j = 0;
	i = 0;
	bigger_tab = (char ***)malloc(sizeof(char **) * (nb_tetro + 1));
	while (i < nb_tetro)
	{
		bigger_tab[i] = ft_strsplit(tetro_tab[i], '\n');
		i++;
	}
	bigger_tab[i] = NULL;
	return (bigger_tab);
}

char	**replace(char **map, int i)
{
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (map[b])
	{
		while (map[b][a])
		{
			if (map[b][a] == (i + 'A'))
				map[b][a] = '.';
			++a;
		}
		a = 0;
		++b;
	}
	return (map);
}

char	***to_tetro_tab(char **tab)
{
	int		i;
	char	***tetro_tab;

	tetro_tab = NULL;
	i = 0;
	while (tab[i])
	{
		tetro_tab[i] = ft_strsplit(tab[i], '\n');
		++i;
	}
	return (tetro_tab);
}

char	*to_point(char *map, int nb)
{
	int		i;

	i = 0;
	while (i < nb)
	{
		map[i] = '.';
		++i;
	}
	map[i] = '\0';
	return (map);
}

char	**map_cpy(char **map)
{
	int		i;
	int		j;
	char	**map_cpy;

	j = 0;
	i = ft_strlen(map[0]);
	map_cpy = (char **)malloc(sizeof(char *) * (i + 1));
	while (j < i)
	{
		map_cpy[j] = (char *)malloc(sizeof(char) * (i + 1));
		++j;
	}
	j = 0;
	while (j < i)
	{
		ft_strcpy(map_cpy[j], map[j]);
		++j;
	}
	return (map_cpy);
}
