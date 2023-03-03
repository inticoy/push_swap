# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 15:33:33 by gyoon             #+#    #+#              #
#    Updated: 2023/03/03 15:32:10 by gyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS_CMD		= $(addprefix cmd/,		push_a.c push_b.c repeat_cmd.c rev_rotate_a.c rev_rotate_ab.c rev_rotate_b.c rotate_a.c rotate_ab.c rotate_b.c swap_a.c swap_ab.c swap_b.c)
SRCS_DIV		= $(addprefix div/,		get_div_info.c update_div_info.c)
SRCS_ERROR		= $(addprefix error/,	raise_error.c)
SRCS_MATH		= $(addprefix math/,	max_idx.c max_idx_of_three.c min_idx.c min_idx_of_three.c power.c)
SRCS_MERGE		= $(addprefix merge/,	merge_all_to_a.c merge_all_to_b.c merge_to_a.c merge_to_b.c)
SRCS_ORDER		= $(addprefix order/,	print_orders.c reverse_orders.c set_orders.c)
SRCS_PRESORT	= $(addprefix presort/,	pre_sort.c pre_sort_five_nodes.c pre_sort_four_nodes.c pre_sort_six_nodes.c pre_sort_three_nodes.c pre_sort_two_nodes.c) 
SRCS_SORT		= $(addprefix sort/,	sort_five_nodes.c sort_four_nodes.c sort_stacks.c sort_three_nodes.c sort_two_nodes.c)
SRCS_STACK		= $(addprefix stack/,	get_a_bot.c get_a_top.c get_b_bot.c get_b_top.c init_stacks.c is_sorted.c print_stacks.c set_stack.c set_stacks.c)
SRCS_UTIL		= $(addprefix util/,	arr_sum.c)
SRCS_MAIN		= main.c
SRCS 			= $(addprefix src/, 	$(SRCS_CMD)		\
										$(SRCS_DIV)		\
										$(SRCS_ERROR)	\
										$(SRCS_MATH) 	\
										$(SRCS_MERGE)	\
										$(SRCS_ORDER)	\
										$(SRCS_PRESORT)	\
										$(SRCS_SORT)	\
										$(SRCS_STACK)	\
										$(SRCS_UTIL)	\
										$(SRCS_MAIN))

SRCS_CMD_BONUS		= $(SRCS_CMD:.c=_bonus.c)
SRCS_DIV_BONUS		= $(SRCS_DIV:.c=_bonus.c)
SRCS_ERROR_BONUS	= $(SRCS_ERROR:.c=_bonus.c)
SRCS_MATH_BONUS		= $(SRCS_MATH:.c=_bonus.c)
SRCS_MERGE_BONUS	= $(SRCS_MERGE:.c=_bonus.c)
SRCS_ORDER_BONUS	= $(SRCS_ORDER:.c=_bonus.c)
SRCS_PRESORT_BONUS	= $(SRCS_PRESORT:.c=_bonus.c)
SRCS_SORT_BONUS		= $(SRCS_SORT:.c=_bonus.c)
SRCS_STACK_BONUS	= $(SRCS_STACK:.c=_bonus.c)
SRCS_UTIL_BONUS		= $(SRCS_UTIL:.c=_bonus.c)
SRCS_MAIN_BONUS		= $(SRCS_MAIN:.c=_bonus.c)
SRCS_BONUS 			= $(addprefix src_bonus/, 	$(SRCS_CMD_BONUS)		\
												$(SRCS_DIV_BONUS)		\
												$(SRCS_ERROR_BONUS)		\
												$(SRCS_MATH_BONUS) 		\
												$(SRCS_MERGE_BONUS)		\
												$(SRCS_ORDER_BONUS)		\
												$(SRCS_PRESORT_BONUS)	\
												$(SRCS_SORT_BONUS)		\
												$(SRCS_STACK_BONUS)		\
												$(SRCS_UTIL_BONUS)		\
												$(SRCS_MAIN_BONUS))

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

INCLUDE = ./include
LIBFT = libft/libft.a

all : $(NAME)

bonus : $(NAME_BONUS)

$(NAME)	: $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -L./libft $(OBJS) -lft -I $(INCLUDE) -o $@

$(NAME_BONUS) : $(LIBFT) $(OBJS_BONUS)
	$(CC) $(CFLAGS) -L./libft $(OBJS_BONUS) -lft -I $(INCLUDE) -o $@

$(LIBFT) :
	make -C libft

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDE)

clean :
	$(RM) $(OBJS)
	$(RM) $(OBJS_BONUS)
	make -C libft clean

fclean :
	make clean
	$(RM) $(NAME)
	$(RM) $(NAME_BONUS)
	make -C libft fclean

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re