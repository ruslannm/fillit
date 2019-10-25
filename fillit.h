/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:16:01 by rgero             #+#    #+#             */
/*   Updated: 2019/10/25 18:02:21 by fprovolo         ###   ########.fr       */
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
	struct s_link	*root_top;
	struct s_link	*root_side;
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
void    ft_print_field(t_link *ptr, int size);
int     ft_check_fit(char *tet, int pt, int size);
t_link	*ft_create_blank_line(int len);
void	ft_push(t_list **stack, t_link *link);
t_link	*ft_pop(t_list **stack);
t_link	*ft_fill_matrix(t_list *income, int size);
t_link	*ft_init_header(int size);
t_link  *ft_add_tetra(t_link *root, char *tet, int pt, unsigned char letter);
void    ft_print_matrix(t_link *root);

#endif