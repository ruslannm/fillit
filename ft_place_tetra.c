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

t_link  *ft_create_blank_line()
{
    int     i;
    t_link *ptr;
    t_link *next;

    if (!(ptr = (t_link *)malloc(sizeof(t_link))))
        return (NULL);
    ptr->left = ptr;
    ptr->right = ptr ;
    i = 1;
    while (i < 5)
    {
        if (!(next = (t_link *)malloc(sizeof(t_link))))
            return (NULL);
        next->left = ptr;
        next->right = ptr->right;
        ptr->right = next;
        next->right->left = next;
        i++;
    }
    return (ptr);
}

int     ft_check_fit(char *tet, int pt, int size)
{
    int i;

    i = 0;
    while (i < 16)
    {
        if (tet[i] == '#')
            if (pt % size + i % 4 >= size || pt / size + i / 4 >= size)
                return (0);
        i++;
    }
    return (1);
}

void    ft_print_field(t_link *ptr, int size)
{
    int i;
    int j;
    int pt;

    i = 0;
    j = 0;
    while (i < size)
    {
        while (j < size)
        {
            pt = i * j;
            if (pt == (int)ptr->bit || pt == (int)ptr->right->bit ||
                    pt == (int)ptr->right->right->bit || pt == (int)ptr->right->right->right->bit)
                printf("A");
            else
                printf("-");
            j++;
        }
        i++;
        printf("\n");
    }
}

void    ft_place_tetra(char *tet, char name, int size)
{
    int     i;
    int     pt;
    t_link  *ptr;
    
    pt = 0;
    while (pt < size * size)
    {
        if (ft_check_fit(tet, pt, size))
        {
            ptr = ft_create_blank_line();
            i = 0;
            while (i < 16) 
            {
                if (tet[i] == '#')
                {
                    ptr->bit = (unsigned char)(pt + i / 4 * size + i % 4);
                    printf("%d\t", pt + i / 4 * size + i % 4);
                    ptr->letter = name;
                    ptr = ptr->right;
                }
                i++;
            }
            printf("\n");
        }
/*        ft_print_field(ptr, size);*/
        pt++;
    }
}