/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:54:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 19:44:04 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	sort_stacks(t_stacks *stacks)
{
	t_div_info	info;
	int			i;
	int			num_conquer;

	if (stacks->num == 2)
	{
		sort_2(stacks, asc);
		return ;
	}
	if (stacks->num == 3)
	{
		sort_3(stacks, asc);
		return ;
	}
	info = get_div_info(ft_lstsize(stacks->a));
	i = 0;
	num_conquer = info.level;
	if (info.level % 2 == 0)
		reverse_orders(info.orders, info.part);
	preprocess(stacks, info);
	while (i < num_conquer)
	{
		if (i % 2 == 0)
			merge_all_to_a(stacks, info);
		else
			merge_all_to_b(stacks, info);
		info = update_div_info(info);
		i++;
	}
	if (num_conquer % 2 == 0)
		repeat_cmd(push_a, stacks, ft_true, stacks->num);
}
