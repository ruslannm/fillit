/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tetra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:08:23 by fprovolo          #+#    #+#             */
/*   Updated: 2019/10/22 17:08:44 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

t_tetra *ft_create_blank_line()
{
    int     i;
    t_tetra *ptr;
    t_tetra *next;

    if (!(ptr = (t_tetra *)malloc(sizeof(t_tetra))))
        return (NULL);
    ptr->left = ptr;
    ptr->right = ptr ;
    i = 1;
    while (i < 4)
    {
        if (!(next = (t_tetra *)malloc(sizeof(t_tetra))))
            return (NULL);
        next->left = ptr;
        next->right = ptr->right;
        ptr->right = next;
        next->right->left = next;
        i++;
    }
    return (ptr);
}

char    *ft_place_tetra(char *tetra, char name, int size)
{
    int     i;
    int     point;
    int     col;
    int     line;
    int     addr;

    point = 0;
    while (point < size * size)
    {
        i = 0;
        while (i < 16) 
        {
            if (tetra[i] == '#')
                if ((col = point % size + i % 4) < size &&
                         (line = point / size + i / 4) < size)
                    addr = line * size + col;
                else
                    err = 1;
            i++;
        }
        point++;
    }
}