/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:30:50 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 15:46:48 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	pre_sort_123(t_stacks *stacks)
{
	swap_a(stacks, ft_true);
	push_b(stacks, ft_true);
	swap_a(stacks, ft_true);
	push_b(stacks, ft_true);
	swap_b(stacks, ft_true);
	push_b(stacks, ft_true);
}

static void	pre_sort_132(t_stacks *stacks)
{
	push_b(stacks, ft_true);
	push_b(stacks, ft_true);
	swap_b(stacks, ft_true);
	push_b(stacks, ft_true);
	swap_b(stacks, ft_true);
}

static void	pre_sort_213(t_stacks *stacks)
{
	push_b(stacks, ft_true);
	swap_a(stacks, ft_true);
	push_b(stacks, ft_true);
	swap_b(stacks, ft_true);
	push_b(stacks, ft_true);
}

static void	pre_sort_231(t_stacks *stacks)
{
	push_b(stacks, ft_true);
	push_b(stacks, ft_true);
	swap_b(stacks, ft_true);
	push_b(stacks, ft_true);
}

void	pre_sort_3(t_stacks *stacks, t_order order)
{
	const int	a1 = *(int *)stacks->a->content * order;
	const int	a2 = *(int *)stacks->a->next->content * order;
	const int	a3 = *(int *)stacks->a->next->next->content * order;

	if (a1 < a2 && a2 < a3)
		pre_sort_123(stacks);
	else if (a1 < a2 && a2 > a3 && a1 < a3)
		pre_sort_132(stacks);
	else if (a1 > a2 && a2 < a3 && a1 < a3)
		pre_sort_213(stacks);
	else if (a1 < a2 && a2 > a3 && a1 > a3)
		pre_sort_231(stacks);
	else if (a1 > a2 && a2 < a3 && a1 > a3)
	{
		repeat_cmd(push_b, stacks, ft_true, 3);
		swap_b(stacks, ft_true);
	}
	else if (a1 > a2 && a2 > a3)
		repeat_cmd(push_b, stacks, ft_true, 3);
}
