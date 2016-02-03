/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 14:14:55 by vbauguen          #+#    #+#             */
/*   Updated: 2015/12/21 17:13:06 by darabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

int		main(int argc, char **argv)
{
	int fd;
	int ret;
	char buf[22];
	char **tab;
	char ***tetro_tab = NULL;
	char **map;
	int i;

	argc= argc+1;
	i = 0;
	tab = (char**)malloc(sizeof(char*) * 27);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() error\n");
		return (0);
	}

	while (((ret = read(fd, buf, 21)) > 20) && i < 27)
	{
		buf[ret] = '\0';
		tab[i] = (char*)malloc(sizeof(char) * (ft_strlen(buf) + 1));
		tab[i] = ft_strcpy(tab[i], buf);
		if (ft_verif_tetro(tab[i]) == 0 || ft_stick_verif(tab[i]) == 0)
		{
			ft_putnbr(i);
			ft_putstr("tetromino error");
			return (0);
		}
		i++;
	}
	buf[ret] = '\0';
	tab[i] = (char*)malloc(sizeof(char) * (ft_strlen(buf) + 1));
	tab[i] = ft_strcpy(tab[i], buf);
	tab[i + 1] = NULL;
	if (ft_verif_tetro(tab[i]) == 1 && ft_stick_verif(tab[i]) == 1 && i < 27)
	{
	up_left_pieces(tab);
	ft_to_letters(tab, i);
	i++;
	tetro_tab = ft_bigger_tab(tab, i);
	// printf("\n\n\n\n");
	ft_print_grid(ft_sqrt_rounded_up(i * 4));
	map = ft_print_grid(ft_sqrt_rounded_up(i * 4));
	while (!backtracking(map, tetro_tab, 0))
	{
		ft_putstr("COUCOU JE SUIS ENTRE");
		ft_puttab(map);
		ft_putchar(10);
		map = up_map(map);
		ft_puttab(map);
	}
	printf("COUCOU JE SUIS SORTI\n");
	ft_puttab(map);
		ft_putchar(10);
	return (1);
	}
	return (0);
}

int		ft_verif_tetro(char *str)
{
	int i;
	int nb_hashtags;
	int nb_dots;
	int backslash;

	nb_dots = 0;
	nb_hashtags = 0;
	backslash = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			nb_hashtags++;
		if (str[i] == '.')
			nb_dots++;
		i++;
	}
	if (str[4] == '\n' && str[9] == '\n' && str[14] == '\n' && str[19] == '\n')
		backslash = 1;
	if (nb_hashtags == 4 && nb_dots == 12 && backslash == 1
		&& (ft_strlen(str) == 21 || ft_strlen(str) == 20))
		return (1);
	return (0);
}

int		ft_verif_last(char *str)
{
	int i;
	int nb_hashtags;
	int nb_dots;
	int backslash;

	nb_dots = 0;
	nb_hashtags = 0;
	backslash = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			nb_hashtags++;
		if (str[i] == '.')
			nb_dots++;
		i++;
	}
	if (str[4] == '\n' && str[9] == '\n' && str[14] == '\n' && str[19] == '\0')
		backslash = 1;
	if (nb_hashtags == 4 && nb_dots == 12 && backslash == 1
		&& ft_strlen(str) == 19)
		return (1);
	return (0);
}
