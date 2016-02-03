/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:50:01 by vbauguen          #+#    #+#             */
/*   Updated: 2015/12/14 20:12:53 by darabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include <stdio.h>

int		ft_verif_tetro(char *str);
int		ft_verif_last(char *str);
int		ft_all_verif(char *str, int i);
int		ft_stick_verif(char *str);
char	**ft_to_letters(char **str_tab, int i);
char	**ft_print_grid(int size);
int		ft_sqrt_rounded_up(int nb);
int		check(char **tetro, char **map);
int		check_all(char ***tetro, char **map);
int		backtracking(char **map, char ***tetro_tab, int i);
int		ft_place(char **original_map, char **tetro, int new_piece, int old_piece);
char	**replace(char **map, int i);
char	*to_point(char *map, int nb);
char	**map_cpy(char **map);
char	**up_map(char **map);
char	***to_tetro_tab(char **map);
char	***ft_bigger_tab(char **tetro_tab, int nb_tetro);
int		count(char ***tetro_tab);
void	up_left_pieces(char **piece);
#endif
