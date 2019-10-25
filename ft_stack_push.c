/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:20:34 by rgero             #+#    #+#             */
/*   Updated: 2019/10/25 16:42:25 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_push(t_list **stack, t_link *link)
{
	t_list	*tmp;
	t_list  *new;

	new = ft_lstnew(link, sizeof(link));
	if (*stack == NULL)
		*stack = new;
	else
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void		ft_delete_dl(t_link *link, t_list **stack, char *type)
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