/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:12:44 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 21:30:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	need_swap_b(t_stacks *stacks)
{
	const int	b1 = *(int *)stacks->b->content;
	const int	b2 = *(int *)stacks->b->next->content;

	if (b1 < b2)
		return (ft_true);
	else
		return (ft_false);
}

void	sort_five_nodes(t_stacks *stacks, t_order order)
{
	t_merge_info	minfo;

	minfo.a = 0;
	minfo.b = 2;
	minfo.c = 3;
	minfo.order = order;
	repeat_cmd(push_b, stacks, ft_true, 2);
	sort_three_nodes(stacks, asc);
	if (need_swap_b(stacks))
		swap_b(stacks, ft_true);
	merge_to_a(stacks, minfo);
}
