/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_to_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 18:48:58 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/03 14:55:29 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cmd_merge_to_b(t_stacks *stacks, t_merge_info *minfo, int idx)
{
	if (idx == 0)
	{
		rev_rotate_a(stacks, ft_true);
		push_b(stacks, ft_true);
		minfo->a--;
	}
	else if (idx == 1)
	{
		push_b(stacks, ft_true);
		minfo->b--;
	}
	else if (idx == 2)
	{
		rev_rotate_b(stacks, ft_true);
		minfo->c--;
	}
}

static int	get_index(t_stacks *stacks, t_merge_info minfo)
{
	if (minfo.a && minfo.b && !minfo.c)
	{
		if ((minfo.order > 0 && (get_a_bot(stacks) > get_a_top(stacks))) \
			|| (minfo.order < 0 && (get_a_bot(stacks) < get_a_top(stacks))))
			return (0);
		else
			return (1);
	}
	else if (minfo.a && !minfo.b && minfo.c)
	{
		if ((minfo.order > 0 && (get_a_bot(stacks) > get_b_bot(stacks))) \
			|| (minfo.order < 0 && (get_a_bot(stacks) < get_b_bot(stacks))))
			return (0);
		else
			return (2);
	}
	else if (!minfo.a && minfo.b && minfo.c)
	{
		if ((minfo.order > 0 && (get_a_top(stacks) > get_b_bot(stacks))) \
			|| (minfo.order < 0 && (get_a_top(stacks) < get_b_bot(stacks))))
			return (1);
		else
			return (2);
	}
	return (-1);
}

void	merge_to_b(t_stacks *stacks, t_merge_info minfo)
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
			idx = max_idx_of_three(get_a_bot(stacks), \
									get_a_top(stacks), \
									get_b_bot(stacks));
		else
			idx = min_idx_of_three(get_a_bot(stacks), \
									get_a_top(stacks), \
									get_b_bot(stacks));
	}
	else
		idx = get_index(stacks, minfo);
	cmd_merge_to_b(stacks, &minfo, idx);
	merge_to_b(stacks, minfo);
}
