/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dancing_links.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:28:21 by rgero             #+#    #+#             */
/*   Updated: 2019/10/25 16:43:43 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int  ft_square(int nb)
{
	while (0 == ft_sqrt(nb))
		nb++;
	return (ft_sqrt(nb));
}

int    ft_dancing_links(t_link *root, t_list **solution)
{
	int		ret;
	t_link	*row;
	t_link	*tmp_row_delete;
	t_link	*tmp_column;
	t_list	*stack_delete;
	t_link	*root_top;
	//tmp = income;
	//len = ft_square(qnt * 4);
	
//	row = (ft_get_header_min(root))->down; //first row for solution
//	tmp_row = row;
	ret = 0;
	if ((root_top = root->right) == root)
		return (1);  //there aren't any column

	while (root_top != root)
	{
		row = root_top->down;  //first row
		ft_move_same_letter(row, &stack_delete);   //delete row with same letter
		ft_move_same_bits(row, &stack_delete);
		ft_delete_dl(row, &(*solution), "row"); //move_to_solution
	    if ((ret = ft_check_column(root)) == 0)
			return (1);
		else if (ret == -1)
				;	//undo deletion
		else
			root_top = root_top->right;
	}
	if (root->right == root)
		return (1);
	else
		return (ft_dancing_links(root, &(*solution)))
	;
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

void	ft_delete_dl(t_link *link, t_list **stack, char *type)
{
	t_link *tmp;

	tmp = link;
	if (type == "row" && tmp->root_side->letter != 0) //defence deleting header
	{	
		while (tmp != link)
		{
			tmp->down->up = tmp->up;
			tmp->up->down = tmp->down;
			tmp = tmp->right;
		}
	}
	else
	{
		tmp->right->left = tmp->left;
		tmp->left->right = tmp->right;
	}
	ft_push(*stack, link);
}

void	ft_restore_dl(t_list **stack, char *type)
{
	t_link	*tmp;
	t_link	*new;
	
	new = ft_pop(*stack);
	tmp = new;
	if (type == "row")
	{
		while (tmp != new)
		{
			tmp->down->up = tmp;
			tmp->up->down = tmp;
			tmp = tmp->right;
		}
	}
	else
	{
		tmp->right->left = tmp;
		tmp->left->right = tmp;
	}
}