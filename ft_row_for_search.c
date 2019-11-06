/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_row_for_search.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:28:21 by rgero             #+#    #+#             */
/*   Updated: 2019/11/06 15:08:13 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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

t_link	*ft_column_for_search(t_link *root)
{
	t_link	*tmp;
	t_link	*column;
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
	return (column);
}

t_stack	*ft_row_for_seach_fast(t_link *root)
{
	t_link	*tmp;
	t_link	*column;
	t_stack	*ret;

	ret = NULL;
	column = ft_column_for_search(root);
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
