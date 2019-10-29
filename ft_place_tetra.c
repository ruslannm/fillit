/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place_tetra.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:08:23 by fprovolo          #+#    #+#             */
/*   Updated: 2019/10/28 16:58:36 by fprovolo         ###   ########.fr       */
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

    printf("Size = %d\n", root->bit);
    line = root->down;
    while (line->root_top != line)
    {
        column = root->right;
        ptr = line->right;
        while (column->root_side != column)
        {
            if (column->bit == ptr->bit)
            {
                printf(" %d", ptr->letter);
                ptr = ptr->right;
            }
            else
                printf(" -");
            column = column->right;
        }
        line = line->down;
        printf("\n");
    }
    ptr = root->down;
    while (ptr->root_top != ptr)
    {
        printf("%d-%d\t", ptr->letter, ptr->bit);
        printf("%d-%d\t", ptr->right->letter, ptr->right->bit);
        printf("%d-%d\t", ptr->right->right->letter, ptr->right->right->bit);
        printf("%d-%d\t", ptr->right->right->right->letter, ptr->right->right->right->bit);
        printf("%d-%d\t", ptr->right->right->right->right->letter, ptr->right->right->right->right->bit);
        printf("\n");
        ptr = ptr->down;
    }
}

t_link  *ft_add_tetra(t_link *root, char *tet, int pt, unsigned char letter)
{
    int     i;
    t_link  *new;
    t_link  *rt;

    if (!(new = ft_create_blank_line(5)))
        return (NULL);
    new->letter = letter;
    new->bit = 99;
    new->up = root->up;
    new->down = root;
    root->up->down = new;
    root->up = new;
    new = new->right;
    i = 0;
    while (i < 16)
    {
        if (tet[i] == '#')
        {
            new->bit = (unsigned char)(pt + i / 4 * root->bit + i % 4);
            new->letter = letter;   
            rt = root->right;
            while (rt->bit != new->bit)
                rt = rt->right;
            new->up = rt->up;
            new->down = rt;
            rt->up->down = new;
            rt->up = new;
            new = new->right;
        }
        i++;
    }
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

ft_add_dummy(t_link *root, unsigned char letter)
{
    int i;

    while (letter <= root->bit * root->bit)
    {
        
        letter++;
    }

}

t_link  *ft_fill_matrix(t_list *income, int size)
{
    int             pt;
    t_link          *root;
    unsigned char   letter;

    if (!(root = ft_init_header(size)))
        return (NULL);
    letter = 1;
    while (income)
    {
        pt = 0;
        while (pt < size * size)
        {
            if (ft_check_fit((char *)income->content, pt, size))
                if (!(ft_add_tetra(root, (char *)income->content, pt, letter)))
                    return (NULL);
            pt++;
        }
        letter++;
        income = income->next;
    }
    return (root);
}