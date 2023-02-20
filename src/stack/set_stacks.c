/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:54:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/20 23:32:37 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	set_stacks(int argc, char **argv)
{
	t_stacks	stacks;

	stacks = init_stacks();
	stacks.a = set_stack_a(argc, argv);
	if (!stacks.a)
		return (stacks);
	stacks.b = set_stack_b(ft_lstsize(stacks.a));
	return (stacks);
}
