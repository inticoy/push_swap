/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_stack_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:10:10 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/19 19:13:03 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_list	*set_stack_b(int size)
{
	t_list	*head;
	t_list	*node;
	int		i;

	head = 0;
	i = 0;
	while (i < size)
	{
		node = ft_lstnew(new_stack_data());
		ft_lstadd_back(&head, node);
		i++;
	}
	return (head);
}