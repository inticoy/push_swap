/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:54:29 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/22 22:07:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_order	*set_t_order(int part, int level)
{
	t_order	*order;
	int		i;
	int		j;

	order = ft_calloc(part + 1, sizeof(char));
	i = 0;
	order[0] = asc;
	while (i < level)
	{
		j = ;
		while (j < part / 3)
		{

		}
		i++;
	}
	return (order);
}

t_divide_info	get_section(int size)
{
	t_divide_info	info;
	int				i;
	int				q;
	int				r;

	info.level = 1;
	info.part = 3;
	while (size / info.part >= 6)
	{
		info.level++;
		info.part *= 3;
	}
	q = size / info.part;
	r = size % info.part;
	info.arr = (int *)ft_calloc(info.part, sizeof(int *));
	i = 0;
	while (i < info.part - r)
		info.arr[i++] = q;
	while (i < info.part)
		info.arr[i++] = q + 1;
	info.order = set_t_order(info.part, info.level);
	return (info);
}

void	sort_stacks(t_stacks stacks)
{
	t_divide_info	info;
	int				total;

	total = ft_lstsize(stacks.a);
	info = get_section(total);

}
