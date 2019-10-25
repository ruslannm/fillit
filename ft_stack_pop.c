/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:20:34 by rgero             #+#    #+#             */
/*   Updated: 2019/10/25 17:11:47 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_del(void *content, size_t len)
{
	ft_bzero(content, len);
	free(content);
}

static t_link	*ft_pop(t_list **stack)
{
	t_list	*tmp;
    t_link  *ret;

    if (*stack == NULL)
		return (NULL);
	else
	{
	    tmp = *stack;
		while (tmp->next)
        	tmp = tmp->next;
		ret = tmp->content;
        ft_lstdel(*stack, &ft_del);
        return (ret);
	}
}

static void	ft_restore_dl(t_list **stack, char *type)
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

void    ft_undo_move(t_list *stack_row, t_list *stack_top, t_list *solution)
{
	while (stack_row)
		ft_restore_dl(&stack_row, "row");
	while (stack_top)	
    	ft_restore_dl(&stack_top, "column");
    ft_restore_dl(&solution, "row");

}