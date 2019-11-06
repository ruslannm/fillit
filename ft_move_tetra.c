/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_tetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 14:35:41 by rgero             #+#    #+#             */
/*   Updated: 2019/11/06 16:27:35 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	*ft_move_limit_tetra(char *s, int square, int limit[2], int move)
{
	int		i;
	char	*ret;

	ret = s;
	ft_memmove(&s[limit[0] - move], &s[limit[0]], limit[1] - limit[0] + 1);
	i = limit[1] - move + 1;
	while (i < square)
		ret[i++] = '.';
	return (ret);
}

char		*ft_move_tetra(char *s, int square)
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

int			ft_summa_tetra(char *s)
{
	int i;
	int summa;

	i = 0;
	summa = 0;
	while (i < 16)
	{
		if (s[i] == '#')
		{
			if (i + 4 < 16)
				summa = summa + (s[i + 4] == '#' ? 1 : 0);
			if (i - 4 >= 0)
				summa = summa + (s[i - 4] == '#' ? 1 : 0);
			if (i + 1 < 4 * (i / 4) + 4)
				summa = summa + (s[i + 1] == '#' ? 1 : 0);
			if (i - 1 >= 4 * (i / 4))
				summa = summa + (s[i - 1] == '#' ? 1 : 0);
		}
		i++;
	}
	return (summa == 6 || summa == 8 ? 0 : -1);
}

int			ft_check_tetra(char *s, t_list **income)
{
	int		i;
	t_list	*new;

	i = 0;
	while (s[i] != '\0')
	{
		if (!(s[i] == '#' || s[i] == '.'))
			return (-1);
		i++;
	}
	if (ft_summa_tetra(s) == -1)
		return (-1);
	s = ft_move_tetra(s, 4 * 4);
	if (!(new = ft_lstnew(s, 17)))
		return (-1);
	ft_lstaddback(&(*income), new);
	return (0);
}
