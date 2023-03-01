/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 18:53:05 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define STDERR 2

typedef enum e_order
{
	desc = -1,
	asc = 1
}	t_order;

typedef struct s_stacks
{
	int		num;
	t_list	*a;
	t_list	*b;
}	t_stacks;

typedef struct s_div_info
{
	int		level;
	int		part;
	int		*elements;
	t_order	*orders;
}	t_div_info;

typedef struct s_merge_info
{
	int		a;
	int		b;
	int		c;
	t_order	order;
}	t_merge_info;

void			push_a(t_stacks *stacks, t_bool opt);
void			push_b(t_stacks *stacks, t_bool opt);
void			repeat_cmd(	void (*f)(t_stacks *, t_bool), \
							t_stacks *s, t_bool opt, int n);
void			rev_rotate_a(t_stacks *stacks, t_bool opt);
void			rev_rotate_ab(t_stacks *stacks, t_bool opt);
void			rev_rotate_b(t_stacks *stacks, t_bool opt);
void			rotate_a(t_stacks *stacks, t_bool opt);
void			rotate_ab(t_stacks *stacks, t_bool opt);
void			rotate_b(t_stacks *stacks, t_bool opt);
void			swap_a(t_stacks *stacks, t_bool opt);
void			swap_b(t_stacks *stacks, t_bool opt);
void			swap_ab(t_stacks *stacks, t_bool opt);

t_div_info		get_div_info(int size);
t_div_info		update_div_info(t_div_info old);

void			raise_error(char *msg);

void			print_orders(t_order *orders, int len);
void			reverse_orders(t_order *orders, int len);
t_order			*set_order(int part, int level);

void			merge_all_to_a(t_stacks *stacks, t_div_info info);
void			merge_all_to_b(t_stacks *stacks, t_div_info info);
void			merge_to_a(t_stacks *stacks, t_merge_info minfo);
void			merge_to_b(t_stacks *stacks, t_merge_info minfo);
void			pre_sort_2(t_stacks *stacks, t_order order);
void			pre_sort_3(t_stacks *stacks, t_order order);
void			pre_sort_4(t_stacks *stacks, t_order order);
//void			pre_sort_5(t_stacks *stacks, t_order order);
void			preprocess(t_stacks *stacks, t_div_info info);
void			sort_stacks(t_stacks *stacks);

int				get_a_top(t_stacks *stacks);
int				get_b_top(t_stacks *stacks);
int				get_a_bottom(t_stacks *stacks);
int				get_b_bottom(t_stacks *stacks);
t_stacks		init_stacks(void);
void			print_stacks(t_stacks stacks);
t_list			*set_stack_a(int argc, char **argv);
t_list			*set_stack_b(int size);
t_stacks		set_stacks(int argc, char **argv);

int				arr_sum(int *elements, int len);

#endif
