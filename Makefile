# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgeffroy <hgeffroy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 12:02:28 by hgeffroy          #+#    #+#              #
#    Updated: 2023/06/06 09:33:27 by hgeffroy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Variables

NAME = push_swap
FLAGS = -Wall -Werror -Wextra
CC = cc
RM = rm -f
OBJ_DIR = obj/
SRC_DIR = src/
LIBFT_DIR = libft/
LIBFT = libft.a
HEADER = header/push_swap.h

#Files

SRC_F = push_swap_op.c \
		push_swap_sort.c \
		push_swap_utils.c \
		push_swap_algo.c \
		push_swap_parsing.c \
		push_swap_lists.c \
		push_swap.c
		
OBJ = $(addprefix $(OBJ_DIR), $(SRC_F:.c=.o))

#Rules

all : lib $(NAME)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c $(LIBFT_DIR)$(LIBFT) $(HEADER) Makefile
	mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@ -I.

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT_DIR)$(LIBFT) -o $@ -I.

lib :
	make -C $(LIBFT_DIR)

clean :
	$(RM) -r $(OBJ_DIR) libft.a
	make fclean -C $(LIBFT_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : re fclean clean all