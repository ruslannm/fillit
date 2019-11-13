/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_blank_line.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 13:55:51 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/13 14:53:09 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_link	*ft_create_blank_line(int len, t_stack **matrix_stk)
{
	int		i;
	t_link	*ptr;
	t_link	*next;

	if (!(ptr = (t_link *)malloc(sizeof(t_link))))
		return (NULL);
	ft_push(matrix_stk, ptr);
	ptr->left = ptr;
	ptr->right = ptr;
	ptr->root_side = ptr;
	i = 1;
	while (i < len)
	{
		if (!(next = (t_link *)malloc(sizeof(t_link))))
			return (NULL);
		ft_push(matrix_stk, next);
		next->left = ptr;
		next->right = ptr->right;
		ptr->right->left = next;
		ptr->right = next;
		next->root_side = ptr;
		i++;
	}
	return (ptr);
}
