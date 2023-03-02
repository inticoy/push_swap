/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:33:00 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/02 22:38:59 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_sort(t_stacks *stacks, t_div_info info)
{
	int	i;

	i = 0;
	while (i < info.part)
	{
		if (info.elements[i] == 2)
			pre_sort_two_nodes(stacks, info.orders[i]);
		else if (info.elements[i] == 3)
			pre_sort_three_nodes(stacks, info.orders[i]);
		else if (info.elements[i] == 4)
			pre_sort_four_nodes(stacks, info.orders[i]);
		else if (info.elements[i] == 5)
			pre_sort_five_nodes(stacks, info.orders[i]);
		else if (info.elements[i] == 6)
			pre_sort_six_nodes(stacks, info.orders[i]);
		i++;
	}
}
