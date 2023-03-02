/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_all_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:48:00 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 18:55:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	merge_all_to_b(t_stacks *stacks, t_div_info info)
{
	t_merge_info	minfo;
	int				pb;
	int				i;

	pb = arr_sum(info.elements + (info.part / 3) * 2, info.part / 3);
	repeat_cmd(push_b, stacks, ft_true, pb);
	i = 0;
	while (i < info.part / 3)
	{
		minfo.a = info.elements[i];
		minfo.b = info.elements[(info.part / 3) * 2 - 1 - i];
		minfo.c = info.elements[info.part - 1 - i];
		minfo.order = info.orders[i];
		merge_to_b(stacks, minfo);
		i++;
	}
}
