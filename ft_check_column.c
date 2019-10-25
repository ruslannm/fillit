/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_column.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:31:05 by rgero             #+#    #+#             */
/*   Updated: 2019/10/25 17:55:28 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
draft, for optimization
*/


static t_link *ft_get_header_min(t_link *root)
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
