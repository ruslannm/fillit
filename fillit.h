/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:16:01 by rgero             #+#    #+#             */
/*   Updated: 2019/10/30 15:05:39 by fprovolo         ###   ########.fr       */
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

char	*ft_move_tetra(char *s, int len);
int		ft_dancing_links(t_link *root, t_link *row, t_list **solution);
int 	ft_sqrt(int nb);
void    ft_print_field(t_link *ptr, int size);
int     ft_check_fit(char *tet, int pt, int size);
t_link	*ft_create_blank_line(int len);
t_link	*ft_fill_matrix(t_list *income, int size);
t_link	*ft_init_header(int size);
t_link  *ft_add_tetra(t_link *root, char *tet, int pt, unsigned char letter);
void    ft_print_matrix(t_link *root);
void	ft_delete_dl(t_link *link, t_list **stack, char type);
void    ft_undo_move(t_list **stack_row, t_list **stack_top, t_list **solution);
void    ft_move_same_letter(t_link *row, t_list **stack);
void	ft_move_same_bits(t_link *row, t_list **stack_row, t_list **stack_top);

#endif