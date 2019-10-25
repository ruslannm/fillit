/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_same_bits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:29:30 by rgero             #+#    #+#             */
/*   Updated: 2019/10/25 16:13:20 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_move_same_bit(t_link *row, t_link **stack)
{
	t_link  *root_top;
	t_link  *row_to_stack;

	root_top =row->root_top;
	row_to_stack = row->down;
	while (row_to_stack->down != row)
	{
		row_to_stack = row_to_stack->down;
		if (row_to_stack == row->root_top)
			ft_delete_dl(row_to_stack, *stack, "column");
		else
			ft_delete_dl(row_to_stack, *stack, "row");
		row_to_stack = row_to_stack->down;
	}
}

void		ft_move_same_bits(t_link *row, t_link **stack)
{
	t_link  *tmp;
	t_link  *root_side;

	tmp = row;
	root_side =row->root_side;
	while (tmp->right != row)
	{
		if (root_side != tmp->root_top)
			ft_move_same_bit(tmp, &(*stack));
		tmp = tmp->right;
	}
}