/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:20:34 by rgero             #+#    #+#             */
/*   Updated: 2019/10/23 18:32:08 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_push(t_list **stack, t_link *link)
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