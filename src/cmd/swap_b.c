/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:45:26 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 13:44:38 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stacks *stacks, t_bool opt)
{
	t_list	*temp;

	if (!stacks->b || !stacks->b->next)
		return ;
	temp = stacks->b->next->next;
	stacks->b->next->next = stacks->b;
	stacks->b = stacks->b->next;
	stacks->b->next->next = temp;
	if (opt)
		ft_printf("sb\n");
}
