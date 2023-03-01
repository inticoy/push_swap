/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:45:26 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 13:44:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *stacks, t_bool opt)
{
	t_list	*temp;

	if (!stacks->a || !stacks->a->next)
		return ;
	temp = stacks->a->next->next;
	stacks->a->next->next = stacks->a;
	stacks->a = stacks->a->next;
	stacks->a->next->next = temp;
	if (opt)
		ft_printf("sa\n");
}
