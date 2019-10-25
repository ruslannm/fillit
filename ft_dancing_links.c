/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dancing_links.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:28:21 by rgero             #+#    #+#             */
/*   Updated: 2019/10/25 17:57:28 by rgero            ###   ########.fr       */
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
	

static int		ft_count_row(t_link *top, char *mask)
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
		if (ft_count_row(tmp, "all") == 0)
			return (-1);
		else
		ret = 0;
	}
	return (ret);
}

int    ft_dancing_links(t_link *root, t_link *row, t_list **solution)
{
	int		ret;
	t_link	*row;
	t_list	*stack_delete_row;
	t_list	*stack_delete_top;
	
	ft_move_same_letter(row, &stack_delete_row);   //delete row with same letter
	ft_move_same_bits(row, &stack_delete_row, &stack_delete_top);
	ft_delete_dl(row, &(*solution), "row"); //move_to_solution
	ret = ft_check_column(root);
	if (ret == 1)
		return (1);
	else if (ret == -1)
	{
		ft_undo_move(&stack_delete_row, &stack_delete_top, *solution); 	//undo deletion
		return(ft_dancing_links(root, row->down, &solution)); 		
	}
	else
		return (ft_dancing_links(root, root->right->down, &(*solution)));
}