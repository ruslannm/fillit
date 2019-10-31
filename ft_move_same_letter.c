/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_same_letter.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:02:19 by rgero             #+#    #+#             */
/*   Updated: 2019/10/31 18:43:11 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void    ft_move_same_letter(t_link *row, t_stack **stack)
{
	t_link  *row_to_stack;

	row_to_stack = row->down;
	while (row_to_stack != row)
	{
		if (row_to_stack->letter == row->letter)
			ft_delete_dl(row_to_stack, &(*stack), 'r');
		row_to_stack = row_to_stack->down;
	}
}
