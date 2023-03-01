/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocess.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:33:00 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 13:33:33 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	preprocess(t_stacks *stacks, t_div_info info)
{
	int	i;

	i = 0;
	while (i < info.part)
	{
		if (info.elements[i] == 2)
			pre_sort2(stacks, info.orders[i]);
		else if (info.elements[i] == 3)
			pre_sort3(stacks, info.orders[i]);
		else if (info.elements[i] == 4)
			pre_sort4(stacks, info.orders[i]);
		i++;
	}
}
