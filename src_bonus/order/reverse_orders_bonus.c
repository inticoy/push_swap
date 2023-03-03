/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_orders_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:21:32 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/03 15:09:01 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	reverse_orders(t_order *orders, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		orders[i] = -orders[i];
		i++;
	}
}
