/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dancing_links.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:28:21 by rgero             #+#    #+#             */
/*   Updated: 2019/11/01 20:06:40 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdio.h"
#include "fillit.h"

int	ft_count_row(t_link *top, char mask)
{
	t_link	*tmp;
	int		i;

	tmp = top;
	i = 0;
	while (tmp->down != top)
	{
		if (mask == 'a')
			i++;
		else if (tmp->root_side->letter >= 1 && tmp->root_side->letter <= 26)
			i++;
		tmp = tmp->down;
	}
	return (i);
}

t_link	*ft_find_start_row(t_link *root)
{
	t_link	*tmp;
	t_link	*ret;
	int		count_row;
	int		count_row_tmp;

	ret = root->right;
	count_row = 26;
	tmp = root->left;
	while (tmp != root)
	{
		count_row_tmp = ft_count_row(tmp, 't');
		if (count_row_tmp <= count_row)
		{
			count_row = count_row_tmp;
			ret = tmp;
		}
		tmp = tmp->left;
	}
	return (ret->down->root_side);
}

/*
** 1 - not column (solution)
** 0 - there are column (go ahead)
** -1 - there are empty column (go back, undo deletion)
*/

int	ft_check_column(t_link *root)
{
	t_link	*tmp;
	int		ret;

	ret = 1;
	tmp = root;
	while (tmp->right != root)
	{
		tmp = tmp->right;
		if (ft_count_row(tmp, 'a') == 0)
			return (-1);
		else
			ret = 0;
	}
	return (ret);
}

int	ft_check_solution(t_stack *solution, int qnt)
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

int	ft_check_root(t_link *root, int qnt)
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

int	ft_dancing_links(t_link *root, t_link *row, t_stack **solution, int qnt)
{
	int		ret;
	int		check_s;
	t_stack	*stack_delete_row;
	t_stack	*stack_delete_top;
	t_link	*tmp;

	stack_delete_row = NULL;
	stack_delete_top = NULL;
	tmp = row;
	while (1)
	{
		printf(" %p\n", row->root_side);
		if (row->root_side->letter == 5)
			printf("letter = 5\n");
		ft_move_same_letter(tmp->root_side, &stack_delete_row);
		ft_move_same_bits(tmp->root_side, &stack_delete_row, &stack_delete_top);
		ft_delete_dl(tmp->root_side, &(*solution), 'r');
		ft_print_matrix(root);
		ret = ft_check_column(root);
		check_s = ft_check_solution(*solution, qnt) + ft_check_root(root, qnt);
		if (ret == 1 && check_s == qnt)
			return (1);
		else if (ret == -1 || check_s != qnt)
		{
			ft_undo_move(&stack_delete_row, &stack_delete_top, &(*solution));
			printf("After undo, ret=%d, check_s=%d=\n", ret, check_s);
			ft_print_matrix(root);
			if (tmp->root_side->down->letter > 26 || tmp->root_side->down == root)
				return (-1);
			tmp = tmp->root_side->down;
		}
		else if (check_s == qnt)
		{
			if ((ft_dancing_links(root, ft_find_start_row(root), &(*solution), qnt)) == 1)
				return (1);
			ft_undo_move(&stack_delete_row, &stack_delete_top, &(*solution));
			printf("After recursive undo, ret=%d, check_s=%d=\n", ret, check_s);
			ft_print_matrix(root);
			if (tmp->root_side->down == root)
				return (-1);
			tmp = tmp->root_side->down;
		}
	}
}

/*
int	ft_dancing_links(t_link *root, t_link *row, t_stack **solution, int qnt)
{
	int		ret;
	int		check_s;
	t_stack	*stack_delete_row;
	t_stack	*stack_delete_top;

	stack_delete_row = NULL;
	stack_delete_top = NULL;
	ft_move_same_letter(row->root_side, &stack_delete_row);
	ft_move_same_bits(row->root_side, &stack_delete_row, &stack_delete_top);
	ft_delete_dl(row->root_side, &(*solution), 'r');
	ft_print_matrix(root);
	ret = ft_check_column(root);
	check_s = ft_check_solution(*solution, qnt) + ft_check_root(root, qnt);
	if (ret == 1 && check_s == qnt)
		return (1);
	else if (ret == -1 || check_s != qnt)
	{
		ft_undo_move(&stack_delete_row, &stack_delete_top, &(*solution));
		printf("After undo, ret=%d, check_s=%d=\n", ret, check_s);
		ft_print_matrix(root);
		if (row->root_side->down == root)
			return (-1);
		return (ft_dancing_links(root, row->root_side->down, &(*solution),
				qnt));
	}
	else if (check_s == qnt)
		return (ft_dancing_links(root, root->down, &(*solution), qnt));
	return (-1);
}
*/