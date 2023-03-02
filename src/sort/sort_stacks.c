/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:54:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/02 22:44:22 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	sort_2345(t_stacks *stacks)
{
	if (stacks->num == 2)
		sort_two_nodes(stacks, asc);
	else if (stacks->num == 3)
		sort_three_nodes(stacks, asc);
	else if (stacks->num == 4)
		sort_four_nodes(stacks, asc);
	else if (stacks->num == 5)
		sort_five_nodes(stacks, asc);
	return ;
}

void	sort_stacks(t_stacks *stacks, t_div_info *dinfo)
{
	int			i;
	int			num_conquer;

	if (is_sorted(stacks))
		return ;
	if (2 <= stacks->num && stacks->num <= 5)
	{
		sort_2345(stacks);
		return ;
	}
	i = -1;
	num_conquer = dinfo->level;
	if (dinfo->level % 2 == 0)
		reverse_orders(dinfo->orders, dinfo->part);
	pre_sort(stacks, *dinfo);
	while (++i < num_conquer)
	{
		if (i % 2 == 0)
			merge_all_to_a(stacks, *dinfo);
		else
			merge_all_to_b(stacks, *dinfo);
		*dinfo = update_div_info(*dinfo);
	}
	if (num_conquer % 2 == 0)
		repeat_cmd(push_a, stacks, ft_true, stacks->num);
}
