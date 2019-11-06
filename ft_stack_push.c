/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:20:34 by rgero             #+#    #+#             */
/*   Updated: 2019/11/06 16:22:02 by rgero            ###   ########.fr       */
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

int				ft_push(t_stack **stack, t_link *link)
{
	t_stack	*new;

	new = ft_stacknew(link);
	if (!new)
		return (0);
	if (*stack == NULL)
		*stack = new;
	else
	{
		new->next = *stack;
		*stack = new;
	}
	return (1);
}
