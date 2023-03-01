/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:30:50 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 13:31:12 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_sort_3(t_stacks *stacks, t_order order)
{
	const int	a1 = *(int *)stacks->a->content * (order ? 1 : -1);
	const int	a2 = *(int *)stacks->a->next->content * (order ? 1 : -1);
	const int	a3 = *(int *)stacks->a->next->next->content * (order ? 1 : -1);

	if (a1 > a2 && a2 > a3)					//3 2 1
	{
		push_b(stacks);
		push_b(stacks);
		push_b(stacks);
	}
	else if (a1 > a2 && a2 < a3 && a1 > a3)	//3 1 2
	{
		push_b(stacks);
		push_b(stacks);
		push_b(stacks);
		swap_b(stacks);
	}
	else if (a1 > a2 && a2 < a3 && a1 < a3)	//2 1 3
	{
		push_b(stacks);
		swap_a(stacks);
		push_b(stacks);
		swap_b(stacks);
		push_b(stacks);
	}
	else if (a1 < a2 && a2 > a3 && a1 > a3)	//2 3 1
	{
		push_b(stacks);
		push_b(stacks);
		swap_b(stacks);
		push_b(stacks);
	}
	else if (a1 < a2 && a2 > a3 && a1 < a3)	//1 3 2
	{
		push_b(stacks);
		push_b(stacks);
		swap_b(stacks);
		push_b(stacks);
		swap_b(stacks);
	}
	else if (a1 < a2 && a2 < a3)			//1 2 3
	{
		swap_a(stacks);
		push_b(stacks);
		swap_a(stacks);
		push_b(stacks);
		swap_b(stacks);
		push_b(stacks);
	}
}
