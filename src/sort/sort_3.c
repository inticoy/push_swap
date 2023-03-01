/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:10:27 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 19:40:42 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stacks *stacks, t_order order)
{
	const int	a1 = *(int *)stacks->a->content * order;
	const int	a2 = *(int *)stacks->a->next->content * order;
	const int	a3 = *(int *)stacks->a->next->next->content * order;

	if (a1 < a2 && a2 < a3)
		return ;
	else if (a1 < a2 && a2 > a3 && a1 < a3)
	{
		rev_rotate_a(stacks, ft_true);
		swap_a(stacks, ft_true);
	}
	else if (a1 > a2 && a2 < a3 && a1 < a3)
		swap_a(stacks, ft_true);
	else if (a1 < a2 && a2 > a3 && a1 > a3)
		rev_rotate_a(stacks, ft_true);
	else if (a1 > a2 && a2 < a3 && a1 > a3)
		rotate_a(stacks, ft_true);
	else if (a1 > a2 && a2 > a3)
	{
		rotate_a(stacks, ft_true);
		swap_a(stacks, ft_true);
	}
}
