/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 19:19:02 by gyoon             #+#    #+#             */
/*   Updated: 2023/03/02 19:22:39 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_bool	is_sorted(t_stacks *stacks)
{
	t_list	*node;
	int		curr;
	int		next;

	node = stacks->a;
	while (node->next)
	{
		curr = *(int *)node->content;
		next = *(int *)node->next->content;
		if (curr > next)
			return (ft_false);
		node = node->next;
	}
	return (ft_true);
}
