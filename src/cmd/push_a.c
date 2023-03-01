/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:14:30 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 21:26:10 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	push_a(t_stacks *stacks, t_bool opt)
{
	t_list	*temp;

	if (!stacks->b)
		return ;
	temp = stacks->b->next;
	ft_lstadd_front(&stacks->a, stacks->b);
	stacks->b = temp;
	if (opt)
		ft_printf("pa\n");
}
