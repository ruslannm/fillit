/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_same_bits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 15:29:30 by rgero             #+#    #+#             */
/*   Updated: 2019/11/01 15:02:44 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_move_same_bit(t_link *row, t_stack **stack_row,
			t_stack **stack_top)
{
	t_link	*row_to_stack;

	row_to_stack = row->down;
	while (row_to_stack != row)
	{
		if (row_to_stack == row->root_top)
			ft_delete_dl(row_to_stack, &(*stack_top), 'c');
		else
			ft_delete_dl(row_to_stack, &(*stack_row), 'r');
		row_to_stack = row_to_stack->down;
	}
}

void		ft_move_same_bits(t_link *row, t_stack **stack_row,
			t_stack **stack_top)
{
	t_link	*tmp;

	tmp = row->right;
	while (tmp != row)
	{
		if (row->root_side != tmp)
			ft_move_same_bit(tmp, &(*stack_row), &(*stack_top));
		tmp = tmp->right;
	}
}
