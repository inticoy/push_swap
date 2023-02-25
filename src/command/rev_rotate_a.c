/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:17:41 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/25 18:52:50 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rev_rotate_a(t_stacks *stacks)
{
	t_list	*temp;
	t_list	*node;

	if (!stacks->a || !stacks->a->next)
		return ;
	node = stacks->a;
	while (node->next->next)
		node = node->next;
	temp = node->next;
	node->next = FT_NULL;
	ft_lstadd_front(&stacks->a, temp);
	ft_printf("rra\n");
}
