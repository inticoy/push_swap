/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:41:22 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/03 15:27:25 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "libft.h"

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
void			update_div_info(t_div_info *info);

void			raise_error(char *msg);

void			print_orders(t_order *orders, int len);
void			reverse_orders(t_order *orders, int len);
t_order			*set_orders(int part, int level);

int				max_idx_of_three(int a, int b, int c);
int				max_idx(int a, int b);
int				min_idx_of_three(int a, int b, int c);
int				min_idx(int a, int b);
int				power(int num, int exp);

void			merge_all_to_a(t_stacks *stacks, t_div_info info);
void			merge_all_to_b(t_stacks *stacks, t_div_info info);
void			merge_to_a(t_stacks *stacks, t_merge_info minfo);
void			merge_to_b(t_stacks *stacks, t_merge_info minfo);

void			pre_sort_two_nodes(t_stacks *stacks, t_order order);
void			pre_sort_three_nodes(t_stacks *stacks, t_order order);
void			pre_sort_four_nodes(t_stacks *stacks, t_order order);
void			pre_sort_five_nodes(t_stacks *stacks, t_order order);
void			pre_sort_six_nodes(t_stacks *stacks, t_order order);
void			pre_sort(t_stacks *stacks, t_div_info info);

void			sort_two_nodes(t_stacks *stacks, t_order order);
void			sort_three_nodes(t_stacks *stacks, t_order order);
void			sort_four_nodes(t_stacks *stacks, t_order order);
void			sort_five_nodes(t_stacks *stacks, t_order order);
void			sort_stacks(t_stacks *stacks, t_div_info *dinfo);

int				get_a_bot(t_stacks *stacks);
int				get_a_top(t_stacks *stacks);
int				get_b_top(t_stacks *stacks);
int				get_b_bot(t_stacks *stacks);
t_stacks		init_stacks(void);
t_bool			is_sorted(t_stacks *stacks);
void			print_stacks(t_stacks stacks);
t_list			*set_stack(int argc, char **argv);
t_stacks		set_stacks(int argc, char **argv);

int				arr_sum(int *elements, int len);

#endif