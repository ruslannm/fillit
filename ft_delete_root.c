/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_root.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:20:34 by rgero             #+#    #+#             */
/*   Updated: 2019/11/06 18:49:49 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_delete_link(t_stack **stack)
{
	t_stack	*tmp;
	t_link	*link;

	if (*stack == NULL)
		return ;
	else
	{
		tmp = *stack;
		link = tmp->link;
		free(link);
		*stack = (*stack)->next;
		free(tmp);
	}
}

void	ft_del_root(t_stack *solution, t_stack *root)
{
	ft_del_stack(solution);
	while (root)
		ft_delete_link(&root);
}
