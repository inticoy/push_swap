/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_6.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:23:35 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 21:06:04 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	need_swap_a(t_stacks *stacks, t_order order)
{
	const int	a1 = *(int *)stacks->a->content * order;
	const int	a2 = *(int *)stacks->a->next->content * order;

	if (a1 > a2)
		return (ft_true);
	else
		return (ft_false);
}

static t_bool	need_swap_b(t_stacks *stacks, t_order order)
{
	const int	b1 = *(int *)stacks->b->content * order;
	const int	b2 = *(int *)stacks->b->next->content * order;

	if (b1 > b2)
		return (ft_true);
	else
		return (ft_false);
}

void	pre_sort_6(t_stacks *stacks, t_order order)
{
	t_merge_info	minfo;
	int				idx;

	push_b(stacks, ft_true);
	push_b(stacks, ft_true);
	if (need_swap_b(stacks, order))
		swap_b(stacks, ft_true);
	rotate_b(stacks, ft_true);
	rotate_b(stacks, ft_true);
	if (need_swap_a(stacks, order))
		swap_a(stacks, ft_true);
	rotate_a(stacks, ft_true);
	rotate_a(stacks, ft_true);
	if (need_swap_a(stacks, -order))
		swap_a(stacks, ft_true);
	minfo.a = 2;
	minfo.b = 2;
	minfo.c = 2;
	minfo.order = order;
	merge_to_b(stacks, minfo);
}
