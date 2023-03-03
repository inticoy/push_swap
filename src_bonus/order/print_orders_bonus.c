/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_orders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:18:03 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/03 15:08:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	print_orders(t_order *orders, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("%d", orders[i]);
		i++;
	}
	ft_printf("\n");
}
