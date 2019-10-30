/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:20:34 by rgero             #+#    #+#             */
/*   Updated: 2019/10/30 19:37:16 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_stack	*ft_stacknew(t_link *link)
{
	t_stack *ret;

	if (!(ret = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	if (!link)
		ret->link = NULL;
	else
		ret->link = link;
	ret->next = NULL;
	return (ret);
}

static void	ft_push(t_stack **stack, t_link *link)
{
	t_stack  *new;

	new = ft_stacknew(link);
	if (*stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
}

void		ft_delete_dl(t_link *link, t_stack **stack, char type)
{
	t_link *tmp;

	tmp = link;
	if (type == 'r' && tmp->letter != 0) //defence deleting header
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