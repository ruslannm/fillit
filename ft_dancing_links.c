/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dancing_links.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:28:21 by rgero             #+#    #+#             */
/*   Updated: 2019/11/05 18:34:27 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

t_stack	*ft_row_for_seach(t_link *root)
{
	t_link	*tmp;
	t_stack	*ret;

	ret = NULL;
	tmp = root->up;
	while (tmp != root)
	{
		if (!ft_push(&ret, tmp->root_side))
		{
			ft_del_stack(ret);
			return (NULL);
		}
		tmp = tmp->up;
	}
	return (ret);
}

int		ft_check_solution(t_stack *solution, int qnt)
{
	t_stack	*tmp;
	t_link	*link;
	int		i;
	int		ret;

	i = 1;
	ret = 0;
	while (i <= qnt)
	{
		tmp = solution;
		while (tmp)
		{
			link = tmp->link;
			if (link->letter == i)
				ret++;
			tmp = tmp->next;
		}
		i++;
	}
	return (ret);
}

int		ft_check_root(t_link *root, int qnt)
{
	t_link	*link;
	int		i;
	int		ret;

	i = 1;
	ret = 0;
	while (i <= qnt)
	{
		link = root->down;
		while (link != root)
		{
			if (link->letter == i)
			{
				ret++;
				break ;
			}
			link = link->down;
		}
		i++;
	}
	return (ret);
}

int		ft_dancing_links(t_link *root, t_stack *stack_row, t_stack **solution,
		int qnt, int deep)
{
	int		check[2];
	t_stack	*stack_delete_row;
	t_stack	*stack_delete_top;
	t_link	*row;

	stack_delete_row = NULL;
	stack_delete_top = NULL;
	while ((row = ft_pop(&stack_row)))
	{
//		ft_print_matrix(root);
		printf("deep=%i, letter=%i, row=%p\n", deep, row->letter, row);
		ft_move_same_letter(row, &stack_delete_row);
		ft_move_same_bits(row, &stack_delete_row, &stack_delete_top);
		ft_delete_dl(row, &(*solution), 'r');
		check[0] = ft_check_root(root, qnt);
		check[1] = ft_check_solution(*solution, qnt);
		if (check[1] == qnt)
			return (1);
		else if (check[0] + check[1] == qnt)
		{
			if ((ft_dancing_links(root, ft_row_for_seach(root), &(*solution),
				qnt, deep + 1)) == 1)
				return (1);
		}
		ft_undo_move(&stack_delete_row, &stack_delete_top, &(*solution));
	}
	return (0);
}

int		ft_count_row(t_link *top)
{
	t_link	*tmp;
	int		ret;

	ret = 0;
	tmp = top->down;
	while (tmp != top)
	{
		ret++;
		tmp = tmp->down;
	}
	return (ret);
}

t_stack	*ft_row_for_seach_fast(t_link *root)
{
	t_link	*tmp;
	t_link	*column;
	t_stack	*ret;
	int		count_max;
	int		count_row;

	column = root->right;
	count_max = ft_count_row(root);
	tmp = root->left;
	while (tmp != root)
	{
		count_row = ft_count_row(tmp);
		if (count_row <= count_max)
		{
			count_max = count_row;
			column = tmp;
		}
		tmp = tmp->left;
	}
	ret = NULL;
	tmp = column->up;
	while (tmp != column)
	{
		if (!ft_push(&ret, tmp->root_side))
		{
			ft_del_stack(ret);
			return (NULL);
		}
		tmp = tmp->up;
	}
	return (ret);
}

int		ft_dancing_links_fast(t_link *root, t_stack *stack_row, t_stack **solution,
		int qnt, int deep)
{
	int		check[2];
	t_stack	*stack_delete_row;
	t_stack	*stack_delete_top;
	t_link	*row;

	stack_delete_row = NULL;
	stack_delete_top = NULL;
	while ((row = ft_pop(&stack_row)))
	{
//		ft_print_matrix(root);
		printf("deep=%i, letter=%i, row=%p\n", deep, row->letter, row);
		ft_move_same_letter(row, &stack_delete_row);
		ft_move_same_bits(row, &stack_delete_row, &stack_delete_top);
		ft_delete_dl(row, &(*solution), 'r');
		check[0] = ft_check_root(root, qnt);
		check[1] = ft_check_solution(*solution, qnt);
		if (check[1] == qnt)
			return (1);
		else if (check[0] + check[1] == qnt)
		{
			if ((ft_dancing_links_fast(root, ft_row_for_seach_fast(root), &(*solution),
				qnt, deep + 1)) == 1)
				return (1);
		}
		ft_undo_move(&stack_delete_row, &stack_delete_top, &(*solution));
	}
	return (0);
}
