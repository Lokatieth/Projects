/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 21:55:20 by vbauguen          #+#    #+#             */
/*   Updated: 2016/02/03 22:20:11 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	int		fd;
	char	*line;
	int		i;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	i = 1;
	while ((get_next_line(fd, &line)) > 0)
	{
		printf("\n TOUR DE BOUCLE NUMERO %d =\t", i);
		printf("[%s]\n", line);
		free(line);
		++i;
	}
	close(fd);
	return (0);
}
