/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_div_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:11:16 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/25 19:10:43 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmath.h"
#include "push_swap.h"

t_div_info	get_div_info(int size)
{
	t_div_info	info;
	int			q;
	int			r;
	int			i;

	info.level = 1;
	info.part = 3;
	while (size / info.part >= 6)
	{
		info.level++;
		info.part *= 3;
	}
	q = size / info.part;
	r = size % info.part;
	info.elements = (int *)ft_calloc(info.part, sizeof(int));
	i = 0;
	while (i < info.part - r)
		info.elements[i++] = q;
	while (i < info.part)
		info.elements[i++] = q + 1;
	info.orders = set_orders(info.part, info.level);
	return (info);
}
