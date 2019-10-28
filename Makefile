# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgero <rgero@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 15:46:56 by rgero             #+#    #+#              #
#    Updated: 2019/10/28 19:39:05 by rgero            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

SRC_PATH = ./
SRC_NAME = main.c ft_move_tetra.c ft_sqrt.c ft_place_tetra.c \
	ft_dancing_links.c	ft_stack_pop.c ft_stack_push.c \
	ft_move_same_bits.c ft_move_same_letter.c

OBJ_PATH = ./
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INC_PATH = ./
INC = $(addprefix -I, $(INC_PATH))

LIB_PATH = libft/
LIB_NAME = libft.a

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_NAME)
	$(CC) -o a.out  $(OBJ_NAME) -L $(LIB_PATH) -lft

%.o: %.c
	$(CC) $(CFLAGS) -o $@  -c $<

$(LIB_NAME):
	make -C $(LIB_PATH) fclean && make -C $(LIB_PATH)

clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all
