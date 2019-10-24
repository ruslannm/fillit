/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_same_letter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:02:19 by rgero             #+#    #+#             */
/*   Updated: 2019/10/24 17:41:03 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    ft_move_same_letter(t_link *row, t_link **stack)
{
    t_link  *vertical_header;
    t_link  *row_to_stack;

    vertical_header = row;
    while (vertical_header->bit != 0)
        vertical_header = vertical_header->left;
    row_to_stack = vertical_header->down;
    while (row_to_stack != vertical_header)
    {
        if (row_to_stack->letter == vertical_header->letter)
            ft_delete_dl(row_to_stack, *stack, "row");
        row_to_stack = row_to_stack->down;
    }
}

t_link  *ft_get_header(t_link *row, )