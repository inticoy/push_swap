/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 19:46:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 19:51:16 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_4(t_stacks *stacks, t_order order)
{
	t_merge_info	minfo;

	minfo.a = 0;
	minfo.b = 2;
	minfo.c = 2;
	minfo.order = asc;
	repeat_cmd(push_b, stacks, ft_true, 2);
	sort_2(stacks, asc);
	sort_2(stacks, asc);
	merge_to_a(stacks, minfo);
}
