/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:45:26 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/25 18:53:30 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *stacks)
{
	t_list	*temp;

	if (!stacks->a || !stacks->a->next)
		return ;
	temp = stacks->a->next->next;
	stacks->a->next->next = stacks->a;
	stacks->a = stacks->a->next;
	stacks->a->next->next = temp;
	ft_printf("sa\n");
}
