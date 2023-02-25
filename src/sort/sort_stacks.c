/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:54:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/25 14:57:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	pre_sort(t_stacks *stacks, t_order order)
{
	int	x;
	int	y;

	x = *((int *)stacks->a->content);
	y = *((int *)stacks->a->next->content);
	if (order)
	{
		if (x > y)
		{
			swap_a(stacks);
			push_b(stacks);
			push_b(stacks);
		}
		else
		{
			push_b(stacks);
			push_b(stacks);
		}
	}
	else
	{
		if (x > y)
		{
			push_b(stacks);
			push_b(stacks);
		}
		else
		{
			swap_a(stacks);
			push_b(stacks);
			push_b(stacks);
		}
	}

}

static void	preprocess(t_stacks *stacks, t_div_info info)
{
	int	i;

	i = 0;
	while (i < info.part)
	{
		pre_sort(stacks, info.orders[i]);
		i++;
	}
	// only when 3
}

void	sort_stacks(t_stacks *stacks)
{
	t_div_info	info;
	int			total;

	total = ft_lstsize(stacks->a);
	info = get_div_info(total);
	preprocess(stacks, info);
	print_stacks(*stacks);
}
