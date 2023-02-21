/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:54:40 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/21 15:11:44 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

static t_bool	has_duplication(t_list *head)
{
	t_list	*node;
	int		head_num;

	while (head)
	{
		node = head->next;
		head_num = ((t_stack_data *)head->content)->number;
		while (node)
		{
			if (((t_stack_data *)node->content)->number == head_num)
				return (ft_true);
			node = node->next;
		}
		head = head->next;
	}
	return (ft_false);
}

t_stacks	set_stacks(int argc, char **argv)
{
	t_stacks	stacks;

	stacks = init_stacks();
	stacks.a = set_stack_a(argc, argv);
	if (has_duplication(stacks.a))
		ft_lstclear(&stacks.a, ft_free_s);
	return (stacks);
}
