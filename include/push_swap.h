/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:31:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/22 21:57:01 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

# define STDERR 2

/* typedef enum e_order
{
	desc,
	asc
}	t_order; */

typedef struct s_stacks
{
	t_list	*a;
	t_list	*b;
}	t_stacks;

typedef struct s_divide_info
{
	int		level;
	int		part;
	int		*arr;
	char	*order;
}	t_divide_info;

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

void			sort_stacks(t_stacks stacks);

t_stacks		init_stacks(void);
void			print_stacks(t_stacks stacks);
t_list			*set_stack_a(int argc, char **argv);
t_list			*set_stack_b(int size);
t_stacks		set_stacks(int argc, char **argv);

#endif
