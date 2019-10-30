/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:20:34 by rgero             #+#    #+#             */
/*   Updated: 2019/10/30 18:01:02 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_push(t_list **stack, t_link *link)
{
	t_list  *new;

	new = ft_lstnew(link, sizeof(*link));
	if (*stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

void		ft_delete_dl(t_link *link, t_list **stack, char type)
{
	t_link *tmp;

	tmp = link;
	if (type == 'r' && tmp->root_side->letter != 0) //defence deleting header
	{	
		while (tmp->right != link)
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