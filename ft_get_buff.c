/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_buff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:46:27 by rgero             #+#    #+#             */
/*   Updated: 2019/11/12 15:22:37 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_get_buff(int fd, char **line)
{
	ssize_t	buff_bytes;
	char	buff[BUFF_SIZE];
	int		ret;

	ret = 0;
	buff_bytes = read(fd, buff, BUFF_SIZE);
	if (buff_bytes < 20 || buff_bytes > 545)
		ret = -1;
	else if (buff[buff_bytes - 1] != '\n')
		ret = -1;
	else
	{
		buff[buff_bytes] = '\0';
		if (!(*line = strdup(buff)))
			ret = -1;
	}
	return (ret);

}