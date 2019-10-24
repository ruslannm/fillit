/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dancing_links.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:28:21 by rgero             #+#    #+#             */
/*   Updated: 2019/10/24 17:53:12 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int  ft_square(int nb)
{
	while (0 == ft_sqrt(nb))
		nb++;
	return (ft_sqrt(nb));
}

char    *ft_dancing_links(t_list *income, int qnt)
{
	t_list  *tmp;
	int     len;
	t_link	*root;
	t_link	*row;
	t_link	*tmp_row;
	t_link	*tmp_row_delete;
	t_link	*tmp_column;
	t_list	*solution;
	t_list	*stack_delete;

	tmp = income;
	len = ft_square(qnt * 4);
	
	// ft_get_header_min(root); get column with min bit
	row = (ft_get_header_min(root))->down; //first row for solution
	tmp_row = row;
	ft_move_same_letter(tmp_row, &stack_delete);   //delete row with same letter
	while (tmp_row->right != row)
	{
		tmp_column = tmp_row;
		while (tmp_column->down != tmp_row)
		{
			ft_delete_dl(tmp_column, &stack_delete, "row"); //delete row with same place
			tmp_column = tmp_column->down;
		}
		
		tmp_row = tmp_row->right;
	}
	
	return("ok\n");
}

int		ft_count_row(t_link *header)
{
	t_link	*tmp;
	int		i;

	tmp = header;
	i = 0;
	while (tmp->down != header)
	{
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
	amount_row = ft_count_row(root);
	tmp = root;
	while ((tmp = tmp->right) != root)
	{
		i = ft_count_row(tmp);
		if (i < amount_row)
			ret = tmp;
	}
	return (ret);
}

void	ft_delete_dl(t_link *link, t_list **stack, char *type)
{
	t_link *tmp;

	tmp = link;
	while (tmp != link)
	{
		if (type == "row")
		{
			tmp->down->up = tmp->up;
			tmp->up->down = tmp->down;
			tmp = tmp->right;
		}
		else
		{
			tmp->right->left = tmp->left;
			tmp->left->right = tmp->right;
			tmp = tmp->down;
		}
	}
	ft_push(*stack, link);
}

void	ft_restore_dl(t_list **stack, char *type)
{
	t_link	*tmp;
	t_link	*new;
	
	new = ft_pop(*stack);
	tmp = new;
	while (tmp != new)
	{
		if (type == "row")
		{
			tmp->down->up = tmp;
			tmp->up->down = tmp;
			tmp = tmp->right;
		}
		else
		{
			tmp->right->left = tmp;
			tmp->left->right = tmp;
			tmp = tmp->down;
		}
	}
}