/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:56:19 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/01 13:44:07 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

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
