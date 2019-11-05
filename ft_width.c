/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_width.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:58:58 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/05 18:33:05 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int     ft_size(char *tetra)
{
    int i;
    int size;

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