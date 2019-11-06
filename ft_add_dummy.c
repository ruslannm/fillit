/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_dummy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:28:05 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/06 16:49:07 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_link	*ft_add_dummy(t_link *root, unsigned char letter, t_stack **matrix_stk)
{
	unsigned char	pt;
	unsigned char	len;
	t_link			*new;

	new = NULL;
	pt = 0;
	len = root->bit * root->bit;
	while (pt < len && letter * 4 < len)
	{
		if (!(new = ft_create_blank_line(2, matrix_stk)))
		{
			ft_free_matrix(root);
			return (NULL);
		}
		new->letter = 27 + pt;
		new->bit = 99;
		new->right->letter = 27 + pt;
		new->right->bit = pt;
		ft_add_to_matrix(root, new);
		pt++;
	}
	return (new);
}
