/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:58:52 by vbauguen          #+#    #+#             */
/*   Updated: 2016/03/18 11:23:06 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_fdf_check(char *str)
{
	char	*end;

	end = (char*)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (end == NULL)
		return (0);
	if ((end = ft_strrchr(str, '.')) == NULL)
		return (0);
	if (end[0] == '.' && end[1] == 'f' && end[2] == 'd' && end[3] == 'f'
			&& end[4] == '\0')
		return (1);
	else
		return (0);
	return (0);
}

void	ft_error(void)
{
	ft_putstr("Error while loading the file.\nUsage : ./fdf testfile.fdf\n");
	exit(0);
}

void	ft_color_vertical(t_id *s, int i, int j)
{
	s->col = 0x87591A;
	if (s->map[j][i] <= 0 && s->map[j + 1][i] <= 0)
		s->col = 0x0000FF;
	else if (s->map[j][i] > 0 && s->map[j + 1][i] > 0)
		s->col = 0x00FF00;
}

void	ft_color_horizontal(t_id *s, int i, int j)
{
	s->col = 0x87591A;
	if (s->map[j][i] <= 0 && s->map[j][i + 1] <= 0)
		s->col = 0x0000FF;
	else if (s->map[j][i] > 0 && s->map[j][i + 1] > 0)
		s->col = 0x00FF00;
}
