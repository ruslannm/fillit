/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:15:31 by rgero             #+#    #+#             */
/*   Updated: 2019/10/17 17:04:55 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/get_next_line.h"
#include "libft/libft.h"
#include <stdio.h>

int ft_read(int fd)
{
	int 	i;
	char 	*str; 
	char	tet[17];
	int		err;

  	i = 0;   
	err = 0;
	while (get_next_line(fd, &str) == 1 && err == 0)
	{
		if (i % 5 == 4)
		{
			if  (ft_strlen(str) != 0)
				err = 1;
				i++;
		}
		else
		{
			if (ft_strlen(str) != 4)
				err = 1;
			else
				ft_strcpy(&tet[(i % 5) * 4], str);
			i++;
			if (i % 5 == 4)
				printf("tetra =%s=\n", tet);
		}
		free(str);
	}
	return (err);
}

int main(int argc, char **argv)
{
	int fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd > 0)
	{
		ft_read(fd);
	}
}