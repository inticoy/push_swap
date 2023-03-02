# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 15:33:33 by gyoon             #+#    #+#              #
#    Updated: 2023/03/02 19:23:46 by gyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS_CMD	= $(addprefix cmd/,		push_a.c push_b.c repeat_cmd.c rev_rotate_a.c rev_rotate_ab.c rev_rotate_b.c rotate_a.c rotate_ab.c rotate_b.c swap_a.c swap_ab.c swap_b.c)
SRCS_DIV	= $(addprefix div/,		get_div_info.c update_div_info.c)
SRCS_ERROR	= $(addprefix error/,	raise_error.c)
SRCS_MATH	= $(addprefix math/,	power.c max_i.c min_i.c max_3.c min_3.c)
SRCS_ORDER	= $(addprefix order/,	print_orders.c reverse_orders.c set_orders.c)
SRCS_SORT	= $(addprefix sort/,	merge_all_to_a.c merge_all_to_b.c merge_to_a.c merge_to_b.c pre_sort_2.c pre_sort_3.c pre_sort_4.c pre_sort_5.c pre_sort_6.c preprocess.c sort_2.c sort_3.c sort_4.c sort_5.c sort_stacks.c)
SRCS_STACK	= $(addprefix stack/,	get_a_bot.c get_a_top.c get_b_bot.c get_b_top.c init_stacks.c is_sorted.c print_stacks.c set_stack.c set_stacks.c)
SRCS_UTIL	= $(addprefix util/,	arr_sum.c)
SRCS_MAIN	= main.c
SRCS = $(addprefix src/, $(SRCS_CMD) $(SRCS_DIV) $(SRCS_ERROR) $(SRCS_MATH) $(SRCS_ORDER) $(SRCS_SORT) $(SRCS_STACK) $(SRCS_UTIL) $(SRCS_MAIN))
SRCS_BONUS = $(addprefix src_bonus/, main.c)

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

ifdef BONUS
    F_OBJS = $(OBJS_BONUS)
else
    F_OBJS = $(OBJS)
endif

INCLUDE = ./include
LIBFT = libft/libft.a

all : $(NAME)

$(NAME) : $(LIBFT) $(F_OBJS)
	$(CC) $(CFLAGS) -L./libft $(SRCS) -lft -I $(INCLUDE) -o $@

bonus :
	make BONUS=1 all

$(LIBFT) :
	make -C libft

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

clean :
	$(RM) $(OBJS)
	$(RM) $(B_OBJS)
	make -C libft clean

fclean :
	make clean
	$(RM) $(NAME)
	make -C libft fclean

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re