/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two_nodes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:40:48 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/02 22:37:29 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two_nodes(t_stacks *stacks, t_order order)
{
	const int	a1 = *(int *)stacks->a->content * order;
	const int	a2 = *(int *)stacks->a->next->content * order;

	if (a1 > a2)
		swap_a(stacks, ft_true);
}
