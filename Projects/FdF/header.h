/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 20:48:17 by vbauguen          #+#    #+#             */
/*   Updated: 2016/02/08 10:48:05 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define BUFF_SIZE 30

# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct	s_id
{
	void *win;
	void *mlx;
	int x0;
	int x1;
	int y1;
	int y0;
	int dx;
	int dy;
	int err;
	int sy;
	int sx;
	int e2;
}				t_id;

#endif