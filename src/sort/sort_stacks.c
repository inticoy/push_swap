/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:54:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 15:33:24 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libmath.h"
#include "push_swap.h"

static int	arr_sum(int *elements, int len)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (i < len)
	{
		sum += elements[i];
		i++;
	}
	return (sum);
}

static void	merge_to_aa(t_stacks *stacks, t_merge_info minfo)
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
			if (get_b_bottom(stacks) > get_b_top(stacks))
				idx = 0;
			else
				idx = 1;
		}
		else if (minfo.a && !minfo.b && minfo.c)
		{
			if (get_b_bottom(stacks) > get_a_bottom(stacks))
				idx = 0;
			else
				idx = 2;
		}
		else if (!minfo.a && minfo.b && minfo.c)
		{
			if (get_b_top(stacks) > get_a_bottom(stacks))
				idx = 1;
			else
				idx = 2;
		}
		else
			idx = max_3(get_b_bottom(stacks), get_b_top(stacks), get_a_bottom(stacks));
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
			if (get_b_bottom(stacks) < get_b_top(stacks))
				idx = 0;
			else
				idx = 1;
		}
		else if (minfo.a && !minfo.b && minfo.c)
		{
			if (get_b_bottom(stacks) < get_a_bottom(stacks))
				idx = 0;
			else
				idx = 2;
		}
		else if (!minfo.a && minfo.b && minfo.c)
		{
			if (get_b_top(stacks) < get_a_bottom(stacks))
				idx = 1;
			else
				idx = 2;
		}
		else
			idx = min_3(get_b_bottom(stacks), get_b_top(stacks), get_a_bottom(stacks));
	}
	if (idx == 0)
	{
		rev_rotate_b(stacks, ft_true);
		push_a(stacks, ft_true);
		minfo.a--;
	}
	else if (idx == 1)
	{
		push_a(stacks, ft_true);
		minfo.b--;
	}
	else if (idx == 2)
	{
		rev_rotate_a(stacks, ft_true);
		minfo.c--;
	}
	merge_to_aa(stacks, minfo);
}

static void	merge_to_a(t_stacks *stacks, t_div_info info)
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
		merge_to_aa(stacks, minfo);
		i++;
	}
}

static void	merge_to_bb(t_stacks *stacks, t_merge_info minfo)
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
	merge_to_bb(stacks, minfo);
}

static void	merge_to_b(t_stacks *stacks, t_div_info info)
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
		merge_to_bb(stacks, minfo);
		i++;
	}
}

void	sort_stacks(t_stacks *stacks)
{
	t_div_info	info;
	int			i;
	int			num_conquer;

	info = get_div_info(ft_lstsize(stacks->a));
	i = -1;
	num_conquer = info.level;
	if (info.level % 2 == 0)
		reverse_orders(info.orders, info.part);
	preprocess(stacks, info);
	while (++i < num_conquer)
	{
		if (i % 2 == 0)
			merge_to_a(stacks, info);
		else
			merge_to_b(stacks, info);
		info = update_div_info(info);
	}
	if (num_conquer % 2 == 0)
		repeat_cmd(push_a, stacks, ft_true, stacks->num);
}
