/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:08:23 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/05 14:45:04 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

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

void     ft_add_to_matrix(t_link *root, t_link *line)
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
        while (root->bit != line->bit)
            root = root->right;
        line->up = root->up;
        line->down = root;
        line->root_top = root;
        root->up->down = line;
        root->up = line;
        line = line->right;
    }
    return ;
}

t_link  *ft_add_tetra(t_link *root, char *tet, int pt, unsigned char letter, t_stack **matrix_stk)
{
    int     i;
    t_link  *new;
    t_link  *ptr;

    if (!(new = ft_create_blank_line(5, matrix_stk)))
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

t_link  *ft_init_header(int size, t_stack **matrix_stk)
{
    t_link          *root;
    t_link          *ptr;
    unsigned char   i;
    
    if ((!(root = ft_create_blank_line(size * size + 1, matrix_stk))) || size > 15)
        return (NULL);
    ptr = root;
    i = 0;
    while (i < size * size)
    {
        ptr->letter = 0;
        ptr->bit = i;
        ptr->up = ptr;
        ptr->down = ptr;
        ptr->root_top = ptr;
        if (ptr->root_side == ptr)
            ptr->bit = size;
        else
            i++;
        ptr = ptr->right;
    }
    return (root);
}

t_link  *ft_fill_matrix(t_list *income, int size, t_stack **matrix_stk)
{
    int             pt;
    t_link          *root;
    unsigned char   letter;

    if (!(root = ft_init_header(size, matrix_stk)))
        return (NULL);
    letter = 0;
    while (income)
    {
        pt = 0;
        letter++;
        while (pt < size * size)
        {
            if (ft_check_fit((char *)income->content, pt, size))
                if (!(ft_add_tetra(root, (char *)income->content, pt, letter, matrix_stk)))
                    return (NULL);
            pt++;
        }
        income = income->next;
    }
  /*
   if (!(ft_add_dummy(root, letter, matrix_stk)))
       return (NULL);
       */
    return (root);
}