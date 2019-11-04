/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:20:34 by rgero             #+#    #+#             */
/*   Updated: 2019/11/04 12:53:41 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
static void	ft_del(void *content, size_t len)
{
	//ft_bzero(content, len);
	if (len > 0)
		free(content);
}
*/

t_link	*ft_pop(t_stack **stack)
{
	t_stack	*tmp;
    t_link  *ret;

    if (*stack == NULL)
		return (NULL);
	else
	{
	    tmp = *stack;
		ret = tmp->link;
		*stack = (*stack)->next;
        free(tmp);
		//ft_lstdel(&tmp, &ft_del);
        return (ret);
	}
}

static void	ft_restore_dl(t_stack **stack, char type)
{
	t_link	*tmp;
	t_link	*new;
	
	new = ft_pop(&(*stack));
	if (type == 'r')
	{
		tmp = new->right;
		while (tmp != new)
		{
			tmp->down->up = tmp;
			tmp->up->down = tmp;
			tmp = tmp->right;
		}
		tmp->down->up = tmp;
		tmp->up->down = tmp;
	}
	else
	{
		tmp = new;
		tmp->right->left = tmp;
		tmp->left->right = tmp;
	}
}

void    ft_undo_move(t_stack **stack_row, t_stack **stack_top, t_stack **solution)
{
	ft_restore_dl(solution, 'r');
	while (*stack_top)	
		ft_restore_dl(stack_top, 'c');
 	while (*stack_row)
		ft_restore_dl(stack_row, 'r');
}