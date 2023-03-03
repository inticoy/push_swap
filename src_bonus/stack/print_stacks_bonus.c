/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:40:16 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/03 15:10:24 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap_bonus.h"

void	print_stacks(t_stacks stacks)
{
	ft_printf("[stack A] : ");
	while (stacks.a)
	{
		ft_printf("%d ", *(int *)stacks.a->content);
		stacks.a = stacks.a->next;
	}
	ft_printf("\n");
	ft_printf("[stack B] : ");
	while (stacks.b)
	{
		ft_printf("%d ", *(int *)stacks.b->content);
		stacks.b = stacks.b->next;
	}
	ft_printf("\n");
}
