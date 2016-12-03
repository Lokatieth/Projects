/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 13:29:45 by vbauguen          #+#    #+#             */
/*   Updated: 2016/12/03 03:21:46 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	mallocsize(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		i++;
	while (s2[j] != '\0')
		j++;
	return (i + j + 1);
}

char		*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*dst;

	j = -1;
	i = -1;
	dst = ft_strnew(mallocsize(s1, s2) + 1);
	if (dst == NULL)
		return (NULL);
	while (s1[++i])
		dst[i] = s1[i];
	while (s2[++j])
		dst[i + j] = s2[j];
	dst[i + j] = '\0';
	return (dst);
}
