/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tetra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:08:23 by fprovolo          #+#    #+#             */
/*   Updated: 2019/10/30 18:14:08 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
            return (NULL);
        next->left = ptr;
        next->right = ptr->right;
        ptr->right->left = next;
        ptr->right = next;
        next->root_side = ptr;
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

int     ft_add_to_matrix(t_link *root, t_link *line)
{
    line->up = root->up;
    line->down = root;
    line->root_top = root;
    root->up->down = line;
    root->up = line;

    line = line->right;
    root = root->right;
    while (line->root_side != line)
    {
        while (root->bit != line->bit && root->root_side != root)
            root = root->right;
        if (root->root_side == root)
            return (0);
        line->up = root->up;
        line->down = root;
        line->root_top = root;
        root->up->down = line;
        root->up = line;
        line = line->right;
    }
    return (1);
}

t_link  *ft_add_tetra(t_link *root, char *tet, int pt, unsigned char letter)
{
    int     i;
    t_link  *new;
    t_link  *ptr;

    if (!(new = ft_create_blank_line(5)))
        return (NULL);
    new->letter = letter;
    new->bit = 99;
    ptr = new->right;
    i = 0;
    while (i < 16)
    {
        if (tet[i] == '#')
        {
            ptr->bit = (unsigned char)(pt + i / 4 * root->bit + i % 4);
            ptr->letter = letter;   
            ptr = ptr->right;
        }
        i++;
    }
    ft_add_to_matrix(root, new);
    return (new);
}

t_link  *ft_init_header(int size)
{
    t_link          *root;
    t_link          *ptr;
    unsigned char   i;
    
    if ((!(root = ft_create_blank_line(size * size + 1))) || size > 15)
        return (NULL);
    root->letter = 0;
    root->bit = size;
    root->up = root;
    root->down = root;
    root->root_top = root;
    root->root_side = root;
    ptr = root->right;
    i = 0;
    while (i < size * size)
    {
        ptr->letter = 0;
        ptr->bit = i;
        ptr->up = ptr;
        ptr->down = ptr;
        ptr->root_top = ptr;
        ptr->root_side = root;
        ptr = ptr->right;
        i++;
    }
    return (root);
}

int     ft_add_dummy(t_link *root, unsigned char letter)
{
    unsigned char   pt;
    unsigned char   len;
    t_link          *new;

    pt = 0;
    len = root->bit * root->bit;
    while (pt < len && letter * 4 < len)
    {
        if (!(new = ft_create_blank_line(2)))
            return (0);
        new->letter = 27 + pt;
        new->bit = 99;
        new->right->letter = 27 + pt;
        new->right->bit = pt;
        ft_add_to_matrix(root, new);
        pt++;
    }
    return (1);
}

t_link  *ft_fill_matrix(t_list *income, int size)
{
    int             pt;
    t_link          *root;
    unsigned char   letter;

    if (!(root = ft_init_header(size)))
        return (NULL);
    letter = 0;
    while (income)
    {
        pt = 0;
        letter++;
        while (pt < size * size)
        {
            if (ft_check_fit((char *)income->content, pt, size))
                if (!(ft_add_tetra(root, (char *)income->content, pt, letter)))
                    return (NULL);
            pt++;
        }
        income = income->next;
    }
    ft_add_dummy(root, letter);
    return (root);
}