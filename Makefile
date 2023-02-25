# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/19 15:33:33 by gyoon             #+#    #+#              #
#    Updated: 2023/02/25 18:45:39 by gyoon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
RM = rm -rf

# CFLAGS = -Wall -Wextra -Werror

SRCS = $(addprefix src/, \
		command/push_a.c command/push_b.c \
		command/rev_rotate_a.c command/rev_rotate_ab.c command/rev_rotate_b.c\
		command/rotate_a.c command/rotate_ab.c command/rotate_b.c \
		command/swap_a.c command/swap_ab.c command/swap_b.c \
		division/get_div_info.c division/update_div_info.c \
		error/raise_error.c \
		math/power.c math/max_i.c math/min_i.c\
		order/print_orders.c order/set_order.c \
		sort/sort_stacks.c \
		stack/get_a_bottom.c stack/get_a_top.c stack/get_b_bottom.c stack/get_b_top.c \
		stack/init_stacks.c stack/print_stacks.c stack/set_stack_a.c stack/set_stacks.c \
		main.c)
OBJS = $(SRCS:.c=.o)

B_SRCS = ${SRCS:.c=_bonus.c}
B_OBJS = ${OBJS:.o=_bonus.o}

LIBFT = libft/libft.a

INCLUDE = ./include

ifdef BONUS
    F_OBJS = $(B_OBJS)
else
    F_OBJS = $(OBJS)
endif

all : $(NAME)

$(NAME) : $(LIBFT) $(F_OBJS)
	$(CC) -L./libft $(SRCS) -lft -I $(INCLUDE) -o $@ -fsanitize=address

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