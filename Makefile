# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 15:33:33 by gyoon             #+#    #+#              #
#    Updated: 2023/03/02 22:42:31 by gyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS_CMD		= $(addprefix cmd/,		push_a.c push_b.c repeat_cmd.c rev_rotate_a.c rev_rotate_ab.c rev_rotate_b.c rotate_a.c rotate_ab.c rotate_b.c swap_a.c swap_ab.c swap_b.c)
SRCS_DIV		= $(addprefix div/,		get_div_info.c update_div_info.c)
SRCS_ERROR		= $(addprefix error/,	raise_error.c)
SRCS_MATH		= $(addprefix math/,	power.c max_i.c min_i.c max_3.c min_3.c)
SRCS_MERGE		= $(addprefix merge/,	merge_all_to_a.c merge_all_to_b.c merge_to_a.c merge_to_b.c)
SRCS_ORDER		= $(addprefix order/,	print_orders.c reverse_orders.c set_orders.c)
SRCS_PRESORT	= $(addprefix presort/,	pre_sort.c pre_sort_five_nodes.c pre_sort_four_nodes.c pre_sort_six_nodes.c pre_sort_three_nodes.c pre_sort_two_nodes.c) 
SRCS_SORT		= $(addprefix sort/,	sort_five_nodes.c sort_four_nodes.c sort_stacks.c sort_three_nodes.c sort_two_nodes.c)
SRCS_STACK		= $(addprefix stack/,	get_a_bot.c get_a_top.c get_b_bot.c get_b_top.c init_stacks.c is_sorted.c print_stacks.c set_stack.c set_stacks.c)
SRCS_UTIL		= $(addprefix util/,	arr_sum.c)
SRCS_MAIN		= main.c
SRCS = $(addprefix src/, 	$(SRCS_CMD)		$(SRCS_DIV)		$(SRCS_ERROR)	\
							$(SRCS_MATH) 	$(SRCS_MERGE)	$(SRCS_ORDER)	\
							$(SRCS_PRESORT)	$(SRCS_SORT)	$(SRCS_STACK)	\
							$(SRCS_UTIL)	$(SRCS_MAIN))
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