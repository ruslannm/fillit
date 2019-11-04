/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_dl.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:20:34 by rgero             #+#    #+#             */
/*   Updated: 2019/11/04 17:44:20 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_delete_dl(t_link *link, t_stack **stack, char type)
{
	t_link *tmp;

	tmp = link;
	if (type == 'r' && tmp->letter != 0)
	{
		tmp = link->right;
		while (tmp != link)
		{
			tmp->down->up = tmp->up;
			tmp->up->down = tmp->down;
			tmp = tmp->right;
		}
		tmp->down->up = tmp->up;
		tmp->up->down = tmp->down;
	}
	else
	{
		tmp->right->left = tmp->left;
		tmp->left->right = tmp->right;
	}
	ft_push(&(*stack), link);
}
