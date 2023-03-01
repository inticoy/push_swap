/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_order.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 14:16:22 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 14:07:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libmath.h"
#include "push_swap.h"

t_order	*set_order(int part, int level)
{
	t_order	*order;
	int		i;
	int		j;

	order = (t_order *)ft_calloc(part, sizeof(t_order));
	if (!order)
		return (FT_NULL);
	order[0] = asc;
	i = 0;
	while (i < level)
	{
		j = 0;
		while (j < power(3, i))
		{
			order[(power(3, i) * 2 - 1) - j] = -order[j];
			order[(power(3, i) * 3 - 1) - j] = -order[j];
			j++;
		}
		i++;
	}
	return (order);
}
