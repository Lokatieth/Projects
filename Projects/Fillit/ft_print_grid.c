/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_grid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 15:42:16 by vbauguen          #+#    #+#             */
/*   Updated: 2015/12/12 15:13:35 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**ft_print_grid(int size)
{
	int		i;
	int		j;
	char	**map;

	j = 0;
	i = 0;
	while (i < size)
		i++;
	map = (char **)malloc(sizeof(char *) * (i + 1));
	while (j < size)
	{
		map[j] = malloc(sizeof(char) * (i + 1));
		i = 0;
		while (i < size)
		{
			map[j][i] = '.';
			i++;
		}
		map[j][i] = '\0';
		j++;
	}
	return (map);
}
