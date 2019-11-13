/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_dummy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:28:05 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/13 14:53:09 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_add_dummy(t_link *root, t_stack **matrix_stk)
{
	unsigned char	pt;
	unsigned char	len;
	unsigned char	letter;
	t_link			*new;

	pt = 0;
	len = root->bit * root->bit;
	letter = root->up->letter;
	while (pt < len && letter * 4 < len)
	{
		if (!(new = ft_create_blank_line(2, matrix_stk)))
			return (-1);
		new->letter = 27 + pt;
		new->bit = 99;
		new->right->letter = 27 + pt;
		new->right->bit = pt;
		ft_add_to_matrix(root, new);
		pt++;
	}
	return (0);
}
