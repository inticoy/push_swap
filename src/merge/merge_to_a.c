/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:49:53 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/02 15:08:57 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"
#include "push_swap.h"

static void	cmd_merge_to_a(t_stacks *stacks, t_merge_info *minfo, int idx)
{
	if (idx == 0)
	{
		rev_rotate_b(stacks, ft_true);
		push_a(stacks, ft_true);
		minfo->a--;
	}
	else if (idx == 1)
	{
		push_a(stacks, ft_true);
		minfo->b--;
	}
	else if (idx == 2)
	{
		rev_rotate_a(stacks, ft_true);
		minfo->c--;
	}
	else
		return ;
}

static int	get_index(t_stacks *stacks, t_merge_info minfo)
{
	if (minfo.a && minfo.b && !minfo.c)
	{
		if ((minfo.order > 0 && (get_b_bot(stacks) > get_b_top(stacks))) \
			|| (minfo.order < 0 && (get_b_bot(stacks) < get_b_top(stacks))))
			return (0);
		else
			return (1);
	}
	else if (minfo.a && !minfo.b && minfo.c)
	{
		if ((minfo.order > 0 && (get_b_bot(stacks) > get_a_bot(stacks))) \
			|| (minfo.order < 0 && (get_b_bot(stacks) < get_a_bot(stacks))))
			return (0);
		else
			return (2);
	}
	else if (!minfo.a && minfo.b && minfo.c)
	{
		if ((minfo.order > 0 && (get_b_top(stacks) > get_a_bot(stacks))) \
			|| (minfo.order < 0 && (get_b_top(stacks) < get_a_bot(stacks))))
			return (1);
		else
			return (2);
	}
	return (-1);
}

void	merge_to_a(t_stacks *stacks, t_merge_info minfo)
{
	int	idx;

	if (!minfo.a && !minfo.b && !minfo.c)
		return ;
	else if (minfo.a && !minfo.b && !minfo.c)
		idx = 0;
	else if (!minfo.a && minfo.b && !minfo.c)
		idx = 1;
	else if (!minfo.a && !minfo.b && minfo.c)
		idx = 2;
	else if (minfo.a && minfo.b && minfo.c)
	{
		if (minfo.order > 0)
			idx = max_3(get_b_bot(stacks), \
						get_b_top(stacks), \
						get_a_bot(stacks));
		else
			idx = min_3(get_b_bot(stacks), \
						get_b_top(stacks), \
						get_a_bot(stacks));
	}
	else
		idx = get_index(stacks, minfo);
	cmd_merge_to_a(stacks, &minfo, idx);
	merge_to_a(stacks, minfo);
}
