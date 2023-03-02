/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:54:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/02 19:23:15 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static void	sort_2345(t_stacks *stacks)
{
	if (stacks->num == 2)
		sort_2(stacks, asc);
	else if (stacks->num == 3)
		sort_3(stacks, asc);
	else if (stacks->num == 4)
		sort_4(stacks, asc);
	else if (stacks->num == 5)
		sort_5(stacks, asc);
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
	preprocess(stacks, *dinfo);
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
