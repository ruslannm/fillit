/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:16:01 by rgero             #+#    #+#             */
/*   Updated: 2019/10/23 19:46:04 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include "libft/get_next_line.h"
#include "libft/libft.h"

typedef struct		s_link
{
	unsigned char	letter;
	unsigned char	bit;
	unsigned char	header;  //qnt row
	struct s_link	*left;	
	struct s_link	*right;	
	struct s_link	*up;	
	struct s_link	*down;
	struct s_link	*root;	
}					t_link;

/* можно изпользовать структуру из либф т*/
typedef struct		s_tetra
{
	char			name;
	struct s_tetra	*left;
	struct s_tetra	*right;
	struct s_tetra	*up;
	struct s_tetra	*down;
}					t_tetra;

char	*ft_move_tetra(char *s, int len);
char    *ft_dancing_links(t_list *income, int qnt);
int 	ft_sqrt(int nb);
void	ft_push(t_list **stack, t_link *link);
t_link	*ft_pop(t_list **stack);

#endif