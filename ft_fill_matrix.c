/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 17:08:23 by fprovolo          #+#    #+#             */
/*   Updated: 2019/11/06 18:19:36 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_check_fit(char *tet, int pt, int size)
{
	int i;

	i = 0;
	while (i < 16)
	{
		if (tet[i] == '#')
			if (pt % size + i % 4 >= size || pt / size + i / 4 >= size)
				return (0);
		i++;
	}
	return (1);
}

void	ft_add_to_matrix(t_link *root, t_link *line)
{
	line->up = root->up;
	line->down = root;
	line->root_top = root;
	root->up->down = line;
	root->up = line;
	line = line->right;
	root = root->right;
	while (line->root_side != line)
	{
		while (root->bit != line->bit)
			root = root->right;
		line->up = root->up;
		line->down = root;
		line->root_top = root;
		root->up->down = line;
		root->up = line;
		line = line->right;
	}
	return ;
}

void	ft_add_tetra(t_link *root, char *tet, int pt, t_link *new)
{
	int		i;
	t_link	*ptr;

	ptr = new->right;
	i = 0;
	while (i < 16)
	{
		if (tet[i] == '#')
		{
			ptr->bit = (unsigned char)(pt + i / 4 * root->bit + i % 4);
			ptr = ptr->right;
		}
		i++;
	}
	ft_add_to_matrix(root, new);
	return ;
}

t_link	*ft_create_tetra(t_link *root, char *tetra, unsigned char letter,
		t_stack **matrix_stk)
{
	int				pt;
	t_link			*new;
	t_link			*ptr;

	pt = 0;
	while (pt < root->bit * root->bit)
	{
		if (ft_check_fit(tetra, pt, root->bit))
		{
			if (!(new = ft_create_blank_line(5, matrix_stk)))
				return (NULL);
			new->letter = letter;
			new->bit = 99;
			ptr = new->right;
			while (ptr->root_side != ptr)
			{
				ptr->letter = letter;
				ptr = ptr->right;
			}
			ft_add_tetra(root, tetra, pt, new);
		}
		pt++;
	}
	return (new);
}

t_link	*ft_fill_matrix(t_list *income, int size, t_stack **matrix_stk,
		char dummy)
{
	t_link			*root;

	if (!(root = ft_init_header(size, matrix_stk)))
		return (NULL);
	while (income)
	{
		if (!(ft_create_tetra(root, (char *)income->content,
				root->up->letter + 1, matrix_stk)))
			return (NULL);
		income = income->next;
	}
	if (dummy == 'y')
		if (-1 == ft_add_dummy(root, matrix_stk))
			return (NULL);
	return (root);
}
