/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/09 16:18:11 by vbauguen          #+#    #+#             */
/*   Updated: 2016/01/20 19:29:54 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_get_next_line(int const fd, char **line)
{
	// int i;
	// int ret;
	char *buf;

	buf = ft_strnew(BUFF_SIZE);
	// if (fd == -1)
	// 	return(-1);
	// while ((ret = read(fd, buf, BUFF_SIZE)) >= 0)
	// {
	// 	while ()
	read(fd, buf, BUFF_SIZE);
	*line = ft_strdup(buf);
	return (1);
}	

char *get_next_line(char *str)
{
	char *rest;
	// static char *line;
	char *ret;
	int i;

	i = 0;
	rest = ft_strnew(ft_strlen(ft_strchr(str, '\n')));
	// line = ft_strnew(ft_strlen(str));
	rest = ft_strdup(ft_strchr(str, '\n'));
	if (ft_strsub(str, 0, ft_strlen(str) - ft_strlen(rest)) != NULL)
	{
		ret = ft_strsub(str, 0, ft_strlen(str) - ft_strlen(rest));
		return (ret);
	}
	return (ret);
}

int main(int argc, char **argv)
{
	(void)argc;
	int fd;
	char *line = NULL;
	int i = 0;

	fd = open(argv[1], O_RDONLY);
	while (ft_get_next_line(fd, &line) > 0 && i < 2)
	{
		ft_putstr(get_next_line(line));
		free(line);
		++i;
	}
	return (0);
}
