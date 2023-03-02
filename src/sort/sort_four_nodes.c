/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_nodes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:46:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/02 22:37:31 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_bool	need_swap_a(t_stacks *stacks)
{
	const int	a1 = *(int *)stacks->a->content;
	const int	a2 = *(int *)stacks->a->next->content;

	if (a1 > a2)
		return (ft_true);
	else
		return (ft_false);
}

static t_bool	need_swap_b(t_stacks *stacks)
{
	const int	b1 = *(int *)stacks->b->content;
	const int	b2 = *(int *)stacks->b->next->content;

	if (b1 < b2)
		return (ft_true);
	else
		return (ft_false);
}

void	sort_four_nodes(t_stacks *stacks, t_order order)
{
	t_merge_info	minfo;
	t_bool			sa;
	t_bool			sb;

	minfo.a = 0;
	minfo.b = 2;
	minfo.c = 2;
	minfo.order = order;
	repeat_cmd(push_b, stacks, ft_true, 2);
	sa = need_swap_a(stacks);
	sb = need_swap_b(stacks);
	if (sa && sb)
		swap_ab(stacks, ft_true);
	else if (sa)
		swap_a(stacks, ft_true);
	else if (sb)
		swap_b(stacks, ft_true);
	merge_to_a(stacks, minfo);
}
