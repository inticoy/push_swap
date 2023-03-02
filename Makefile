# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 15:33:33 by gyoon             #+#    #+#              #
#    Updated: 2023/03/02 16:42:22 by gyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = $(addprefix src/, \
		cmd/push_a.c cmd/push_b.c \
		cmd/repeat_cmd.c \
		cmd/rev_rotate_a.c cmd/rev_rotate_ab.c cmd/rev_rotate_b.c\
		cmd/rotate_a.c cmd/rotate_ab.c cmd/rotate_b.c \
		cmd/swap_a.c cmd/swap_ab.c cmd/swap_b.c \
		div/get_div_info.c div/update_div_info.c \
		error/raise_error.c \
		math/power.c math/max_i.c math/min_i.c math/max_3.c math/min_3.c \
		order/print_orders.c order/reverse_orders.c order/set_order.c \
		sort/merge_all_to_a.c sort/merge_all_to_b.c sort/merge_to_a.c sort/merge_to_b.c \
		sort/pre_sort_2.c sort/pre_sort_3.c sort/pre_sort_4.c sort/pre_sort_5.c sort/pre_sort_6.c \
		sort/sort_2.c sort/sort_3.c sort/sort_4.c sort/sort_5.c \
		sort/preprocess.c sort/sort_stacks.c \
		stack/get_a_bot.c stack/get_a_top.c stack/get_b_bot.c stack/get_b_top.c \
		stack/init_stacks.c stack/print_stacks.c stack/set_stack.c stack/set_stacks.c \
		util/arr_sum.c \
		main.c)
SRCS_BONUS = $(addprefix src_bonus/, \
			main.c)

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