/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 17:00:59 by rgero             #+#    #+#             */
/*   Updated: 2019/11/04 17:05:33 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fillit.h"

char	*ft_strnew_char(size_t size, char c)
{
	char	*ret;

	if (!(ret = (char *)malloc(size + 1)))
		return (NULL);
	ft_memset(ret, c, size + 1);
	return (ret);
}