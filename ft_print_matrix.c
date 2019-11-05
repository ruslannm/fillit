/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 12:47:00 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/01 15:49:39 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

void    ft_print_field(t_link *ptr, int size)
{
    int     pt;
    int     i;
    char    c;

    pt = 0;
    ptr = ptr->right;
    while (pt < size * size)
    {
        c = 31;
        i = 0;
        while (i < 4)
        {
            if (pt == ptr->bit)
                c = ptr->letter;
            ptr = ptr->right;
            i++;
        }
        printf("%c ", c + 64);
        if (pt % size == size - 1)
            printf("\n");
        pt++;
    }
    printf("\n");
}

void    ft_print_matrix(t_link *root)
{
    t_link  *column;
    t_link  *line;
    t_link  *ptr;

    printf("Size = %d\nHeader\nLetter ", root->bit);
    line = root->right;
    while (line != root)
    {
        if (line->bit < 10)
            printf("  %d", line->bit);
        else
            printf(" %d", line->bit);
        line = line->right;
    }
    printf(" Pointer    \n");
    
    line = root->down;
    while (line->root_top != line)
    {
        printf("     %d ", line->letter);
        column = root->right;
        ptr = line->right;
        while (column->root_side != column)
        {
            if (column->bit == ptr->bit)
            {
                printf("  %d", ptr->letter);
                ptr = ptr->right;
            }
            else
                printf("  -");
            column = column->right;
        }
        printf(" %p\n", line);
        line = line->down;
    }
/*    ptr = root->down;
    while (ptr->root_top != ptr)
    {
        printf("%d-%d\t", ptr->letter, ptr->bit);
        printf("%d-%d\t", ptr->right->letter, ptr->right->bit);
        printf("%d-%d\t", ptr->right->right->letter, ptr->right->right->bit);
        printf("%d-%d\t", ptr->right->right->right->letter, ptr->right->right->right->bit);
        printf("%d-%d\t", ptr->right->right->right->right->letter, ptr->right->right->right->right->bit);
        printf("\n");
        ptr = ptr->down;
    }*/
}