/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:14:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/21 15:44:07 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stacks *stacks)
{
	t_list	*temp;

	if (!stacks->a)
		return ;
	temp = stacks->a->next;
	ft_lstadd_front(&stacks->b, stacks->a);
	stacks->a = temp;
}
