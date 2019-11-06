/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fprovolo <fprovolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:16:01 by rgero             #+#    #+#             */
/*   Updated: 2019/11/06 17:20:34 by fprovolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

#include <stdio.h>
#include "libft/get_next_line.h"
#include "libft/libft.h"

typedef struct		s_link
{
	unsigned char	letter;
	unsigned char	bit;
	struct s_link	*left;	
	struct s_link	*right;	
	struct s_link	*up;	
	struct s_link	*down;
	struct s_link	*root_top;
	struct s_link	*root_side;
}					t_link;

typedef struct		s_stack
{
	struct s_link	*link;
	struct s_stack	*next;
}					t_stack;

char	*ft_move_tetra(char *s, int len);
int		ft_check_tetra(char *s, t_list **income);
char	*ft_strnew_char(size_t size, char c);
int		ft_dancing_links(t_link *root, t_stack *stack_row, t_stack **solution, int qnt, int deep);
int		ft_dancing_links_fast(t_link *root, t_stack *stack_row, t_stack **solution,
		int qnt, int deep);
int 	ft_sqrt(int nb);
void    ft_print_field(t_link *ptr, int size);
int     ft_check_fit(char *tet, int pt, int size);
t_link	*ft_create_blank_line(int len, t_stack **matrix_stk);
void	ft_free_line(t_link *line);
void	ft_free_matrix(t_link *root);
t_link	*ft_fill_matrix(t_list *income, int size, t_stack **matrix_stk, char dummy);
t_link	*ft_init_header(int size, t_stack **matrix_stk);
void	ft_add_to_matrix(t_link *root, t_link *line);
void	ft_add_tetra(t_link *root, char *tet, int pt, t_link *new);
t_link	*ft_add_dummy(t_link *root, t_stack **matrix_stk);
void    ft_print_matrix(t_link *root);
void	ft_delete_dl(t_link *link, t_stack **stack, char type);
void    ft_undo_move(t_stack **stack_row, t_stack **stack_top, t_stack **solution);
void    ft_move_same_letter(t_link *row, t_stack **stack);
void	ft_move_same_bits(t_link *row, t_stack **stack_row, t_stack **stack_top);
int		ft_push(t_stack **stack, t_link *link);
t_link	*ft_pop(t_stack **stack);
void	ft_del_stack(t_stack *stack);
t_stack	*ft_row_for_seach(t_link *root);
t_stack	*ft_row_for_seach_fast(t_link *root);
int     ft_size_tetra(char *tetra);

#endif