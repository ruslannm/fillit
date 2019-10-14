/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rgero <rgero@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 16:16:01 by rgero             #+#    #+#             */
/*   Updated: 2019/10/14 19:46:24 by rgero            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

typedef struct		s_link
{
	unsigned char	letter;
	unsigned char	bit;
	unsigned char	header;
	struct s_link	*left;	
	struct s_link	*right;	
	struct s_link	*up;	
	struct s_link	*down;
	struct s_link	*root;	
}					t_link;

/* можно изпользовать структуру из либф т*/
typedef struct		s_stack
{
	struct s_link	*link;
	struct s_stack	*next;
}					t_stack;


#endif