/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:45:26 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 13:45:51 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_stacks *stacks, t_bool opt)
{
	swap_a(stacks, ft_false);
	swap_b(stacks, ft_false);
	if (opt)
		ft_printf("ss\n");
}
