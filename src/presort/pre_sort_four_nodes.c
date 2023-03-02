/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_four_nodes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:32:31 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/02 22:38:42 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_sort_four_nodes(t_stacks *stacks, t_order order)
{
	t_merge_info	minfo;

	push_b(stacks, ft_true);
	rotate_b(stacks, ft_true);
	minfo.a = 1;
	minfo.b = 2;
	minfo.c = 1;
	minfo.order = order;
	if (minfo.order > 0)
	{
		if (*((int *)stacks->a->content) < *((int *)stacks->a->next->content))
			swap_a(stacks, ft_true);
		merge_to_b(stacks, minfo);
	}
	else
	{
		if (*((int *)stacks->a->content) > *((int *)stacks->a->next->content))
			swap_a(stacks, ft_true);
		merge_to_b(stacks, minfo);
	}
}
