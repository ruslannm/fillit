/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dancing_links.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 16:28:21 by rgero             #+#    #+#             */
/*   Updated: 2019/10/20 17:01:05 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int  ft_square(int nb)
{
    while (0 == ft_sqrt(nb))
        nb++;
    return (nb);
}

char    *ft_dancing_links(t_list *income, int qnt)
{
    t_list  *tmp;
    int     i;

    tmp = income;
    i = ft_square(qnt * 4);
    return("ok\n");
}