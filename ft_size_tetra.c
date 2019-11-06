/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_tetra.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:58:58 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/06 13:19:51 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_size_tetra(char *tetra)
{
	int	i;
	int	size;

	i = 0;
	size = 1;
	while (i < 16)
	{
		if (tetra[i] == '#')
		{
			if (i % 4 + 1 > size)
				size = i % 4 + 1;
			if (i / 4 + 1 > size)
				size = i / 4 + 1;
		}
		i++;
	}
	return (size);
}
