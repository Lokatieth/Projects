/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stick_verif.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: darabi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:50:23 by darabi            #+#    #+#             */
/*   Updated: 2015/12/08 13:50:00 by darabi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_stick_verif(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		while (str[i] != '#' && str[i])
			i++;
		if (ft_all_verif(str, i) == 0 && str[i] == '#')
			return (0);
		i++;
	}
	return (1);
}

int		ft_all_verif(char *str, int i)
{
	if ((i == 1 || i == 2) && (str[i - 1] == '#' || str[i + 1]
			== '#' || str[i + 5] == '#'))
		return (1);
	else if ((i == 3) && (str[i - 1] == '#' || str[i + 5] == '#'))
		return (1);
	else if ((i == 5 || i == 10) && (str[i - 5] == '#' || str[i + 1] == '#'\
			|| str[i + 5] == '#'))
		return (1);
	else if ((i == 6 | i == 7 | i == 11 || i == 12) && (str[i - 1] == '#' || \
		str[i - 5] == '#' || str[i + 1] == '#' || str[i + 5] == '#'))
		return (1);
	else if ((i == 8 || i == 13) && (str[i - 1] == '#' || str[i - 5] == '#' \
			|| str[i + 5] == '#'))
		return (1);
	else if ((i == 15) && (str[i - 5] == '#' || str[i + 1] == '#'))
		return (1);
	else if ((i == 16 || i == 17) && (str[i - 5] == '#' || str[i - 1] == \
			'#' || str[i + 1] == '#'))
		return (1);
	else if ((i == 18) && ((str[i - 1] == '#' || str[i - 5] == '#')))
		return (1);
	else if ((i == 0) && (str[i + 1] == '#' || str[i + 5] == '#'))
		return (1);
	return (0);
}
