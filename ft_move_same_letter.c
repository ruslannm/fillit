/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_same_letter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:02:19 by rgero             #+#    #+#             */
/*   Updated: 2019/10/24 19:38:42 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    ft_move_same_letter(t_link *row, t_link **stack)
{
	t_link  *root_side;
	t_link  *row_to_stack;

	root_side = row->root_side;
	row_to_stack = root_side->down;
	while (row_to_stack != root_side)
	{
		if (row_to_stack->letter == root_side->letter)
			ft_delete_dl(row_to_stack, *stack, "row");
		row_to_stack = row_to_stack->down;
	}
}
