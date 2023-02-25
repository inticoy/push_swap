/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:54:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/25 21:56:36 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libmath.h"
#include "push_swap.h"

static int	min_3(int a, int b, int c);
static int	max_3(int a, int b, int c);

static void	pre_sort2(t_stacks *stacks, t_order order)
{
	int	x;
	int	y;

	x = *((int *)stacks->a->content);
	y = *((int *)stacks->a->next->content);
	if (order)
	{
		if (x > y)
		{
			push_b(stacks);
			push_b(stacks);
		}
		else
		{
			swap_a(stacks);
			push_b(stacks);
			push_b(stacks);
		}
	}
	else
	{
		if (x > y)
		{
			swap_a(stacks);
			push_b(stacks);
			push_b(stacks);
		}
		else
		{
			push_b(stacks);
			push_b(stacks);
		}
	}
}

static void	pre_sort3(t_stacks *stacks, t_order order)
{
	t_merge_info 	minfo;
	int				idx;

	rotate_a(stacks);
	push_b(stacks);
	rotate_b(stacks);
	minfo.a = 1;
	minfo.b = 1;
	minfo.c = 1;
	minfo.order = order;
	if (minfo.order) // is asc->find biggest
	{
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

static void	pre_sort4(t_stacks *stacks, t_order order)
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

static void	preprocess(t_stacks *stacks, t_div_info info)
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

static int	max_3(int a, int b, int c)
{
	if (a > b)
	{
		if (a > c)
			return (0);
		else
			return (2);
	}
	else
		return (1 + max_i(b, c));
}

static int	min_3(int a, int b, int c)
{
	if (a < b)
	{
		if (a < c)
			return (0);
		else
			return (2);
	}
	else
		return (1 + min_i(b, c));
}

static void	merge_to_a(t_stacks *stacks, t_div_info info)
{
	int	pa;
	int	i;

	pa = arr_sum(info.elements + (info.part / 3) * 2, info.part / 3);
	i = 0;
	while (i < pa)
	{
		push_a(stacks);
		i++;
	}
	i = 0;
	while (i < info.part / 3)
	{
		t_merge_info	minfo;
		int				idx;

		minfo.a = info.elements[i];
		minfo.b = info.elements[(info.part / 3) * 2 - 1 - i];
		minfo.c = info.elements[info.part - 1 - i];
		minfo.order = info.orders[i];

		if (minfo.order) // is asc->find biggest
		{
			while (minfo.a || minfo.b || minfo.c)
			{
				if (!minfo.a)
				{
					if (!minfo.b)
						idx = 2;
					else
						idx = max_i(get_b_top(stacks), get_a_bottom(stacks)) + 1;
				}
				else
				{
					if (!minfo.b && !minfo.c)
						idx = 0;
					else if (!minfo.b)
						idx = max_i(get_b_bottom(stacks), get_a_bottom(stacks));
					else if (!minfo.c)
						idx = max_i(get_b_bottom(stacks), get_b_top(stacks));
					else
						idx = max_3(get_b_bottom(stacks), get_b_top(stacks), get_a_bottom(stacks));
				}
				if (idx == 0)
				{
					rev_rotate_b(stacks);
					push_a(stacks);
					minfo.a--;
				}
				else if (idx == 1)
				{
					push_a(stacks);
					minfo.b--;
				}
				else if (idx == 2)
				{
					rev_rotate_a(stacks);
					minfo.c--;
				}
			}
		}
		else
		{
			while (minfo.a || minfo.b || minfo.c)
			{
				if (!minfo.a)
				{
					if (!minfo.b)
						idx = 2;
					else
						idx = min_i(get_b_top(stacks), get_a_bottom(stacks)) + 1;
				}
				else
				{
					if (!minfo.b && !minfo.c)
						idx = 0;
					else if (!minfo.b)
						idx = min_i(get_b_bottom(stacks), get_a_bottom(stacks));
					else if (!minfo.c)
						idx = min_i(get_b_bottom(stacks), get_b_top(stacks));
					else
						idx = min_3(get_b_bottom(stacks), get_b_top(stacks), get_a_bottom(stacks));
				}
				if (idx == 0)
				{
					rev_rotate_b(stacks);
					push_a(stacks);
					minfo.a--;
				}
				else if (idx == 1)
				{
					push_a(stacks);
					minfo.b--;
				}
				else if (idx == 2)
				{
					rev_rotate_a(stacks);
					minfo.c--;
				}
			}
		}
		i++;
	}
}

static void	merge_to_b(t_stacks *stacks, t_div_info info)
{
	int	pb;
	int	i;

	pb = arr_sum(info.elements + (info.part / 3) * 2, info.part / 3);
	i = 0;
	while (i < pb)
	{
		push_b(stacks);
		i++;
	}
	i = 0;
	while (i < info.part / 3)
	{
		t_merge_info	minfo;
		int				idx;

		minfo.a = info.elements[i];
		minfo.b = info.elements[(info.part / 3) * 2 - 1 - i];
		minfo.c = info.elements[info.part - 1 - i];
		minfo.order = info.orders[i];

		if (minfo.order) // is asc->find biggest
		{
			while (minfo.a || minfo.b || minfo.c)
			{
				if (!minfo.a)
				{
					if (!minfo.b)
						idx = 2;
					else
						idx = max_i(get_a_top(stacks), get_b_bottom(stacks)) + 1;
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
			while (minfo.a || minfo.b || minfo.c)
			{
				if (!minfo.a)
				{
					if (!minfo.b)
						idx = 2;
					else
						idx = min_i(get_a_top(stacks), get_b_bottom(stacks)) + 1;
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
	{
		i = -1;
		while (++i < stacks->num)
			push_a(stacks);
	}
}
