/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 20:48:17 by vbauguen          #+#    #+#             */
/*   Updated: 2016/02/01 22:53:03 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

typedef struct	s_id
{
	void *win;
	void *mlx;
	int x0;
	int x1;
	int y1;
	int y0;

}				t_id;

#endif