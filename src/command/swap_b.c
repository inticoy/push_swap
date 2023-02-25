/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:45:26 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/25 18:53:40 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_b(t_stacks *stacks)
{
	t_list	*temp;

	if (!stacks->b || !stacks->b->next)
		return ;
	temp = stacks->b->next->next;
	stacks->b->next->next = stacks->b;
	stacks->b = stacks->b->next;
	stacks->b->next->next = temp;
	ft_printf("sb\n");
}
