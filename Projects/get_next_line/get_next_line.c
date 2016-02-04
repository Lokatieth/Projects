/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 17:30:33 by vbauguen          #+#    #+#             */
/*   Updated: 2016/02/03 23:37:33 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		return_line(char **line, char **rest)
{
	char		*tmp;

	*line = ft_strsub(*rest, 0, ft_strchr(*rest, '\n') - *rest);
	tmp = *rest;
	*rest = ft_strsub(*rest, ft_strlen(*line) + 1,
		ft_strlen(*rest) - ft_strlen(*line));
	free(tmp);
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	static char	*rest = NULL;
	char		buffer[BUFF_SIZE + 1];
	int			ret;

	if (!rest)
		rest = ft_strnew(BUFF_SIZE);
	if (ft_strchr(rest, '\n'))
		return (return_line(line, &rest));
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		rest = ft_strjoinopt(rest, buffer);
		if (ft_strchr(rest, '\n'))
			return (return_line(line, &rest));
	}
	if (ret < 0 || fd < 0)
		return (-1);
	if (ft_strlen(rest) > 0)
	{
		*line = ft_strdup(rest);
		rest = NULL;
		return (1);
	}
	return (0);
}
