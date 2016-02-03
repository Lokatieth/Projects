/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 19:24:53 by vbauguen          #+#    #+#             */
/*   Updated: 2016/02/01 20:04:08 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int main()
{
	void *mlx;
	void *win;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "42");
	mlx_loop(mlx);

}