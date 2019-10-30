/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dancing_links.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:28:21 by rgero             #+#    #+#             */
/*   Updated: 2019/10/30 18:18:05 by rgero            ###   ########.fr       */
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

int ft_check_solution(t_list *solution, int qnt)
{
	t_list  *tmp;
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
			link = tmp->content;
			if (link->letter == i)
				ret++;
			tmp = tmp->next;
		}
		i++;
	}
	if (ret == qnt)
		return (1);
	return (0);
}

int    ft_dancing_links(t_link *root, t_link *row, t_list **solution, int qnt)
{
	int		ret;
	int		check_s;
	t_list	*stack_delete_row;
	t_list	*stack_delete_top;
	
	stack_delete_row = NULL;
	stack_delete_top = NULL;
	ft_move_same_letter(row->root_side, &stack_delete_row);   //delete row with same letter
	ft_move_same_bits(row->root_side, &stack_delete_row, &stack_delete_top);
	ft_delete_dl(row->root_side, &(*solution), 'r'); //move_to_solution  r - row
 	ft_print_matrix(root);
	ret = ft_check_column(root);
	check_s = ft_check_solution(*solution, qnt);
	if (ret == 1 && check_s == 1)
		return (1);
	else if (ret == -1)
	{
		//if (row->down == row->root_top)
		//	return (-1);
		ft_undo_move(&stack_delete_row, &stack_delete_top, &(*solution)); 	//undo deletion
		return(ft_dancing_links(root, row->down, &(*solution), qnt)); 		
	}
	else
		return (ft_dancing_links(root, root->right->down, &(*solution), qnt));
}