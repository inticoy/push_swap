/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyoon <gyoon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 16:20:14 by gyoon             #+#    #+#             */
/*   Updated: 2023/02/19 16:22:39 by gyoon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

t_stack_data	*new_stack_data(void)
{
	t_stack_data	*stack_data;

	stack_data = ft_calloc(1, sizeof(t_stack_data));
	stack_data->number = 0;
	return (stack_data);
}
