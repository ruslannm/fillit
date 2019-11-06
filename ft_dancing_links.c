/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dancing_links.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:28:21 by rgero             #+#    #+#             */
/*   Updated: 2019/11/06 18:55:23 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_del_st(t_stack *stack, t_stack *stack_del_row,
	t_stack *stack_del_top, int ret)
{
	while (stack)
		ft_pop(&stack);
	while (stack_del_row)
		ft_pop(&stack_del_row);
	while (stack_del_top)
		ft_pop(&stack_del_top);
	return (ret);
}

int	ft_dancing_links(t_link *root, t_stack *stack_row, t_stack **solution,
		int qnt)
{
	int		check[2];
	t_stack	*stack_del_row;
	t_stack	*stack_del_top;
	t_link	*row;

	stack_del_row = NULL;
	stack_del_top = NULL;
	while ((row = ft_pop(&stack_row)))
	{
		ft_move_same_letter(row, &stack_del_row);
		ft_move_same_bits(row, &stack_del_row, &stack_del_top);
		ft_delete_dl(row, &(*solution), 'r');
		check[0] = ft_check_root(root, qnt);
		check[1] = ft_check_solution(*solution, qnt);
		if (check[1] == qnt)
			return (ft_del_st(stack_row, stack_del_row, stack_del_top, 1));
		else if (check[0] + check[1] == qnt)
		{
			if ((ft_dancing_links(root, ft_row_for_seach(root), &(*solution),
				qnt)) == 1)
				return (ft_del_st(stack_row, stack_del_row, stack_del_top, 1));
		}
		ft_undo_move(&stack_del_row, &stack_del_top, &(*solution));
	}
	return (ft_del_st(stack_row, stack_del_row, stack_del_top, 0));
}

int	ft_dancing_links_fast(t_link *root, t_stack *stack_row, t_stack **solution,
		int qnt)
{
	int		check[2];
	t_stack	*stack_del_row;
	t_stack	*stack_del_top;
	t_link	*row;

	stack_del_row = NULL;
	stack_del_top = NULL;
	while (root && (row = ft_pop(&stack_row)))
	{
		ft_move_same_letter(row, &stack_del_row);
		ft_move_same_bits(row, &stack_del_row, &stack_del_top);
		ft_delete_dl(row, &(*solution), 'r');
		check[0] = ft_check_root(root, qnt);
		check[1] = ft_check_solution(*solution, qnt);
		if (check[1] == qnt)
			return (ft_del_st(stack_row, stack_del_row, stack_del_top, 1));
		else if (check[0] + check[1] == qnt)
		{
			if ((ft_dancing_links_fast(root, ft_row_for_seach_fast(root),
				&(*solution), qnt)) == 1)
				return (ft_del_st(stack_row, stack_del_row, stack_del_top, 1));
		}
		ft_undo_move(&stack_del_row, &stack_del_top, &(*solution));
	}
	return (ft_del_st(stack_row, stack_del_row, stack_del_top, 0));
}
