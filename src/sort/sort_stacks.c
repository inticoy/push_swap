/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:54:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/25 18:37:33 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libmath.h"
#include "push_swap.h"

static void	pre_sort(t_stacks *stacks, t_order order)
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

static void	preprocess(t_stacks *stacks, t_div_info info)
{
	int	i;

	i = 0;
	while (i < info.part)
	{
		pre_sort(stacks, info.orders[i]);
		i++;
	}
}

static int	arr_sum(char *elements, int len)
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

void	sort_stacks(t_stacks *stacks)
{
	t_div_info	info;
	int			total;

	total = ft_lstsize(stacks->a);
	info = get_div_info(total);
	preprocess(stacks, info);

	ft_printf("\nAFTER PREPROCESSING\n");
	print_stacks(*stacks);

	merge_to_a(stacks, info);

	ft_printf("\nAFTER MERGE\n");
	print_stacks(*stacks);
	print_orders(info.orders, info.part);
}
