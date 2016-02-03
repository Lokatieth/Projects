/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upleft.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 17:58:10 by vbauguen          #+#    #+#             */
/*   Updated: 2016/01/22 19:56:39 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static char		*virgin_piece(void)
{
	char	*new_piece;
	int		i;

	if (!(new_piece = (char *)malloc(sizeof(char) * 21)))
		return (NULL);
	i = -1;
	while (++i < 5)
		ft_memcpy(new_piece + (i * 5), "....\n", 5);
	new_piece[20] = 0;
	return (new_piece);
}

static char		*cpy_up_left(char *piece, int x, int y)
{
	char	*new_piece;
	int		i;
	int		j;

	new_piece = virgin_piece();
	j = y - 1;
	while (++j < 4)
	{
		i = x - 1;
		while (++i < 4)
			new_piece[(i - x) + ((j - y) * 5)] = piece[i + (j * 5)];
	}
	return (new_piece);
}

void			up_left_pieces(char **piece)
{
	int		i;
	int		x;
	int		y;
	char	*tmp;

	if (!*piece)
		return ;
	i = -1;
	x = 42;
	y = 42;
	while ((*piece)[++i])
	{
		if ((*piece)[i] == '#' && i % 5 < x)
			x = i % 5;
		if ((*piece)[i] == '#' && i / 5 < y)
			y = i / 5;
	}
	tmp = *piece;
	*piece = cpy_up_left(*piece, x, y);
	free(tmp);
	up_left_pieces(++piece);
}
