/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:29:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 13:58:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_sort_2(t_stacks *stacks, t_order order)
{
	int	x;
	int	y;

	x = *((int *)stacks->a->content);
	y = *((int *)stacks->a->next->content);
	if (order && x < y)
		swap_a(stacks, ft_true);
	else if (!order && x > y)
		swap_a(stacks, ft_true);
	repeat_cmd(push_b, stacks, 2);
}
