/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dancing_links.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:28:21 by rgero             #+#    #+#             */
/*   Updated: 2019/10/25 17:34:50 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int  ft_square(int nb)
{
	while (0 == ft_sqrt(nb))
		nb++;
	return (ft_sqrt(nb));
}

	//tmp = income;
	//len = ft_square(qnt * 4);
	
//	row = (ft_get_header_min(root))->down; //first row for solution
//	tmp_row = row;

int    ft_dancing_links(t_link *root, t_list **solution)
{
	int		ret;
	t_link	*row;
	t_list	*stack_delete_row;
	t_list	*stack_delete_top;
	t_link	*root_top;
	
	ret = 0;
	root_top = root->right;
	row = root_top->down;  //first row
	while (root_top != root)
	{
		ft_move_same_letter(row, &stack_delete_row);   //delete row with same letter
		ft_move_same_bits(row, &stack_delete_row, &stack_delete_top);
		ft_delete_dl(row, &(*solution), "row"); //move_to_solution
	    ret = ft_check_column(root);
		if (ret == 0)
			return (1);
		else if (ret == -1)
		{
			ft_undo_move(&stack_delete_row, &stack_delete_top, *solution); 	//undo deletion
			row = row->down; 		
		}
		else
			return (ft_dancing_links(root, &(*solution)));
	}
}

int		ft_count_row(t_link *top, char *mask)
{
	t_link	*tmp;
	int		i;

	tmp = top;
	i = 0;
	while (tmp->down != top)
	{
		if (mask == "all")
			i++;
		else if (tmp->root_side->letter >= 'A' && tmp->root_side->letter <='Z')
			i++;
		tmp = tmp->down;
	}
	return (i);
}

t_link *ft_get_header_min(t_link *root)
{
	t_link	*tmp;
	t_link	*ret;
	int		amount_row;
	int		i;

	i = 0;
	ret = NULL;
	amount_row = ft_count_row(root, "tetra");
	tmp = root;
	while ((tmp = tmp->right) != root)
	{
		i = ft_count_row(tmp, "tetra");
		if (i < amount_row)
			ret = tmp;
	}
	if (!ret && root->right != root)
		ret = root->right;  //work when tetra is missing
	return (ret);
}