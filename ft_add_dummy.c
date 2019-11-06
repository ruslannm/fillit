/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_dummy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:28:05 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/06 17:15:33 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_add_dummy(t_link *root, unsigned char letter, t_stack **matrix_stk,
	char dummy)
{
	unsigned char	pt;
	unsigned char	len;
	t_link			*new;

	if (dummy == 'n')
		return (0);
	new = NULL;
	pt = 0;
	len = root->bit * root->bit;
	while (pt < len && letter * 4 < len)
	{
		if (!(new = ft_create_blank_line(2, matrix_stk)))
		{
			ft_free_matrix(root);
			return (-1);
		}
		new->letter = 27 + pt;
		new->bit = 99;
		new->right->letter = 27 + pt;
		new->right->bit = pt;
		ft_add_to_matrix(root, new);
		pt++;
	}
	return (0);
}
