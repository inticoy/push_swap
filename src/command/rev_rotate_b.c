/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:17:41 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 13:44:00 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rev_rotate_b(t_stacks *stacks, t_bool opt)
{
	t_list	*temp;
	t_list	*node;

	if (!stacks->b || !stacks->b->next)
		return ;
	node = stacks->b;
	while (node->next->next)
		node = node->next;
	temp = node->next;
	node->next = FT_NULL;
	ft_lstadd_front(&stacks->b, temp);
	if (opt)
		ft_printf("rrb\n");
}
