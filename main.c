/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:15:31 by rgero             #+#    #+#             */
/*   Updated: 2019/10/28 19:47:33 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

static int  ft_square_len(int nb)
{
	while (0 == ft_sqrt(nb))
		nb++;
	return (ft_sqrt(nb));
}

int	ft_summa_tetra(char *s)
{
	int i;
	int summa;

	i = 0;
	summa = 0;
	while (i < 16)
	{
		if (s[i] == '#')
		{
			if (i + 4 < 16)
				summa = summa + (s[i + 4] == '#' ? 1 : 0);
			if (i - 4 >= 0)
				summa = summa + (s[i - 4] == '#' ? 1 : 0);
			if (i + 1 < 4 * (i / 4) + 4)
				summa = summa + (s[i + 1] == '#' ? 1 : 0);
			if (i - 1 >= 4 * (i / 4))
				summa = summa + (s[i - 1] == '#' ? 1 : 0);
		}
		i++;
	}
	return (summa == 6 || summa == 8 ? 0 : -1);
}

int	ft_check_tetra(char *s, t_list **income)
{
	int	i;
	t_list	*new;

	i = 0;
	
	while (s[i] != '\0')
	{
		if (!(s[i] == '#' || s[i] == '.'))
			return (-1);
		i++;
	}
	if (ft_summa_tetra(s) == -1)
		return (-1);
	s = ft_move_tetra(s, 4 * 4);
	if (!(new = ft_lstnew(s, 17)))
		return (-1);
	ft_lstaddback(income, new);	
	return(0);
}

int ft_read(int fd, t_list **income)
{
	int 	i;
	char 	*str; 
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
		else if  (ft_strlen(str) != 0)
			err = -1;
		i++;
		free(str);
	}
	return (err == -1 ? err : (i + 1) / 5);
}

void	ft_lst_print(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (tmp)
    {
		printf("%s\n", (char *)tmp->content);
	   	tmp = tmp->next;
	}
}

int		ft_solution(t_list *income, int square_len)
{
	t_link	*root;
	int		ret;
	t_list	*solution;

	root = ft_fill_matrix(income, square_len);
	ft_print_matrix(root);

	//return (1);
	ret = ft_dancing_links(root, root->right->down, &solution);
	if (0 == ret)
		ret = ft_solution(income, square_len + 1);
	else
	{
		/* TODO convert t_list  to tab and print tab */
		printf("return solution =%d=\n", ret);
	}
	return (ret);
}

int main(int argc, char **argv)
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
			square_len = ft_square_len(qnt * 4);
			printf("qnt tetra=%d, square len =%d \n", qnt, square_len);
			ft_lst_print(income);
			ft_solution(income, square_len);
		}
		close(fd);
	}
	return (0);
}