/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_orders.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 15:18:03 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/25 15:19:02 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
