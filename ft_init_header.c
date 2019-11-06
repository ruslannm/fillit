/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:46:44 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/06 17:52:37 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_link	*ft_init_header(int size, t_stack **matrix_stk)
{
	t_link			*root;
	t_link			*ptr;
	unsigned char	i;

	if ((!(root = ft_create_blank_line(size * size + 1, matrix_stk))) ||
			size > 15)
		return (NULL);
	ptr = root;
	i = 0;
	while (i < size * size)
	{
		ptr->letter = 0;
		ptr->bit = i;
		ptr->up = ptr;
		ptr->down = ptr;
		ptr->root_top = ptr;
		if (ptr->root_side == ptr)
			ptr->bit = size;
		else
			i++;
		ptr = ptr->right;
	}
	return (root);
}
