/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_two_nodes.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:29:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/02 22:38:06 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_sort_two_nodes(t_stacks *stacks, t_order order)
{
	const int	a1 = *(int *)stacks->a->content * order;
	const int	a2 = *(int *)stacks->a->next->content * order;

	if (a1 < a2)
		swap_a(stacks, ft_true);
	repeat_cmd(push_b, stacks, ft_true, 2);
}
