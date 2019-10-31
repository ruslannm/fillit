/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dancing_links.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:28:21 by rgero             #+#    #+#             */
/*   Updated: 2019/10/31 17:31:47 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_count_row(t_link *top, char mask)
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

/* 1 - not column (solution)
   0 - there are column (go ahead)
   -1 - there are empty column (go back, undo deletion)
*/ 
int ft_check_column(t_link *root)
{
	t_link  *tmp;
	int ret;

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

int ft_check_solution(t_stack *solution, int qnt)
{
	t_stack  *tmp;
	t_link	*link;
	int i;
	int ret;

	i = 1;
	ret = 0;
	while (i <= qnt)
	{
		tmp = solution;
		while (tmp)
		{
			//link = tmp->content;
			link = tmp->link;
			if (link->letter == i)
				ret++;
			tmp = tmp->next;
		}
		i++;
	}
	return (ret);
}

int ft_check_root(t_link *root, int qnt)
{
	t_link	*link;
	int i;
	int ret;

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


int    ft_dancing_links(t_link *root, t_link *row, t_stack **solution, int qnt)
{
	int		ret;
	int		check_s;
	t_stack	*stack_delete_row;
	t_stack	*stack_delete_top;

	stack_delete_row = NULL;
	stack_delete_top = NULL;
	ft_move_same_letter(row->root_side, &stack_delete_row);   //delete row with same letter
	ft_move_same_bits(row->root_side, &stack_delete_row, &stack_delete_top);
	ft_delete_dl(row->root_side, &(*solution), 'r'); //move_to_solution  r - row
 	ft_print_matrix(root);
	ret = ft_check_column(root);
	check_s = ft_check_solution(*solution, qnt) + ft_check_root(root, qnt);
	if (ret == 1 && check_s == qnt)
		return (1);
	else if (ret == -1 || check_s != qnt)
	{
			ft_undo_move(&stack_delete_row, &stack_delete_top, &(*solution)); 	//undo deletion
			ft_print_matrix(root);
			if (row->root_side->down == root)
				return (-1);
			return (ft_dancing_links(root, row->root_side->down, &(*solution), qnt));
			//	return (-1); 		
	}
	else if (check_s == qnt)
		return (ft_dancing_links(root, root->down, &(*solution), qnt));
	return (-1);
}

/*
int    ft_dancing_links(t_link *root, t_link *row, t_stack **solution, int qnt)
{
	int		ret;
	int		check_s;
	t_stack	*stack_delete_row;
	t_stack	*stack_delete_top;

	stack_delete_row = NULL;
	stack_delete_top = NULL;
	while (row->root_side->down != root)
	{
		ft_move_same_letter(row->root_side, &stack_delete_row);   //delete row with same letter
		ft_move_same_bits(row->root_side, &stack_delete_row, &stack_delete_top);
		ft_delete_dl(row->root_side, &(*solution), 'r'); //move_to_solution  r - row
 		ft_print_matrix(root);
		ret = ft_check_column(root);
		check_s = ft_check_solution(*solution, qnt);
		if (ret == 1 && check_s == qnt)
			return (1);
		else if (ret == -1)
		{
			ft_undo_move(&stack_delete_row, &stack_delete_top, &(*solution)); 	//undo deletion
			ft_print_matrix(root);
			row = row->root_side->down;
			//return(ft_dancing_links(root, row->down, &(*solution), qnt)); 		
		}
		else
			row = row->root_side->down;
	//		return (ft_dancing_links(root, root->right->down, &(*solution), qnt));
	}
	return (-1);
}
*/