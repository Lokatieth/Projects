/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_to_letters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 19:36:42 by vbauguen          #+#    #+#             */
/*   Updated: 2015/12/11 20:13:37 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

char	**ft_to_letters(char **str_tab, int i)
{
	int j;
	int h;

	h = 0;
	while (h <= i)
	{
		j = 0;
		while (str_tab[h][j] != '\0')
		{
			if (str_tab[h][j] == '#')
			{
				str_tab[h][j] = 'A' + h;
			}
			j++;
		}
		ft_putstr(str_tab[h]);
		h++;
	}
	return (str_tab);
}
