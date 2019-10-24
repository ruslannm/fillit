/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_column.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 19:31:05 by rgero             #+#    #+#             */
/*   Updated: 2019/10/24 19:43:03 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/* 0 - not column (solution)
   1 - there are column (go ahead)
   -1 - there are empty column (go back, undo deletion)
*/ 

int ft_check_column(t_link *root)
{
    t_link  *tmp;
    int ret;

    ret = 0;
    tmp = root;
    while (tmp->right != root)
    {
        tmp = tmp->right;
        if (ft_count_row(tmp, "all") == 0)
            return (-1);
        else
            ret = 1;        
    }
    return (ret);
}