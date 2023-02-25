/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:56:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/25 18:53:26 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	rotate_b(t_stacks *stacks)
{
	t_list	*temp;

	if (!stacks->b || !stacks->b->next)
		return ;
	temp = stacks->b;
	stacks->b = stacks->b->next;
	temp->next = FT_NULL;
	ft_lstadd_back(&stacks->b, temp);
	ft_printf("rb\n");
}
