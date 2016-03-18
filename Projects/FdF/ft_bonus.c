/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:39:10 by vbauguen          #+#    #+#             */
/*   Updated: 2016/03/18 11:31:45 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_zoom(t_id *param, int keycode)
{
	if (keycode == 69)
	{
		param->dp = (param->dp + 1) * 1.3;
		ft_recreate_img(param);
		ft_display_ver(param);
		ft_display_hor(param);
	}
	if (keycode == 78)
	{
		ft_recreate_img(param);
		param->dp = param->dp / 1.3;
		ft_display_ver(param);
		ft_display_hor(param);
	}
}

void	ft_move_hor(t_id *param, int keycode)
{
	if (keycode == 123)
	{
		ft_recreate_img(param);
		param->decalx = param->decalx - 20;
		ft_display_hor(param);
		ft_display_ver(param);
	}
	if (keycode == 124)
	{
		ft_recreate_img(param);
		param->decalx = param->decalx + 20;
		ft_display_hor(param);
		ft_display_ver(param);
	}
}

void	ft_move_ver(t_id *param, int keycode)
{
	if (keycode == 125)
	{
		ft_recreate_img(param);
		param->decaly = param->decaly + 20;
		ft_display_hor(param);
		ft_display_ver(param);
	}
	if (keycode == 126)
	{
		ft_recreate_img(param);
		param->decaly = param->decaly - 20;
		ft_display_hor(param);
		ft_display_ver(param);
	}
}

void	ft_leveling(t_id *param, int keycode)
{
	if (keycode == 116)
	{
		ft_recreate_img(param);
		param->decalz = param->decalz * 1.3;
		ft_display_hor(param);
		ft_display_ver(param);
	}
	if (keycode == 121)
	{
		ft_recreate_img(param);
		param->decalz = param->decalz / 1.3;
		ft_display_hor(param);
		ft_display_ver(param);
	}
}

void	ft_horizontal_shift(t_id *param, int keycode)
{
	if (keycode == 43)
	{
		ft_recreate_img(param);
		param->slide = param->slide - 0.1;
		ft_display_hor(param);
		ft_display_ver(param);
	}
	if (keycode == 47)
	{
		ft_recreate_img(param);
		param->slide = param->slide + 0.1;
		ft_display_hor(param);
		ft_display_ver(param);
	}
}
