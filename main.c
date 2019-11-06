/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:15:31 by rgero             #+#    #+#             */
/*   Updated: 2019/11/06 15:34:24 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_square_len(int nb, t_list *income)
{
	int		ret;

	while (!(ret = ft_sqrt(nb)))
		nb++;
	if (ret < 4)
		while (income)
		{
			if (ft_size_tetra((char *)income->content) > ret)
				ret = ft_size_tetra((char *)income->content);
			income = income->next;
		}
	return (ret);
}

int			ft_read(int fd, t_list **income)
{
	int		i;
	char	*str;
	char	tet[17];
	int		err;

	i = 0;
	err = 0;
	while (get_next_line(fd, &str) == 1 && err == 0)
	{
		if (i % 5 != 4)
		{
			if (ft_strlen(str) != 4)
				err = -1;
			else
				ft_strcpy(&tet[(i % 5) * 4], str);
			if ((i + 1) % 5 == 4)
				err = ft_check_tetra(tet, income);
		}
		else if (ft_strlen(str) != 0)
			err = -1;
		i++;
		free(str);
	}
	return (err == -1 || (i + 1) % 5 != 0 ? -1 : (i + 1) / 5);
}

void		ft_put_solution(t_stack *solution, int square_len)
{
	char	*ret;
	t_stack	*tmp;
	t_link	*link;
	int		i;

	if (!(ret = ft_strnew_char(square_len * square_len, '.')))
		return ;
	tmp = solution;
	while (tmp)
	{
		link = (tmp->link)->right;
		while (link != link->root_side)
		{
			if (link->letter < 27)
				ret[link->bit] = link->letter + 64;
			link = link->right;
		}
		tmp = tmp->next;
	}
	i = 0;
	while (i < square_len)
	{
		write(1, &ret[(i++) * square_len], square_len);
		write(1, "\n", 1);
	}
}

int			ft_solution(t_list *income, int square_len, int qnt)
{
	t_link	*root;
	int		ret;
	t_stack	*solution;
	t_stack	*matrix_stk;

	matrix_stk = NULL;
	root = ft_fill_matrix(income, square_len, &matrix_stk, 'y');
	solution = NULL;
	ret = ft_dancing_links_fast(root, ft_row_for_seach_fast(root), &solution,
								qnt);
	ft_del_stack(solution);
	solution = NULL;
	if (ret)
	{
		root = ft_fill_matrix(income, square_len, &matrix_stk, 'n');
		ret = ft_dancing_links(root, ft_row_for_seach(root), &solution, qnt);
		ft_put_solution(solution, square_len);
	}
	else
		ret = ft_solution(income, square_len + 1, qnt);
	ft_del_stack(solution);
	return (ret);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		qnt;
	int		square_len;
	t_list	*income;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd > 0)
	{
		qnt = ft_read(fd, &income);
		if (qnt < 0)
			ft_putstr("error\n");
		else
		{
			square_len = ft_square_len(qnt * 4, income);
			ft_solution(income, square_len, qnt);
		}
		close(fd);
	}
	return (0);
}
