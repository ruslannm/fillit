/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_dummy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 14:28:05 by fprovolo          #+#    #+#             */
/*   Updated: 2019/10/31 14:28:19 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_link  *ft_add_dummy(t_link *root, unsigned char letter)
{
    unsigned char   pt;
    unsigned char   len;
    t_link          *new;

    pt = 0;
    len = root->bit * root->bit;
    while (pt < len && letter * 4 < len)
    {
        if (!(new = ft_create_blank_line(2)))
        {
            ft_free_matrix(root);
            return (NULL);
        }
        new->letter = 27 + pt;
        new->bit = 99;
        new->right->letter = 27 + pt;
        new->right->bit = pt;
        ft_add_to_matrix(root, new);
        pt++;
    }
    return (new);
}