/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:56:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/03 14:49:22 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_bonus.h"

void	rotate_a(t_stacks *stacks, t_bool opt)
{
	t_list	*temp;

	if (!stacks->a || !stacks->a->next)
		return ;
	temp = stacks->a;
	stacks->a = stacks->a->next;
	temp->next = FT_NULL;
	ft_lstadd_back(&stacks->a, temp);
	if (opt)
		ft_printf("ra\n");
}
