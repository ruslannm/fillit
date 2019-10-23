/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:20:34 by rgero             #+#    #+#             */
/*   Updated: 2019/10/23 18:52:52 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_del(void *content, size_t len)
{
	ft_bzero(content, len);
	free(content);
}

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

t_link	*ft_pop(t_list **stack)
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