/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dancing_links.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:28:21 by rgero             #+#    #+#             */
/*   Updated: 2019/10/23 18:57:03 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int  ft_square(int nb)
{
	while (0 == ft_sqrt(nb))
		nb++;
	return (ft_sqrt(nb));
}

char    *ft_dancing_links(t_list *income, int qnt)
{
	t_list  *tmp;
	int     len;

	tmp = income;
	len = ft_square(qnt * 4);
	
	return("ok\n");
}

int		ft_count_row(t_link *header)
{
	t_link	*tmp;
	int		i;

	tmp = header;
	i = 0;
	while (tmp->down != header)
	{
		i++;
		tmp = tmp->down;
	}
	return (i);
}

t_link *ft_get_header_min(t_link *root)
{
	t_link	*tmp;
	t_link	*ret;
	int		amount_row;
	int		i;

	i = 0;
	ret = NULL;
	amount_row = ft_count_row(root);
	tmp = root;
	while ((tmp = tmp->right) != root)
	{
		i = ft_count_row(tmp);
		if (i < amount_row)
			ret = tmp;
	}
	return (ret);
}

void	ft_delete_row(t_link *link, t_list **stack)
{
	t_link *tmp;

	tmp = link;
	while (tmp != link)
	{
		tmp->down->up = tmp->up;
		tmp->up->down = tmp->down;
		tmp = tmp->right;
	}
	ft_push(*stack, link);
}

void	ft_restore_row(t_list **stack)
{
	t_link	*tmp;
	t_link	*new;
	
	new = ft_pop(*stack);
	tmp = new;
	while (tmp != new)
	{
		tmp->down->up = tmp;
		tmp->up->down = tmp;
		tmp = tmp->right;
	}
}