/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:15:31 by rgero             #+#    #+#             */
/*   Updated: 2019/11/12 16:55:09 by rgero            ###   ########.fr       */
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

int			ft_read(int fd, t_list **income, char *str, int i)
{
	int		err;
	char	tet[17];
	char	*tmp;
	char	*buff_pos;

	err = ft_get_buff(fd, &str);
	if (!err)
	{
		tmp = str;
		while ((buff_pos = ft_strchr(tmp, '\n')) && !err)
		{
			if (++i % 5 != 4)
			{
				err = ft_check_tetra_line(buff_pos, tmp, &tet[(i % 5) * 4]);
				if ((i + 1) % 5 == 4)
					err = ft_check_tetra(tet, income);
			}
			else if (buff_pos != tmp)
				err = -1;
			tmp = buff_pos + 1;
		}
		free(str);
	}
	return (err == -1 || (i + 2) % 5 != 0 ? -1 : (i + 2) / 5);
}

void		ft_put_solution(t_stack *solution, int square_len)
{
	char	*ret;
	t_link	*link;
	int		i;

	if (!(ret = ft_strnew_char(square_len * square_len, '.')))
		return ;
	while (solution)
	{
		link = (solution->link)->right;
		while (link != link->root_side)
		{
			if (link->letter < 27)
				ret[link->bit] = link->letter + 64;
			link = link->right;
		}
		solution = solution->next;
	}
	i = 0;
	while (i < square_len)
	{
		write(1, &ret[(i++) * square_len], square_len);
		write(1, "\n", 1);
	}
	free(ret);
}

int			ft_solution(t_list *income, int square_len, int qnt)
{
	t_link	*root;
	int		ret;
	t_stack	*solution;
	t_stack	*matrix_stk;

	ft_init_stack(&solution, &matrix_stk);
	ret = -1;
	if ((root = ft_fill_matrix(income, square_len, &matrix_stk, 'y')))
		ret = ft_dancing_links_fast(root, ft_row_for_seach_fast(root),
									&solution, qnt);
	ft_del_root(solution, matrix_stk);
	ft_init_stack(&solution, &matrix_stk);
	if (ret)
	{
		if ((root = ft_fill_matrix(income, square_len, &matrix_stk, 'n')))
			ret = ft_dancing_links(root, ft_row_for_seach(root), &solution,
									qnt);
		ft_put_solution(solution, square_len);
	}
	else if (!ret)
		ret = ft_solution(income, square_len + 1, qnt);
	ft_del_root(solution, matrix_stk);
	return (ret);
}

int			main(int argc, char **argv)
{
	int		fd;
	int		qnt;
	t_list	*income;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		income = NULL;
		if (fd > 0)
		{
			qnt = ft_read(fd, &income, NULL, -1);
			if (qnt < 0 || qnt > 26)
				ft_putstr("error\n");
			else
			{
				ft_solution(income, ft_square_len(qnt * 4, income), qnt);
				ft_lstdel(&income, &ft_del);
			}
			close(fd);
		}
	}
	else
		ft_putstr("usage: ./fillit tetriminos_file\n");
	return (0);
}
