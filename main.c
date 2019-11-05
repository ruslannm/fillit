/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:15:31 by rgero             #+#    #+#             */
/*   Updated: 2019/11/05 19:09:32 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	ft_square_len(int nb, t_list *income)
{
	t_list	*ptr;
	int		ret;
	
	while (!(ret = ft_sqrt(nb)))
		nb++;
	while (income)
	{
		ptr = (char *)income->content;
		
		
		i = 0;
		while (i < 16)
		{

			i++;
		}
		income = income->next;
	}
	return (ft_sqrt(nb));
}

/*
static int	ft_square_len(int nb)
{
	while (0 == ft_sqrt(nb))
		nb++;
	return (ft_sqrt(nb));
}
*/

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
	//square_len = 7;
	root = ft_fill_matrix(income, square_len, &matrix_stk, 'y');
	solution = NULL;
//	ft_print_matrix(root);
	ft_putstr("fast start\n");
	ret = ft_dancing_links_fast(root, ft_row_for_seach_fast(root), &solution, qnt, 0);
	ft_del_stack(solution);
	solution = NULL;
	ft_putstr("fast end\n");
	if (ret)
	{
		root = ft_fill_matrix(income, square_len, &matrix_stk, 'n');
//		ft_print_matrix(root);
		ft_putstr("right start\n");
		ret = ft_dancing_links(root, ft_row_for_seach(root), &solution, qnt, 0);
		ft_putstr("right end\n");
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
