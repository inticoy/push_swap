/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/21 16:28:16 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
}	t_stacks;

typedef struct s_stack_data
{
	int	number;
}	t_stack_data;

void			push_a(t_stacks *stacks);
void			push_b(t_stacks *stacks);
void			rev_rotate_a(t_stacks *stacks);
void			rev_rotate_ab(t_stacks *stacks);
void			rev_rotate_b(t_stacks *stacks);
void			rotate_a(t_stacks *stacks);
void			rotate_ab(t_stacks *stacks);
void			rotate_b(t_stacks *stacks);
void			swap_a(t_stacks *stacks);
void			swap_b(t_stacks *stacks);
void			swap_ab(t_stacks *stacks);

void			raise_error(char *msg);

t_stacks		init_stacks(void);
t_stack_data	*new_stack_data(void);
void			print_stacks(t_stacks stacks);
t_list			*set_stack_a(int argc, char **argv);
t_list			*set_stack_b(int size);
t_stacks		set_stacks(int argc, char **argv);

#endif
