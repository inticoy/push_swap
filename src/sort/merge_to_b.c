/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:48:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 18:56:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"
#include "push_swap.h"

void	merge_to_b(t_stacks *stacks, t_merge_info minfo)
{
	int	idx;

	if (!minfo.a && !minfo.b && !minfo.c)
		return ;
	if (minfo.order > 0) // is asc->find biggest
	{
		if (minfo.a && !minfo.b && !minfo.c)
			idx = 0;
		else if (!minfo.a && minfo.b && !minfo.c)
			idx = 1;
		else if (!minfo.a && !minfo.b && minfo.c)
			idx = 2;
		else if (minfo.a && minfo.b && !minfo.c)
		{
			if (get_a_bottom(stacks) > get_a_top(stacks))
				idx = 0;
			else
				idx = 1;
		}
		else if (minfo.a && !minfo.b && minfo.c)
		{
			if (get_a_bottom(stacks) > get_b_bottom(stacks))
				idx = 0;
			else
				idx = 2;
		}
		else if (!minfo.a && minfo.b && minfo.c)
		{
			if (get_a_top(stacks) > get_b_bottom(stacks))
				idx = 1;
			else
				idx = 2;
		}
		else
			idx = max_3(get_a_bottom(stacks), get_a_top(stacks), get_b_bottom(stacks));
	}
	else
	{
		if (minfo.a && !minfo.b && !minfo.c)
			idx = 0;
		else if (!minfo.a && minfo.b && !minfo.c)
			idx = 1;
		else if (!minfo.a && !minfo.b && minfo.c)
			idx = 2;
		else if (minfo.a && minfo.b && !minfo.c)
		{
			if (get_a_bottom(stacks) < get_a_top(stacks))
				idx = 0;
			else
				idx = 1;
		}
		else if (minfo.a && !minfo.b && minfo.c)
		{
			if (get_a_bottom(stacks) < get_b_bottom(stacks))
				idx = 0;
			else
				idx = 2;
		}
		else if (!minfo.a && minfo.b && minfo.c)
		{
			if (get_a_top(stacks) < get_b_bottom(stacks))
				idx = 1;
			else
				idx = 2;
		}
		else
			idx = min_3(get_a_bottom(stacks), get_a_top(stacks), get_b_bottom(stacks));
	}
	if (idx == 0)
	{
		rev_rotate_a(stacks, ft_true);
		push_b(stacks, ft_true);
		minfo.a--;
	}
	else if (idx == 1)
	{
		push_b(stacks, ft_true);
		minfo.b--;
	}
	else if (idx == 2)
	{
		rev_rotate_b(stacks, ft_true);
		minfo.c--;
	}
	merge_to_b(stacks, minfo);
}
