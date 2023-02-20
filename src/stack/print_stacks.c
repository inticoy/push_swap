/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 13:40:16 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/20 13:43:48 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

void	print_stacks(t_stacks stacks)
{
	ft_printf("[stack A] : ");
	while (stacks.a)
	{
		ft_printf("%d ", ((t_stack_data *)(stacks.a->content))->number);
		stacks.a = stacks.a->next;
	}
	ft_printf("\n");
	ft_printf("[stack B] : ");
	while (stacks.b)
	{
		ft_printf("%d ", ((t_stack_data *)(stacks.b->content))->number);
		stacks.b = stacks.b->next;
	}
	ft_printf("\n");
}
