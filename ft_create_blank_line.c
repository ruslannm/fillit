/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_blank_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:55:51 by fprovolo          #+#    #+#             */
/*   Updated: 2019/10/31 14:28:19 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_link  *ft_create_blank_line(int len)
{
    int     i;
    t_link  *ptr;
    t_link  *next;

    if (!(ptr = (t_link *)malloc(sizeof(t_link))))
        return (NULL);
    ptr->left = ptr;
    ptr->right = ptr;
    ptr->root_side = ptr;
    i = 1;
    while (i < len)
    {
        if (!(next = (t_link *)malloc(sizeof(t_link))))
        {
            ft_free_line(ptr);
            return (NULL);
        }
        next->left = ptr;
        next->right = ptr->right;
        ptr->right->left = next;
        ptr->right = next;
        next->root_side = ptr;
        i++;
    }
    return (ptr);
}

void    ft_free_line(t_link *line)
{
    t_link  *del;

    line = line->right;
    while (line != line->root_side)
    {
        del = line;
        line = line->right;
        free(del);
    }
    free(line);
    return ;
}

void    ft_free_matrix(t_link *ptr)
{
    t_link  *del;

    ptr = ptr->down;
    while(ptr != ptr->root_top)
    {
        del = ptr;
        ptr = ptr->down;
        ft_free_line(del);
    }
    ft_free_line(ptr);
    return ;
}