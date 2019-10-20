/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:15:31 by rgero             #+#    #+#             */
/*   Updated: 2019/10/20 13:38:04 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

<<<<<<< HEAD
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
=======
>>>>>>> c91a1f4518dd7d531a097213b4928144b156fa09

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
	while (list)
    {
		printf("%s\n", (char *)list->content);
	   	list = list->next;
	}
}

int main(int argc, char **argv)
{
	int fd;
	t_list	*income;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd > 0)
	{
		printf("qnt tetra=%d\n", ft_read(fd, &income));
		ft_lst_print(income);
	}
}