/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_all_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:50:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 18:55:34 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	merge_all_to_a(t_stacks *stacks, t_div_info info)
{
	t_merge_info	minfo;
	int				pa;
	int				i;

	pa = arr_sum(info.elements + (info.part / 3) * 2, info.part / 3);
	repeat_cmd(push_a, stacks, ft_true, pa);
	i = 0;
	while (i < info.part / 3)
	{
		minfo.a = info.elements[i];
		minfo.b = info.elements[(info.part / 3) * 2 - 1 - i];
		minfo.c = info.elements[info.part - 1 - i];
		minfo.order = info.orders[i];
		merge_to_a(stacks, minfo);
		i++;
	}
}
