/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_tetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 14:35:41 by rgero             #+#    #+#             */
/*   Updated: 2019/10/20 15:53:31 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char *ft_move_limit_tetra(char *s, int square, int limit[2], int move)
{
	int i;
	char *ret;

	ret = s;
	ft_memmove(&s[limit[0] - move], &s[limit[0]], limit[1] - limit[0] + 1);
	i = limit[1] - move + 1;
	while (i < square)
		ret[i++] = '.'; 
	return (ret);
}

char *ft_move_tetra(char *s, int square)
{
	int i;
	int h;
	int w;
	int limit[2];

	i = 0;
	h = -1;
	w = -1;
	limit[0] = -1;
	while (i < square)
	{
		if (s[i] == '#')
		{
			if (h < 0 && h < i / 4)
				h = i / 4;
			if ((w < 0 && w < i % 4) || (w >= 0 && w > i % 4))
				w = i % 4;
			if (limit[0] < 0) 
				limit[0] = i;
			limit[1] = i;
		}
		i++;
	}
 	s = ft_move_limit_tetra(s, square, limit, h * 4 + w);
	return (s);
}