/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 13:32:31 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 13:39:08 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"
#include "push_swap.h"

void	pre_sort_4(t_stacks *stacks, t_order order)
{
	t_merge_info 	minfo;
	int				idx;

	rotate_a(stacks);
	push_b(stacks);
	rotate_b(stacks);
	minfo.a = 1;
	minfo.b = 2;
	minfo.c = 1;
	minfo.order = order;
	if (minfo.order) // is asc->find biggest
	{
		if (*((int *)stacks->a->content) < *((int *)stacks->a->next->content))
			swap_a(stacks);
		while (minfo.a || minfo.b || minfo.c)
		{
			idx = -1;
			if (!minfo.a)
			{
				if (minfo.b && minfo.c)
					idx = max_i(get_a_top(stacks), get_b_bottom(stacks)) + 1;
				else if (!minfo.b)
					idx = 2;
				else if (!minfo.c)
					idx = 1;
			}
			else
			{
				if (!minfo.b && !minfo.c)
					idx = 0;
				else if (!minfo.b) //here is the problem
				{
					if (get_a_bottom(stacks) > get_b_bottom(stacks))
						idx = 0;
					else
						idx = 2;
				}
				else if (!minfo.c)
					idx = max_i(get_a_bottom(stacks), get_a_top(stacks));
				else
					idx = max_3(get_a_bottom(stacks), get_a_top(stacks), get_b_bottom(stacks));
			}
			if (idx == 0)
			{
				rev_rotate_a(stacks);
				push_b(stacks);
				minfo.a--;
			}
			else if (idx == 1)
			{
				push_b(stacks);
				minfo.b--;
			}
			else if (idx == 2)
			{
				rev_rotate_b(stacks);
				minfo.c--;
			}
		}
	}
	else
	{
		if (*((int *)stacks->a->content) > *((int *)stacks->a->next->content))
			swap_a(stacks);
		while (minfo.a || minfo.b || minfo.c)
		{
			if (!minfo.a)
			{
				if (minfo.b && minfo.c)
					idx = min_i(get_a_top(stacks), get_b_bottom(stacks)) + 1;
				else if (!minfo.b)
					idx = 2;
				else if (!minfo.c)
					idx = 1;
			}
			else
			{
				if (!minfo.b && !minfo.c)
					idx = 0;
				else if (!minfo.b) //here is the problem
				{
					if (get_a_bottom(stacks) < get_b_bottom(stacks))
						idx = 0;
					else
						idx = 2;
				}
				else if (!minfo.c)
					idx = min_i(get_a_bottom(stacks), get_a_top(stacks));
				else
					idx = min_3(get_a_bottom(stacks), get_a_top(stacks), get_b_bottom(stacks));
			}
			if (idx == 0)
			{
				rev_rotate_a(stacks);
				push_b(stacks);
				minfo.a--;
			}
			else if (idx == 1)
			{
				push_b(stacks);
				minfo.b--;
			}
			else if (idx == 2)
			{
				rev_rotate_b(stacks);
				minfo.c--;
			}
		}
	}
}
