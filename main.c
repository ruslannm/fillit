/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:15:31 by rgero             #+#    #+#             */
/*   Updated: 2019/10/15 16:42:05 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/get_next_line.h"
#include <stdio.h>

int ft_read(int fd)
{
	int 	i;
	char 	*str; 
	char	*tet[17];
	int		err;

	i = 0;
	err = 0;
	while (get_next_line(fd, &str) == 1)
	{
		if (i % 4 == 0 && i > 0)
		{
			printf("tetra =%s=\n", tet);
			if (ft_strlen(str) != 0)
				err = 1;
		}
		else
		{
			if (ft_strlen(str) != 4)
				err = 1;
			else
				tet[i % 4] = ft_strcpy(&tet[i % 4], str);
			i++;
		}
		free(str);
	}
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