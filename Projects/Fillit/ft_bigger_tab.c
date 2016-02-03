/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigger_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darabi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 12:22:17 by darabi            #+#    #+#             */
/*   Updated: 2015/12/23 12:22:19 by darabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	***ft_bigger_tab(char **tetro_tab, int nb_tetro)
{
	char ***bigger_tab;
	int i;
	int j;

	j = 0;
	i = 0;
	bigger_tab = (char ***)malloc(sizeof(char **) * (nb_tetro + 1));
	while (i < nb_tetro)
	{
		bigger_tab[i] = ft_strsplit(tetro_tab[i], '\n');
		i++;
	}
	bigger_tab[i] = NULL;
	// ft_putstr("AVANT LE I");
	// ft_putstr("\n\n");
	// ft_puttab(bigger_tab[2]);
	// ft_putstr("TEST");
	// //bigger_tab[i] = NULL;
	// ft_putstr("RE");
	return (bigger_tab);
}